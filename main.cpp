#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include "dsp.hpp"

using namespace cv;
using namespace std;

int main() {

    // Mat img = imread("s.jpg", CV_LOAD_IMAGE_ANYCOLOR);
    // cout << (int)(uint8_t)img.at<Vec3d>(14, 44)[0] << endl;

    image::blur("s.jpg", 9, 0);

    return 0;
}