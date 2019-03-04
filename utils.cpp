#include <iostream>
#include <complex.h>
#include <vector>
#include "dsp.hpp"
using std::vector;
using namespace std;

namespace utils {
    void printSeq(vector<float> & y) {
        cout.precision(3);
        for (int i = 0; i < y.capacity(); i++) {
            cout << y[i] << " ";
        }
        cout << endl;
    }

    void printSeq(vector<complex<float>> & y) {
        cout.precision(3);
        for (int i = 0; i < y.capacity(); i++) {
            cout << y[i].real() << " + " << y[i].imag() << "i" << " ";
        }
        cout << endl;
    }
}