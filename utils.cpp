#include <iostream>
#include <complex.h>
#include <vector>
#include "dsp.hpp"
using std::vector;
using namespace std;

namespace utils {
    void printSeq(vector<float> & x) {
        cout.precision(3);
        for (int i = 0; i < x.size(); i++) {
            cout << x[i] << " ";
        }
        cout << endl;
    }

    void printSeq(vector<complex<float>> & x) {
        cout.precision(3);
        for (int i = 0; i < x.size(); i++) {
            cout << x[i] << " ";
        }
        cout << endl;
    }

    int revBit(int n) { 
        int rev = 0;       
        while (n > 0) { 
            rev <<= 1; 
            
            if (n & 1 == 1) {
                rev ^= 1; 
            }

            n >>= 1;     
        } 
        return rev; 
    } 

    vector<complex<float>> bitReversal(vector<complex<float>> & x) {
        vector<complex<float>> y;
        cout << x.size() << endl;
        for (int i = 0; i < x.size(); i++) {
            y.push_back(x[revBit(i)]);
        }
        return y;
    }
}