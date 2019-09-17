#include <iostream>
#include "dsp.hpp"

// using namespace cv;
using namespace std;
using namespace utils;
using namespace basic;
using namespace comm;

int main() {   

    vector<int> data = {0, 0, 0, 1, 1, 0, 1, 1};
    auto modData = QAMMod(data, 4, 8);
    auto demodData = QAMDemod(modData, 4, 4, 0);

    printSeq(demodData);

    return 0;
}