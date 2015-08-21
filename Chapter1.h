#ifndef CHAPTER1
#define CHAPTER1

class Chp1 {
public:
    bool isUniqueChar(string str) {
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
};
#endif
