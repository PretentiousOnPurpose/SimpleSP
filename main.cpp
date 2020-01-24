#include <iostream>
#include "dsp.hpp"

using namespace std;
using namespace utils;
using namespace basic;
using namespace filter;
using namespace comm;

int main() {   

    vector<int> data = {1, 0, 0, 1, 1, 1, 0, 0};
    vector<complex<float>> modData = QAMMod(data, 4, 8);
    vector<int> data_hat = QAMDemod(modData, 4, 4, 1, 1);

    printSeq(data_hat);

    return 0;
}