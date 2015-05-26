//#include <cv.h>
//#include <highgui\highgui.hpp>
//#include <cxcore.h>
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>

#include <iostream>
#include<sstream>
#include<cstring>

using namespace cv;
using namespace std;

IplImage *frame1=0;

//初始化视频写入结构
CvVideoWriter *write1=0;
//初始化视频捕捉器
CvCapture* pCapture=NULL;

int main(int argc,char **argv)
{
	//图像的帧数初始化
	int NumOfFrame=0;
	//注意string对象的初始化，不能用int类型赋值
	string frameName("");

	//open the camera
	if(argc==1)
	{
		VideoCapture cap(0);
		if(!cap.isOpened())
	    {
		    cout<<"Can not open the camera"<<endl;
	    }
	}

	if(argc==1)
	{
		pCapture=cvCaptureFromCAM(0);
	}

	//初始化frame1并保存第一帧
	frame1=cvQueryFrame(pCapture);
	//设定保存视频的文件名解码器等信息
	write1=cvCreateVideoWriter("D:\\TDDOWNLOAD\\opencv\\Video_1\\video_1.avi",-1,15,cvSize(640,480),1);

	while(frame1=cvQueryFrame(pCapture))
	{
		NumOfFrame++;
		//stringstream输入输出流
		stringstream sstr;
		sstr<<"Image_"<<NumOfFrame<<".jpg";
		sstr>>frameName;
		cvSaveImage(frameName.c_str(),frame1);
		//清除标记和内存	
		sstr.clear();
		sstr.str("");

		//将帧写入视频文件
		cvWriteFrame(write1,frame1);
		
		if(cvWaitKey(10)>=0)
		{
			break;
		}
	}

	cvReleaseCapture(&pCapture);
	cvReleaseVideoWriter(&write1);
	cvReleaseImage(&frame1);
	return 0;
}
