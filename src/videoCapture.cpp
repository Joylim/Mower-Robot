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

//��ʼ����Ƶд��ṹ
CvVideoWriter *write1=0;
//��ʼ����Ƶ��׽��
CvCapture* pCapture=NULL;

int main(int argc,char **argv)
{
	//ͼ���֡����ʼ��
	int NumOfFrame=0;
	//ע��string����ĳ�ʼ����������int���͸�ֵ
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

	//��ʼ��frame1�������һ֡
	frame1=cvQueryFrame(pCapture);
	//�趨������Ƶ���ļ�������������Ϣ
	write1=cvCreateVideoWriter("D:\\TDDOWNLOAD\\opencv\\Video_1\\video_1.avi",-1,15,cvSize(640,480),1);

	while(frame1=cvQueryFrame(pCapture))
	{
		NumOfFrame++;
		//stringstream���������
		stringstream sstr;
		sstr<<"Image_"<<NumOfFrame<<".jpg";
		sstr>>frameName;
		cvSaveImage(frameName.c_str(),frame1);
		//�����Ǻ��ڴ�	
		sstr.clear();
		sstr.str("");

		//��֡д����Ƶ�ļ�
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
