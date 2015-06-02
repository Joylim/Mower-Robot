#include <cv.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <cxcore.hpp>
#include <iostream>
#include <string>
#include <fstream>
#include "EdgeDetect.h"
#include <wiringPi.h>
#include <motorControl.h>

using namespace std;
using namespace cv;

#define COUNT_ALL 307200
#define GO_STRAIGHT 0
#define TURN_LEFT 1
#define TURN_BACK -1

int countOfWhite=0;
double grass_rate=0;
int argNum;
/*priImage is the image captured by the camera,gray image is the
gray version of the priImage,canny image is the output of canny
detection**********************************************/
IplImage *priImage=NULL;
IplImage *grayImage=NULL;
IplImage *cannyImage=NULL;
CvMat *priMat=NULL;
CvMat *grayMat=NULL;
CvMat *cannyMat=NULL;

//save the video for future use
CvVideoWriter *write1=0;
//initialize the camera
CvCapture* pCapture=NULL;
Mat cameraFrame;
//initialize the parameters of the detector
EdgeDetect detector(640, 480, 20, 0.4, 0.4);

//open the camera and capture the image
void ImageCapture(int device_index);
void OpenWindow();
void InitializeImage();
bool** Edge_Detect();
//judge whether the mower is on the board
void IsBoarder();
void ShowImage();
void SaveImage(IplImage *priImage,IplImage *grayImage,IplImage *cannyImage,int frameIndex);
void ReleaseALL();

int main(int argc,char *argv[])
{
	argNum=argc;
	int frameIndex=0;
	/*Initialize the camera and capture the image*/
	ImageCapture(0);
	//OpenWindow();
	
	while(priImage=cvQueryFrame(pCapture))
	{
		frameIndex++;
		//cout<<"frameIndex: "<<frameIndex<<endl;
		/*work state and memory initialization*/
		if(frameIndex==1)
		{
			InitializeImage();
		}
		else
		{
			cvCvtColor(priImage,grayImage,CV_RGB2GRAY);
			cvConvert(grayImage,priMat);
			cvConvert(grayImage,grayMat);
			Edge_Detect();
			IsBoarder();
			if(cvWaitKey(500) == 13)
				break;
		}
		SaveImage(priImage,grayImage,cannyImage,frameIndex);
		//cvWriteFrame(write1,priImage);
	}
	ReleaseALL();
	return 0;
}

void ImageCapture(int device_index)
{
	if(argNum==1)
	{
		VideoCapture cap(device_index);
		if(!cap.isOpened())
		{
		cout<<"cannot open the camera"<<endl;
		}
	}
	if(argNum==1)
	{
		pCapture = cvCaptureFromCAM(device_index);
		//cap.read(cameraFrame);
	}
	priImage=cvQueryFrame(pCapture);
	//write1=cvCreateVideoWriter("..\..\img\\video_grass.avi",-1,15,cvSize(640,480),1);
}

/*
void OpenWindow()
{
	cvNamedWindow("priImage",1);
	cvNamedWindow("grayImage",1);
	cvNamedWindow("cannyImage",1);

	cvMoveWindow("priImage",0,0);
	cvMoveWindow("grayImage",300,0);
	//cvMoveWindow("cannyImage",600,0);
}
*/

bool** Edge_Detect()
{
	//cout<<"Edge_Dect(): "<<endl;
	if(grayImage==NULL)
	{
		cerr<<"error initilization."<<endl;
	}
	
	bool** result=NULL;
	Mat a(priMat,true);
	//Mat::Mat(priMat,true);
	

	Mat b(grayMat,true);
	/*Mat::Mat(cannyMat,true);*/

	countOfWhite=0;
	grass_rate=0;
	detector.detect(b,result);
	detector.paint(priImage,result,countOfWhite);
	grass_rate=(countOfWhite+0.0)/COUNT_ALL;
	cout<<"grass_rate "<<grass_rate<<endl;
	 if(grass_rate<0.25)
	 {
		 cout<<"at board."<<endl;
	 }
	cvConvert(cannyMat,cannyImage);

	
	Mat c(priImage,true);
	//ShowImage();
	//cout<<"Edge_Dect finished"<<endl;
	return result;
}

void IsBoarder()
{
	//cout<<"IsBoarder()"<<endl;
	if(grass_rate<0.05)
	{
		TURN_BACK;
		robotLeft(180);
		cout<<"Please go back now!"<<endl;
	}
	if(grass_rate>=0.10&&grass_rate<0.25)
	{
		TURN_LEFT;
		robotLeft(90);
		cout<<"Please turn left!"<<endl;
	}
	if(grass_rate>=0.25)
	{
		robotForward();
		cout<<"Go straight!"<<endl;
	}
}

void ShowImage()
{
	//cvShowImage("priImage",priImage);
	//cvShowImage("grayImage",grayImage);
	//cvShowImage("cannyImage",cannyImage);
}

void InitializeImage()
{
	CvMemStorage *storage=cvCreateMemStorage(0);
	grayImage=cvCreateImage(cvSize(priImage->width,priImage->height),8,1);
	cannyImage=cvCreateImage(cvSize(priImage->width,priImage->height),8,1);

	priMat=cvCreateMat(priImage->height,priImage->width,CV_8U);
	grayMat=cvCreateMat(priImage->height,priImage->width,CV_8U);
	cannyMat=cvCreateMat(priImage->height,priImage->width,CV_8U);

	cvCvtColor(priImage,grayImage,CV_RGB2GRAY);

	cvConvert(grayImage,priMat);
	cvConvert(grayImage,grayMat);
	//cvConvert(grayImage,cannyMat);
}

void SaveImage(IplImage *priImage,IplImage *grayImage,IplImage *cannyImage,int frameIndex)
{
	string priImageName = "";
	string grayImageName = "";
	string cannyImageName = "";
	
	stringstream pri_sstr;
	stringstream gray_sstr;
	stringstream canny_sstr;

	pri_sstr<<"priImage_"<<frameIndex<<".jpg";
	pri_sstr>>priImageName;
	cvSaveImage(priImageName.c_str(),priImage);
	gray_sstr<<"grayImage_"<<frameIndex<<".jpg";
	gray_sstr>>grayImageName;
	cvSaveImage(grayImageName.c_str(),grayImage);
	canny_sstr<<"cannyImage_"<<frameIndex<<".jpg";
	canny_sstr>>cannyImageName;
	cvSaveImage(cannyImageName.c_str(),cannyImage);
	cout<<"This is "<<frameIndex<<" image."<<endl;

	pri_sstr.clear();
	pri_sstr.str("");
	gray_sstr.clear();
	gray_sstr.str("");
	canny_sstr.clear();
	canny_sstr.str("");
}

void ReleaseALL()
{
	cvReleaseImage(&priImage);
	cvReleaseImage(&grayImage);
	cvReleaseImage(&cannyImage);
	cvReleaseMat(&priMat);
	cvReleaseMat(&grayMat);
	cvReleaseMat(&cannyMat);
	cvReleaseCapture(&pCapture);
	cvReleaseVideoWriter(&write1);
}
