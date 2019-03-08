#include <iostream>
#include "dsp.hpp"
#include <cmath>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

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
    void blur(string filename, Mat filter, int filter_size) {
        Mat img = imread(filename, CV_LOAD_IMAGE_COLOR);
        auto size = img.size;
        // Mat filter = gaussianFilter(filter_size);
        for (int k = 0; k < img.channels(); k++) {
            for (int i = 0; i < size[0]; i++) {
                for (int j = 0; j < size[1]; j++) {
                    int tmp = 0, sum = 0;
                    for (int m = 0; m < filter_size; m++) {
                        for (int n = 0; n < filter_size; n++) {
                            tmp += img.at<uint8_t>(i - filter_size/2 + m, j - filter_size/2 + n, k) * filter.at<int>(m, n);
                            sum += filter.at<int>(m, n);
                        }
                    }
                    img.at<uint8_t>(i, j, k) = (uint8_t)tmp / sum;
                }
            }
        }

        imwrite("Blur" + filename, img);

    }
};
