#include <vector>
#include <complex.h>
using std::vector;
using namespace std;

namespace basic {
    vector<float> conv1d(vector<float>, vector<float>);
    vector<complex<float>> dft(vector<complex<float>>, int);
    vector<complex<float>> idft(vector<complex<float>>);
    vector<complex<float>> fft(vector<complex<float>>, int, int = 0);
    vector<complex<float>> ifft(vector<complex<float>>, int);
    vector<complex<float>> fftCompute(vector<complex<float>> , int, int);
    vector<complex<float>> twiddle(int, int);
    vector<complex<float>> fftCombine(vector<complex<float>>, vector<complex<float>>, int, int);
};

namespace utils {
    void printSeq(vector<float>);
    void printSeq(vector<complex<float>>);
    vector<complex<float>> matMul(vector<complex<float>>, vector<complex<float>>);
    vector<complex<float>> matAdd(vector<complex<float>>, vector<complex<float>>);
    vector<complex<float>> getEvenOddTerms(vector<complex<float>>, int);
};

namespace filters {
    vector<complex<float>> Butter();
};

namespace image {
    vector<vector<float>> compress(vector<vector<float>>);
    vector<vector<float>> decompress(vector<vector<float>>); 
};