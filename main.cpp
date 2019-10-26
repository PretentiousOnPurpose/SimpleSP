#include <iostream>
#include "dsp.hpp"

using namespace std;
using namespace utils;
using namespace basic;
using namespace filter;

int main() {   

    auto h = FIRLowPass(18, 20, 100, 11);
    printSeq(h);

    return 0;
}