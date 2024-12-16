#include "chi_square.h"
#include <vector>
#include <cmath>

double chi_square(const std::vector<int>& seq1, const std::vector<int>& seq2) {
    int n1 = seq1.size();
    int n2 = seq2.size();

    std::vector<int> freq1(2, 0), freq2(2, 0);
    for (int bit : seq1) freq1[bit]++;
    for (int bit : seq2) freq2[bit]++;

    double chi2 = 0.0;
    for (int j = 0; j < 2; ++j) {
        int v1j = freq1[j];
        int v2j = freq2[j];
        int total = v1j + v2j;

        if (total > 0) {
            double term = (static_cast<double>(v1j) / n1 - static_cast<double>(v2j) / n2);
            chi2 += (n1 * n2 / static_cast<double>(total)) * term * term;
        }
    }
    return chi2;
}

double chi_square(const std::vector<int>& seq) {
    int n = seq.size();

    std::vector<int> freq(2, 0);
    for (int bit : seq) freq[bit]++;

    double expected = n / 2.0;

    double chi2 = 0.0;
    for (int j = 0; j < 2; ++j) {
        double term = freq[j] - expected;
        chi2 += term * term / expected;
    }
    return chi2;
}
