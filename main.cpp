#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include "dsp.hpp"

using namespace cv;
using namespace std;

int main() {

    image::blur("d.jpg", 7);


    return 0;
}