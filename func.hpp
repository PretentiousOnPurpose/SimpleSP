#include <vector>
#include <complex.h>
using std::vector;
using namespace std;

vector<float> conv1d(vector<float>, vector<float>);
vector<complex<float>> dft(vector<complex<float>> &, int N);
vector<complex<float>> idft(vector<complex<float>> &);
void printSeq(vector<float> &);
void printSeq(vector<complex<float>> &);