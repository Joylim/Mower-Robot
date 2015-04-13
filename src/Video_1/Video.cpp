//本程序的功能是实现草坪影像的获取、处理和边缘识别，
//并在检测到边缘时向机器人发送指令;
//本程序可对摄像头获取的视频进行实时处理，也可以读取
//录制完毕的视频文件，进行后处理
#include <cv.h>
#include <highgui\highgui.hpp>
#include <cxcore.h>
#include <iostream>
#include<sstream>
#include<cstring>
#include"Command.h"

using namespace cv;
using namespace std;

//图像的初始化，原始图像
IplImage *frame1=0;
//背景灰度图
IplImage *frame2=0;
//前景灰度图
IplImage *frame3=0;
//canny检测后的光点图
IplImage *frame4=0;

CvMat *mat1=0;
CvMat *mat2=0;
CvMat *mat3=0;
//初始化视频写入结构
CvVideoWriter *write1=0;

static void helpInfo()
{
	cout<<"This program is aimed to detect the board of the grass."<<endl;
	cout<<"And also keep the mow inside."<<endl;
}

//定义滑动条回调函数
void onTrackBar(int a)
{
	cvCanny(frame2,frame4,(double)a,(double)a*3,3);
	cvShowImage("canny",frame4);
}

//定义子线程，用于向机器人发送控制指令
Command order;

//主线程，用于执行边缘检测和草坪边缘识别,
int main(int argc,char**argv)
{
	//显示帮助信息
	helpInfo();
	
	//图像的帧数初始化
	int NumOfFrame=0;
	//注意sting对象的初始化，不能用int类型赋值
	string frameName("");

	//创建窗口
	cvNamedWindow("video",1);
	cvNamedWindow("background",1);
	cvNamedWindow("foreground",1);
	cvNamedWindow("canny",1);

	//使窗口有序排列
	cvMoveWindow("video",30,0);
	cvMoveWindow("background",300,0);
	cvMoveWindow("foreground",570,0);
	cvMoveWindow("canny",840,0);

	//打开摄像头
	if(argc==1)
	{
		VideoCapture cap(0);
		if(!cap.isOpened())
	    {
		    cout<<"Can not open the camera"<<endl;
	    }
	}
	//读取视频文件
	if(argc==2)
	{
		CvCapture* pCapture=cvCaptureFromAVI("D:\\TDDOWNLOAD\\opencv\\Video_1\\video_2.avi");
	}

	//逐帧读取视频并保存到工程目录下
	CvCapture* pCapture=cvCaptureFromCAM(0);
	//初始化frame1并保存第一帧
	frame1=cvQueryFrame(pCapture);
	//设定保存视频的文件名解码器等信息
	write1=cvCreateVideoWriter("D:\\TDDOWNLOAD\\opencv\\Video_1\\video_1.avi",-1,15,cvSize(640,480),1);
	
	//cvQueryFrame，从摄像头中抓取并返回一帧
	while(frame1=cvQueryFrame(pCapture))
	{
		NumOfFrame++;
		
		//第一张图像需要初始化并申请内存
		if(NumOfFrame==1)
		{
			frame2=cvCreateImage(cvSize(frame1->width,frame1->height),8,1);
			frame3=cvCreateImage(cvSize(frame1->width,frame1->height),8,1);
			frame4=cvCreateImage(cvSize(frame1->width,frame1->height),8,1);

			mat2=cvCreateMat(frame1->height,frame1->width,CV_32FC1);
			mat3=cvCreateMat(frame1->height,frame1->width,CV_32FC1);
			mat1=cvCreateMat(frame1->height,frame1->width,CV_32FC1);

			//转化为单通道图像进行处理
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
			//高斯平滑滤波器
			cvSmooth(mat1,mat1,CV_BLUR,4,0,0,0);
			//当前帧与背景图相减
			cvAbsDiff(mat1,mat2,mat3);
			//二值化前景图
			cvThreshold(mat3,frame3,60,255.0,CV_THRESH_BINARY);
			//滤波去噪音
			cvErode(frame3,frame3,0,1);
			//背景更新移动平均？？
			/*cvRunningAvg(mat1,mat2,0.003,0);*/
			//转为图像格式
			cvConvert(mat1,frame2);
			//创建滑动条
			int edge_thresh=50;
			int new_edge_thresh=edge_thresh;
			
			if(NumOfFrame==2)
			{
				cvCreateTrackbar("canny_threshold","canny",&edge_thresh,100,onTrackBar);
			    //使用canny算法检测边缘并输出结果
			   onTrackBar(100);
			}
			else
			{
				//获取滑块的当前位置以便连续调整
				new_edge_thresh=cvGetTrackbarPos("canny_threshold","canny");
				cvCreateTrackbar("canny_threshold","canny",&new_edge_thresh,100,onTrackBar);
			    onTrackBar(100*new_edge_thresh/edge_thresh);
				 new_edge_thresh=cvGetTrackbarPos("canny_threshold","canny");
			}
		    
			//统计canny边缘点数量，canny边缘点的千分比反映草坪面积比率
			int count_WhitePoint=0;
			double grass_rate=0;
			//设定草坪面积比率的阈值
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
			//输出canny边缘点比率并保存到指定文件
			cout<<"Rate of canny points: "<<grass_rate<<" And number: "<<count_WhitePoint<<endl;
			
			//grass_rate与预设阈值比较，判断机器人是否到达边界并切换线程
			if(grass_rate>=thresholdRate)
			{
				cout<<"You are on the boarder,sir."<<endl;
				order.start("Turn left and get way from the boarder.");
				order.sleep(100);
				order.wait();
			}

			//显示其余的图像
			cvShowImage("video",frame1);
			cvShowImage("background",frame2);
			cvShowImage("foreground",frame3);
			//图像刷新频率调整
			cvWaitKey(20);
			//键盘Enter键响应，退出视频录制
			if(cvWaitKey(20) == 13)
				break;
		}
		
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
	}

	//销毁窗口
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