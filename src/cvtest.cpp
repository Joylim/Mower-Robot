#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>
using namespace cv;
using namespace std;
int main (int argc, char **argv)
{
    Mat image, image_gray;
    image = imread(argv[1], CV_LOAD_IMAGE_COLOR );
    if (argc != 2 || !image.data) {
        cout << "No image data\n";
        return -1;
    }
   
    cvtColor(image, image_gray, CV_RGB2GRAY);
    namedWindow("image", CV_WINDOW_AUTOSIZE);
    namedWindow("image gray", CV_WINDOW_AUTOSIZE);
   
    imshow("image", image);
    imshow("image gray", image_gray);
   
    waitKey(0);
    return 0;
}
