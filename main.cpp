#include <iostream>
#include "dsp.hpp"

using namespace cv;
using namespace std;

int main() {
    
    vector<float> t = utils::linspace(-1, 1, 40);
    vector<float> sin12 = utils::Sin(1/2, t);
    vector<float> sin5 = utils::Sin(5, t);
    vector<float> sin10 = utils::Sin(10, t);
    vector<float> sin20 = utils::Sin(20, t);
    vector<float> sin50 = utils::Sin(50, t);

    vector<vector<float>> M = {sin12, sin5, sin10, sin20, sin50};

    vector<float> x = utils::merge(M);

    vector<float> Filter = filter::FIRLowPass(3.14159/2, 1, 50);

    vector<float> y = basic::conv1d(x, Filter);

    utils::printSeq(y);

    return 0;
}