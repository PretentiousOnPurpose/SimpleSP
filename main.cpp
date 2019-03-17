#include <iostream>
#include "dsp.hpp"

using namespace cv;
using namespace std;
using namespace utils;
using namespace basic;

int main() {   

    auto Filter = filter::FIRLowPass(400, 420, 2000, 11);

    printSeq(Filter);

    return 0;
}