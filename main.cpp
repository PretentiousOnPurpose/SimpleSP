#include <iostream>
#include "dsp.hpp"

using namespace std;
using namespace utils;
using namespace basic;
using namespace filter;
using namespace comm;

int main() {   

    vector<int> data = {1, 1, 1, 0};

    auto y = QAMMod(data, 16, 4);

    auto data_h = QAMDemod(y, 16, 1, 2);

    printSeq(y);
    printSeq(data_h);

    return 0;
}