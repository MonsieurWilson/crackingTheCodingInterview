#ifndef CHAPTER17
#define CHAPTER17

#include <iostream>
#include <cstring>

using namespace std;

class Chp17 {
public:
    /* 不使用if-else 和其他比较运算符，求的两个数的最大值*/
    int getMax(const int a, const int b) {
        int c = a - b;
        int sa = sign(a), sb = sign(b), sc = sign(c);
        int sign_a_b = sa ^ sb, sign_c = myFlip(sa ^ sb);
        int k = sign_a_b * sa + sign_c * sc;
        int q = myFlip(k);
        return k * a + q * b;
    }
    int sign(const int num) {
        return num & (1 << 31);
    }
    int myFlip(const int num) {
        return num ^ 1;
    }
        
    int getMaxII(const int a, const int b) {
        // 使用了比较运算符，不过这个方法比较巧妙
        return b ^ ((a ^ b) & ~(a < b));
    }
};

#endif
