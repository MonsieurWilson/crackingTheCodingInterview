#ifndef CHAPTER1
#define CHAPTER1

#include <iostream>
#include <cstring>

using namespace std;

class Chp1 {
public:
    /* 确定一个字符串的所有字符是否全部不同 */
    bool isUniqueChar(const string &str) {
        if (str.size() > 26) {
            return false;
        }

        int checker = 0;
        for (int i = 0; i < str.size(); ++i) {
            int num = str[i] - 'a';
            if ((checker & (1 << num)) > 0) {
                return false;
            }
            checker |= 1 << num;
        }
        return true;
    }
    /* 翻转字符串 */
    void reverse(char *str) {
        char *end = str;
        if (str) {
            while (*end) {
                ++end;
            }
            --end;

            while (str < end) {
                swap(*str++, *end--);
            }
        }
    }
    /* 变位词(case sensitive) */
    bool permutation(const string &src, const string &dst) {
        int lenSrc = src.size(), lenDst = dst.size();
        if (lenSrc != lenDst) {
            return false;
        }

        int *hashmap = new int[256];
        
        for (int idx = 0; idx < lenSrc; ++idx) {
            ++hashmap[src[idx]];
        }
        for (int idx = 0; idx < lenDst; ++idx) {
            if (--hashmap[dst[idx]] < 0) {
                return false;
            }
        }
        return true;
    }
    /* 将空格替换为'%20' */
    void replaceSpaces(char *str) {
        int spaceCount = 0, lens = strlen(str), newLens;
        for (int idx = 0; idx < lens; ++idx) {
            if (str[idx] == ' ') {
                ++spaceCount;
            }
        }
        newLens = lens + 2 * spaceCount;
        str[newLens] = '\0';

        for (int idx = lens - 1; idx >= 0; --idx) {
            if (str[idx] == ' ') {
                str[--newLens] = '0';
                str[--newLens] = '2';
                str[--newLens] = '%';
            }
            else {
                str[--newLens] = str[idx];
            }
        }
    }
    /* 压缩字符串 */
    char *compressAlternate(char *str) {
        int lens = strlen(str);
        int newLens = countCompression(str);
        if (newLens >= lens) {
            return str;
        }

        char *ret = (char *)malloc(sizeof(char) * newLens);
        int i = 0, counter = 1;
        char last = str[0];
        char tmp[lens] = {0};
        for (int idx = 1; idx < lens; ++idx) {
            if (str[idx] == last) {
                ++counter;
            }
            else {
                ret[i++] = last;
                sprintf(tmp, "%d", counter);
                for (int j = 0; tmp[j] != '\0'; ++j) {
                    ret[i++] = tmp[j];
                }
                counter = 1;
                last = str[idx];
            }
        }
        ret[i++] = last;
        sprintf(tmp, "%d", counter);
        for (int j = 0; tmp[j] != '\0'; ++j) {
            ret[i++] = tmp[j];
        }

        return ret;
    }
    int countCompression(const char *str) {
        if (str == nullptr) {
            return 0;
        }

        int lens = 0, counter = 1;
        char last = str[0];
        char num[strlen(str)] = {0};
        for (int idx = 0; str[idx] != '\0'; ++idx) {
            if (str[idx] == last) {
                ++counter;
            }
            else {
                last = str[idx];
                sprintf(num, "%d", counter);
                lens += 1 + strlen(num);
                counter = 1;
            }
        }
        sprintf(num, "%d", counter);
        lens += 1 + strlen(num);

        return lens;
    }
    /* 图像90 度翻转*/
    void rotate(int **mat, const int &size) {
        for (int l = 0; l < size / 2; ++l) {
            int beg = l, end = size - 1 - beg;
            for (int c = beg; c < end; ++c) {
                int offset = c - beg, tmp = mat[l][c];

                mat[beg][c] = mat[end - offset][beg];
                mat[end - offset][beg] = mat[end][end - offset];
                mat[end][end - offset] = mat[c][end];
                mat[c][end] = tmp;
            }
        }
    }
    /* 检测一个字符串是否能由另一个字符串翻转而成*/
    bool isRotation(const string &s1, const string &s2) {
        int lens1 = s1.size(), lens2 = s2.size();
        if (lens1 == lens2 && lens1 > 0) {
            string s3 = s1 + s1;
            return (strstr(s3.c_str(), s2.c_str()) != NULL);
        }
        return false;
    }
    /* 将矩阵中0 元素所在行、列都设为0 */
    void setZeros(int **mat, const int &size) {
        bool fstRowZero = false, fstColZero = false;
        for (int c = 0; c < size; ++c) {
            if (mat[0][c] == 0) {
                fstRowZero = true;
                break;
            }
        }
        for (int r = 0; r < size; ++r) {
            if (mat[r][0] == 0) {
                fstColZero = true;
                break;
            }
        }

        for (int r = 1; r < size; ++r) {
            for (int c = 1; c < size; ++c) {
                if (mat[r][c] == 0) {
                    mat[r][0] = 0;
                    mat[0][c] = 0;
                }
            }
        }

        for (int r = 1; r < size; ++r) {
            for (int c = 1; c < size; ++c) {
                if (mat[r][0] == 0 || mat[0][c] == 0) {
                    mat[r][c] = 0;
                }
            }
        }

        if (fstRowZero) {
            for (int c = 0; c < size; ++c) {
                mat[0][c] = 0;
            }
        }
        if (fstColZero) {
            for (int r = 0; r < size; ++r) {
                mat[r][0] = 0;
            }
        }
    }
};
#endif
