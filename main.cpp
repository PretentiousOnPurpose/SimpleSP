#include <iostream>
#include "dsp.hpp"

using namespace cv;
using namespace std;
using namespace utils;
using namespace basic;

int main() {
    
    vector<float> t = linspace(0, 100, 100);
    vector<float> x = Sin(0.60, t, 1);

    vector<float> y;
    

    auto Filter = filter::FIRLowPass(0.25, 0.25, 1, 1, 11);

    printSeq(Filter);

    return 0;
}