//������Ĺ�����ʵ�ֲ�ƺӰ��Ļ�ȡ������ͱ�Եʶ��
//���ڼ�⵽��Եʱ������˷���ָ��;
//������ɶ�����ͷ��ȡ����Ƶ����ʵʱ����Ҳ���Զ�ȡ
//¼����ϵ���Ƶ�ļ������к���
#include <cv.h>
#include <highgui\highgui.hpp>
#include <cxcore.h>
#include <iostream>
#include<sstream>
#include<cstring>
#include"Command.h"

using namespace cv;
using namespace std;

//ͼ��ĳ�ʼ����ԭʼͼ��
IplImage *frame1=0;
//�����Ҷ�ͼ
IplImage *frame2=0;
//ǰ���Ҷ�ͼ
IplImage *frame3=0;
//canny����Ĺ��ͼ
IplImage *frame4=0;

CvMat *mat1=0;
CvMat *mat2=0;
CvMat *mat3=0;
//��ʼ����Ƶд��ṹ
CvVideoWriter *write1=0;

static void helpInfo()
{
	cout<<"This program is aimed to detect the board of the grass."<<endl;
	cout<<"And also keep the mow inside."<<endl;
}

//���廬�����ص�����
void onTrackBar(int a)
{
	cvCanny(frame2,frame4,(double)a,(double)a*3,3);
	cvShowImage("canny",frame4);
}

//�������̣߳�����������˷��Ϳ���ָ��
Command order;

