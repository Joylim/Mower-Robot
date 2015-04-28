//#include <stdafx.h>
#include <iostream>
#include <string>
#include <opencv2/opencv.hpp>
#include "opencv2/video/tracking.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
using namespace std;
using namespace cv;
int gridX = 20;
int f[24][32];
bool v[24][32];
int rgb[30][30][30];
int rgb1[30][30][30];
int N = 24;
int M = 32;
int s, t;
pair<int, int> q[1000];
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};
int mm;
bool inside(int x, int y) {
	if (x < 0) return false;
	if (y < 0) return false;
	if (x > 23) return false;
	if (y > 31) return false;
	return true;
}
void getRGB(const Mat& frame, int i, int j, int& r, int& g, int& b) {
	unsigned int b0 = frame.ptr<uchar>(i)[j*3];
	b = b0;
	unsigned int g0 = frame.ptr<uchar>(i)[j*3 + 1];
	g = g0;
	unsigned int r0 = frame.ptr<uchar>(i)[j*3 + 2];
	r = r0;
}
void search(const Mat& frame) {
	int n = frame.size().height;
	int m = frame.size().width;
	memset(f, 0, sizeof(f));
	memset(v, false, sizeof(v));
	for (int i = 0; i < n; ++ i) {
		for (int j = 0; j < m; ++ j) {
			if (frame.ptr<uchar>(i)[j] > 0) {
				f[i / 20][j / 20] ++;
			}
		}
	}
	mm = 0;
	for (int i = 0; i < 24; ++ i) {
	    for (int j = 0; j < 32; ++ j) {
		    if (mm < f[i][j]) mm = f[i][j];
	    }
	}
	cout << mm << endl;
	s = 0;
	t = 0;
	for (int j = 0; j < 32; ++ j) {
		if (f[23][j]>=mm*0.3) {
			q[t].first = 23;
			q[t].second = j;
			v[23][j] = true;
			t ++;
		}
	}
	while (s < t) {
		int x = q[s].first;
		int y = q[s].second;
		for (int i = 0; i < 4; ++ i) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (!inside(nx,ny)) continue;
			if (v[nx][ny]) continue;
			if (f[nx][ny] < mm * 0.4) continue;
			v[nx][ny] = true;
			q[t].first = nx;
			q[t].second = ny;
			t ++;
		}
		s ++;
	}
}
void paint(const Mat& frame, Mat& img) {
	int n = frame.size().height;
	int m = frame.size().width;
	for (int i = 0; i < n; ++ i) {
		for (int j = 0; j < m; ++ j) {
			int x = i / 20;
			int y = j / 20;
			if (v[x][y]) {
				img.ptr<uchar>(i)[j * 3] = 255;
                img.ptr<uchar>(i)[j * 3 + 1] = 255;
				img.ptr<uchar>(i)[j * 3 + 2] = 255;
			} else {
				for (int k = 0; k < 3; ++ k) {
					img.ptr<uchar>(i)[j * 3 + k] = frame.ptr<uchar>(i)[j * 3 + k];
				}
			}
		}
	}
}
int main() {
	string s = "/home/huangyao/research/Lab511/Mower-Robot/resource/sb/Image_";
	int i = 20;
	Mat frame;
	Mat m;
	Mat g;
	Mat img(480, 640, 16);
	while (i < 171){
		ostringstream ss;
		ss << i;
		string name = s + ss.str() + ".jpg";
		frame = imread(name);
		cvtColor(frame, g, CV_BGR2GRAY);
		cout <<name<<endl;
		Canny(g, m, 40, 120);
		threshold(m, m, 40, 255, THRESH_BINARY);
		search(m);
		paint(frame, img);
		imshow("canny", img);
		i++;
		waitKey(0);
	}
}
