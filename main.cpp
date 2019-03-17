#include <iostream>
#include "dsp.hpp"

using namespace cv;
using namespace std;
using namespace utils;
using namespace basic;

int main() {
    
    vector<float> t = sampler(0, 1, 400);
    
    vector<float> x = Sin(60, t);  

    vector<float> y;
    

    auto Filter = filter::FIRLowPass(120, 150, 400, 100, 11);

    printSeq(circConv(x, t));

    return 0;
}