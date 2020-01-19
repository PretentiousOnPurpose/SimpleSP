#include <iostream>
#include "dsp.hpp"

using namespace std;
using namespace utils;
using namespace basic;
using namespace filter;

int main() {   

    // vector<complex<float>> x = {{1, 2}, {2, 3}, {5, 25}};
    vector<complex<float>> y = {{3, 9}, {4, 12}, {2, 1}, {33, 100}};
    
    // auto z = conv1d(x, flip(conj(y)));

    printSeq(downSample(y, 2));

    return 0;
}