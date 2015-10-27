#ifndef CHAPTER9
#define CHAPTER9

#include <vector>
#include <iostream>

using namespace std;

class Chp9 {
public:
    /* 给定不同数量的硬币，币值为25, 10, 5, 1，计算给定的n 能有几种表示方法*/
    vector<vector<int>> makeChange(const int n) {
        vector<vector<int>> ret;
        makeChange(n, 25, vector<int>(), ret);
        return ret;
    }
    void makeChange(const int n, const int base, vector<int> sol, vector<vector<int>> &ret) {
        if (n == 0 || base == 1) {
            if (base == 1) {
                for (int i = 0; i < n; ++i) {
                    sol.push_back(1);
                }
            }
            ret.push_back(sol);
            return;
        }
        int nextBase = 0;
        switch(base) {
            case 25:
                nextBase = 10;
                break;
            case 10:
                nextBase = 5;
                break;
            case 5: 
                nextBase = 1;
                break;
            default:
                break;
        }
        for (int i = 0; i * base <= n; ++i) {
            for (int j = 1; j <= i; ++j) {
                sol.push_back(base);
            }
            makeChange(n - i * base, nextBase, sol, ret);
        }
    }


};

#endif
