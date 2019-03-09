#include <iostream>
#include "dsp.hpp"
#include <cmath>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <cstdlib>

using namespace cv;
using namespace std;

namespace image {
    Mat gaussianFilter(int size) {
        Mat filter = Mat::zeros(size, size, CV_32FC1);
        double sum=0.0;
        int si = 2;
        for (int i = -size/2; i <= size/2; i++) {
            for (int j = -size/2; j <= size/2; j++) {
                filter.at<int>(i+size/2, j+size/2) = ceil(100 * exp(-(i*i+j*j)/(2*si*si))/(2*M_PI*si*si));
                sum += filter.at<int>(i+size/2, j+size/2);
            }
        }

        filter.at<uint>(size/2, size/2) *= 3;

        return filter;
    }
    void blur(string filename, int ksize) {
        Mat filter = image::gaussianFilter(ksize);
        Mat img = imread(filename, CV_LOAD_IMAGE_GRAYSCALE);
        Mat bimg = Mat::zeros(img.rows, img.cols, CV_8UC1);

        for (int k = 0; k < 1; k++) {
            for (int i = 0; i < img.rows; i++) {
                for (int j = 0; j < img.cols; j++) {
                    int tmp = 0, sum = 0;
                    
                    for (int m = 0; m < ksize; m++) {
                        for (int n = 0; n < ksize; n++) {
                            if (!( (i - ksize/2 + m) < 0 || (j - ksize/2 + n) < 0 || (i - ksize/2 + m) >= (img.rows) || (j - ksize/2 + n) >= (img.cols) )) {                                
                                tmp += (int) img.at<uint8_t>(i - ksize/2 + m, j - ksize/2 + n, k) * filter.at<int>(m, n);
                                sum += filter.at<int>(m, n);
                            }
                        }
                    }
                    bimg.at<uint8_t>(i, j, k) = tmp / sum;
                } 
            }
        }


        imwrite("B" + filename, bimg);
    }
};
