#include <string>
#include <opencv2/opencv.hpp>
#include "opencv2/video/tracking.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "edgedetect/EdgeDetect.h"
#include <fstream>
#include <iostream>
using namespace std;
using namespace cv;
/*
 * setting parameters
 */
int start;
int tail;
string ext;
string prefix;
/*
 * read setting file
 */
void getSetting() {
		ifstream fin;
		fin.open("../setting/setting.txt");
		string l;
		while (!fin.eof()) {
				getline(fin, l);
				if (l.length() > 0 && l[0] != '#') {
						string s = "";
						int i;
						for (i = 0; i < (int)l.length(); ++ i) {
								if (l[i] == ' ') {
										break;
								}
								s = s + l[i];
						}
						string v = "";
						for (int j = i + 1; j < (int)l.length(); ++ j) {
								v = v + l[j];
						}
						if (s == "prefix") {
								prefix = v;
						} else if (s == "ext") {
								ext = v;
						} else if (s == "tail") {
								tail = atoi(v.c_str());
						} else if (s == "start") {
								start = atoi(v.c_str());
						}
						cout << s << " : " << v << "\n";
				}
		}
		fin.close();
}
int main() {

	getSetting();

        string s = "../data/" + prefix;
        int i = start;
        Mat frame;
        Mat m;
        Mat g;
        EdgeDetect detector(640, 480, 20, 0.4, 0.4);
        bool** result = NULL;
        while (i <= tail){
                ostringstream ss;
                ss << i;
                string name = s + ss.str() + "." + ext;
                frame = imread(name);
                cout << name << endl;
                cvtColor(frame, g, CV_BGR2GRAY);
                detector.detect(g, result);
                detector.paint(frame, result);
                imshow("canny", frame);
                i++;
                waitKey(0);
        }
}

