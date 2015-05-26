#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>
#include <sstream>
#include <string>
#include <unistd.h>
using namespace cv;
using namespace std;

string num2str(int i)
{
	stringstream ss;
	ss<<i;
	return ss.str();
} 
int main() {
	VideoCapture stream1(0);   //0 is the id of video device.0 if you have only one camera.
 
	if (!stream1.isOpened()) { //check if video device has been initialised
		cout << "cannot open camera";
	}
	else
		cout<< "open success"<<endl;
 
	//ddunconditional loop
	int MAX = 500;
 	int count = 0;
	while (count<MAX) {
		Mat cameraFrame;
		string s1="/home/huangyao/projects/Mower-Robot/img/";
		string s2;
		s2 = num2str(count);
		string s3 = s1+s2+".jpg";
		const char* imgName = s3.c_str();
		cout<<s3<<endl;
		stream1.read(cameraFrame);
		imwrite(imgName, cameraFrame);
		count = count + 1;
		for(int j=0;j<1000;j++)
			usleep(1000);
		if (waitKey(30) >= 0)
			break;
	}
return 0;
}
