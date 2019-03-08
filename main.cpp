#include <iostream>
#include "dsp.hpp"
#include <opencv2/core/core.hpp>

using namespace std;

int main() {
    // cv::Mat f = image::gaussianFilter(7);
    // float sum = 0;
    // for (int i = 0; i < 7; i++) {
    //     for (int j = 0; j < 7; j++) {
    //         cout << f.at<uint>(i, j) << " ";
    //         sum += f.at<uint>(i, j);
    //     }
    //     cout << endl;
    // }
    //     cout << sum << endl;

    int arr[5][5] = {{1, 4, 7, 4, 1}, {4, 16, 26, 16, 4}, {7, 26, 41, 26, 7}, {4, 16, 26, 16, 4}, {1, 4, 7, 4, 1}};
    cv::Mat f = cv::Mat(5, 5, CV_32FC1, &arr);

    image::blur("s.jpg", f, 5);

    return 0;
}



#include <iostream>
#include <vector>
#include <complex.h>
#include "dsp.hpp"
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

using namespace cv;

using std::vector;
using namespace std;

int main() {
    int ksize = 7;
    int filter[ksize][ksize] = {{30, 30, 30, 30, 30, 30, 30}, {30, 30, 30, 30, 30, 30, 30}, {30, 30, 30, 30, 30, 30, 30}, {30, 30, 30, 30, 30, 30, 30}, {30, 30, 30, 30, 30, 30, 30}, {30, 30, 30, 30, 30, 30, 30}, {30, 30, 30, 30, 30, 30, 30}};
    Mat img = imread("s.jpg", CV_LOAD_IMAGE_COLOR);
    auto size = img.size;

    for (int k = 0; k < img.channels(); k++) {
        for (int i = 0; i < size[0]; i++) {
            for (int j = 0; j < size[1]; j++) {
                uint tmp = 0;
                // cout << tmp << endl;
                for (int m = 0; m < ksize; m++) {
                    for (int n = 0; n < ksize; n++) {
                        tmp += img.at<uint8_t>(i - ksize/2 + m, j - ksize/2 + n, k) * filter[m][n];
                    }
                }
                img.at<uint8_t>(i, j, k) = tmp / 1470;
            }
        }
    }

    imwrite("blurred4.jpg", img);

    return 0;
}
