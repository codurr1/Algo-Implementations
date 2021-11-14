
//Bitwise Ops
constexpr int pct(int x) { return __builtin_popcountll(x); } // # of bits set
constexpr int clz(int x) { return __builtin_clz(x); } // # of leading zeros
constexpr int ctz(int x) { return __builtin_ctz(x); } // # of trailing zeros
