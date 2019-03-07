#include <vector>
#include <complex.h>
using std::vector;
using namespace std;

namespace basic {
    vector<float> conv1d(vector<float> &, vector<float> &);
    vector<complex<float>> dft(vector<complex<float>> &, int);
    vector<complex<float>> idft(vector<complex<float>> &);
    vector<complex<float>> fft(vector<complex<float>> &, int);
    vector<complex<float>> fftCompute(vector<complex<float>> & , int)
    vector<complex<float>> twiddle(int);
    // vector<complex<float>> ifft(vector<complex<float>> &);
};

namespace utils {
    void printSeq(vector<float> &);
    void printSeq(vector<complex<float>> &);
    int revBit(int);
    vector<complex<float>> bitReversal(vector<complex<float>> &);
    vector<complex<float>> dot(vector<complex<float>> &, vector<complex<float>> &);
};

namespace filters {
    vector<complex<float>> Butter();
};

namespace image {
    vector<vector<float>> compress(vector<vector<float>>);
    vector<vector<float>> decompress(vector<vector<float>>); 
};