//���̣߳�����ִ�б�Ե���Ͳ�ƺ��Եʶ��,
int main(int argc,char**argv)
{
	//��ʾ������Ϣ
	helpInfo();
	
	//ͼ���֡����ʼ��
	int NumOfFrame=0;
	//ע��sting����ĳ�ʼ����������int���͸�ֵ
	string frameName("");

	//��������
	cvNamedWindow("video",1);
	cvNamedWindow("background",1);
	cvNamedWindow("foreground",1);
	cvNamedWindow("canny",1);

	//ʹ������������
	cvMoveWindow("video",30,0);
	cvMoveWindow("background",300,0);
	cvMoveWindow("foreground",570,0);
	cvMoveWindow("canny",840,0);

	//������ͷ
	if(argc==1)
	{
		VideoCapture cap(0);
		if(!cap.isOpened())
	    {
		    cout<<"Can not open the camera"<<endl;
	    }
	}
	//��ȡ��Ƶ�ļ�
	if(argc==2)
	{
		CvCapture* pCapture=cvCaptureFromAVI("D:\\TDDOWNLOAD\\opencv\\Video_1\\video_2.avi");
	}

	//��֡��ȡ��Ƶ�����浽����Ŀ¼��
	CvCapture* pCapture=cvCaptureFromCAM(0);
	//��ʼ��frame1�������һ֡
	frame1=cvQueryFrame(pCapture);
	//�趨������Ƶ���ļ�������������Ϣ
	write1=cvCreateVideoWriter("D:\\TDDOWNLOAD\\opencv\\Video_1\\video_1.avi",-1,15,cvSize(640,480),1);
	
	//cvQueryFrame��������ͷ��ץȡ������һ֡
	while(frame1=cvQueryFrame(pCapture))
	{
		NumOfFrame++;
		
		//��һ��ͼ����Ҫ��ʼ���������ڴ�
		if(NumOfFrame==1)
		{
			frame2=cvCreateImage(cvSize(frame1->width,frame1->height),8,1);
			frame3=cvCreateImage(cvSize(frame1->width,frame1->height),8,1);
			frame4=cvCreateImage(cvSize(frame1->width,frame1->height),8,1);

			mat2=cvCreateMat(frame1->height,frame1->width,CV_32FC1);
			mat3=cvCreateMat(frame1->height,frame1->width,CV_32FC1);
			mat1=cvCreateMat(frame1->height,frame1->width,CV_32FC1);

			//ת��Ϊ��ͨ��ͼ����д���
			cvCvtColor(frame1,frame2,CV_RGB2GRAY);
			cvCvtColor(frame1,frame3,CV_RGB2GRAY);

			cvConvert(frame2,mat1);
			cvConvert(frame2,mat2);
			cvConvert(frame2,mat3);
		}
		else
		{
			cvCvtColor(frame1,frame2,CV_RGB2GRAY);
			cvConvert(frame2,mat1);
			//��˹ƽ���˲���
			cvSmooth(mat1,mat1,CV_BLUR,4,0,0,0);
			//��ǰ֡�뱳��ͼ���
			cvAbsDiff(mat1,mat2,mat3);
			//��ֵ��ǰ��ͼ
			cvThreshold(mat3,frame3,60,255.0,CV_THRESH_BINARY);
			//�˲�ȥ����
			cvErode(frame3,frame3,0,1);
			//���������ƶ�ƽ������
			/*cvRunningAvg(mat1,mat2,0.003,0);*/
			//תΪͼ���ʽ
			cvConvert(mat1,frame2);
			//����������
			int edge_thresh=50;
			int new_edge_thresh=edge_thresh;
			
			if(NumOfFrame==2)
			{
				cvCreateTrackbar("canny_threshold","canny",&edge_thresh,100,onTrackBar);
			    //ʹ��canny�㷨����Ե��������
			   onTrackBar(100);
			}
			else
			{
				//��ȡ����ĵ�ǰλ���Ա���������
				new_edge_thresh=cvGetTrackbarPos("canny_threshold","canny");
				cvCreateTrackbar("canny_threshold","canny",&new_edge_thresh,100,onTrackBar);
			    onTrackBar(100*new_edge_thresh/edge_thresh);
				 new_edge_thresh=cvGetTrackbarPos("canny_threshold","canny");
			}
		    
			//ͳ��canny��Ե��������canny��Ե���ǧ�ֱȷ�ӳ��ƺ�������
			int count_WhitePoint=0;
			double grass_rate=0;
			//�趨��ƺ������ʵ���ֵ
			double thresholdRate=30;
			
			if(frame4!=0)
			{
				for(int i=0;i<frame4->height;i++)
				{
					for(int j=0;j<frame4->width;j++)
					{
						double pixelValue=cvGetReal2D(frame4,i,j);
						if(pixelValue!=0)
						{
							count_WhitePoint++;
						}
					}
				}
			}
			grass_rate=1000*count_WhitePoint/((frame4->height)*(frame4->width));
			//���canny��Ե����ʲ����浽ָ���ļ�
			cout<<"Rate of canny points: "<<grass_rate<<" And number: "<<count_WhitePoint<<endl;
			
			//grass_rate��Ԥ����ֵ�Ƚϣ��жϻ������Ƿ񵽴�߽粢�л��߳�
			if(grass_rate>=thresholdRate)
			{
				cout<<"You are on the boarder,sir."<<endl;
				order.start("Turn left and get way from the boarder.");
				order.sleep(100);
				order.wait();
			}

			//��ʾ�����ͼ��
			cvShowImage("video",frame1);
			cvShowImage("background",frame2);
			cvShowImage("foreground",frame3);
			//ͼ��ˢ��Ƶ�ʵ���
			cvWaitKey(20);
			//����Enter����Ӧ���˳���Ƶ¼��
			if(cvWaitKey(20) == 13)
				break;
		}
		
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
	}

	//���ٴ���
	cvDestroyWindow("video");
	cvDestroyWindow("background");
	cvDestroyWindow("foreground");
	cvDestroyWindow("canny");

	cvReleaseMat(&mat1);
	cvReleaseMat(&mat2);
	cvReleaseMat(&mat3);
	cvReleaseImage(&frame4);

	cvReleaseCapture(&pCapture);
	cvReleaseVideoWriter(&write1);
	return 0;
}