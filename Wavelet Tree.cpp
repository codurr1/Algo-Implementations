
// returns number of elements strictly smaller than v in vec
template<class T>
int bins(const vector<T>& vec, T v) {
    int low = 0;
    int high = vec.size();
    while(low != high) {
        int mid = (low + high) >> 1;
        if (vec[mid] < v) low = mid + 1;
        else high = mid;
    }
    return low;
}

struct Wavelet {
    private:
        vector<int> vals, sums;
        vector<unsigned int> bits;
        int t, n;

        void setBit(int i, unsigned int v) { bits[i >> 6] |= (v << (i & 63)); }
        int getSum(int i) const { return sums[i >> 6] + __builtin_popcountll(bits[i >> 6] & ((1ull << (i & 63)) - 1)); }
    public:
        Wavelet(vector<int> vec) : vals(vec), t(0), n(vec.size()) {
            sort(vals.begin(), vals.end());
            vals.erase(unique(vals.begin(), vals.end()), vals.end());
            while((1 << t) < vals.size()) ++t;
            bits.resize((t*n + 64) >> 6, 0ull);
            sums.resize(bits.size(), 0);
            
            vector<int> cou((int)vals.size() + 1, 0);
            for (int& i : vec) i = bins(vals, i);
            for (int i : vec) ++cou[i + 1];
            for (int i = 1; i < vals.size(); ++i) cou[i] += cou[i-1];

            for (int j = 0; j < t; ++j) {
                for (int i : vec) {
                    int tmp = i >> (t-1 - j);
                    int pos = (tmp >> 1) << (t - j);
                    setBit(j*n + cou[pos], tmp & 1);
                    ++cou[pos];
                }
                for (int i : vec) --cou[(i >> (t - j)) << (t - j)];
            }
            for (int i = 1; i < sums.size(); ++i) sums[i] = sums[i-1] + __builtin_popcountll(bits[i-1]);
        }

        // Returns minimum value v such that |{i \in [a, b], vec[i] <= v}| > k
        int kthSmallest(int a, int b, int k) {
            ++b;--k;
            for (int j = 0, ia = 0, ib = n, res = 0;; ++j) {
                if (j == t) return vals[res];

                int cou_ia = getSum(n*j + ia);
                int cou_a = getSum(n*j + a);
                int cou_b = getSum(n*j + b);
                int cou_ib = getSum(n*j + ib);

                int ab_zeros = (b-a) - (cou_b - cou_a);
                if (ab_zeros > k) {
                    res = res << 1;
                    ib -= cou_ib - cou_ia;
                    a -= cou_a - cou_ia;
                    b -= cou_b - cou_ia;
                } else {
                    res = (res << 1) | 1;
                    k -= ab_zeros;
                    ia += (ib - ia) - (cou_ib - cou_ia);
                    a += (ib - a) - (cou_ib - cou_a);
                    b += (ib - b) - (cou_ib - cou_b);
                }
            }
        }
};
