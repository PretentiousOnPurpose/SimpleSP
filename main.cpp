#include <iostream>
#include "dsp.hpp"

// using namespace cv;
using namespace std;
using namespace utils;
using namespace basic;

int main() {   

    vector<complex<float>> x1 = {{1, 0}, {2, 0}, {3, 0}, {4, 0}};
    vector<complex<float>> x2 = {{2, 0}, {3, 0}};

    vector<complex<float>> y = basic::conv1d(x1, x2);

    printSeq(y);

    return 0;
}