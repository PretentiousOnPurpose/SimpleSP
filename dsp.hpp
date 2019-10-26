#include <vector>
#include <complex.h>
using std::vector;
using namespace std;

namespace basic {
    vector<complex<float>> conv1d(vector<complex<float>>, vector<complex<float>>);
    vector<complex<float>> circConv(vector<complex<float>>, vector<complex<float>>);
    vector<complex<float>> dft(vector<complex<float>>, int);
    vector<complex<float>> idft(vector<complex<float>>, int);
    vector<complex<float>> fft(vector<complex<float>>, int, int = 0);
    vector<complex<float>> ifft(vector<complex<float>>, int);
    vector<complex<float>> fftCompute(vector<complex<float>> , int, int);
    vector<complex<float>> twiddle(int, int);
    vector<complex<float>> fftCombine(vector<complex<float>>, vector<complex<float>>, int, int);
};

namespace utils {
    void printSeq(vector<int>);
    void printSeq(vector<float>);
    void printSeq(vector<complex<float>>);
    
    vector<complex<float>> realToComplex(vector<float>);
    vector<float> complexToReal(vector<complex<float>>);
    vector<float> ampResponse(vector<complex<float>>);

    vector<float> linspace(float, float, float);
    vector<float> sampler(float, float, float);
    vector<float> Sin(float, vector<float>);
    vector<float> Cos(float, vector<float>);
    
    vector<float> merge(vector<vector<float>>);

    vector<complex<float>> matMul(vector<complex<float>>, vector<complex<float>>);
    vector<complex<float>> matAdd(vector<complex<float>>, vector<complex<float>>);
    vector<float> matMul(vector<float>, vector<float>);
    vector<float> matAdd(vector<float>, vector<float>);

    vector<float> zeroPadding(vector<float>, int);
    vector<complex<float>> zeroPadding(vector<complex<float>>, int);

    vector<complex<float>> getEvenOddTerms(vector<complex<float>>, int);
    float cAbsDiffSqr(complex<float> a, complex<float> b);
    float max(vector<float>);
    float max(float, float);
    float min(vector<float>);
    float min(float, float);
    float sum(vector<float>);
    int len(vector<float>);
    int len(vector<complex<float>>);
    void wait();
};

namespace filter {
    vector<float> FIRLowPass(float, float, float, int, int = 0, string = "rect");
};

namespace comm {
    vector<complex<float>> QAMMod(vector<int>, int M, int size);
    vector<int> QAMDemod(vector<complex<float>>, int M, int size, int softOut);
}

