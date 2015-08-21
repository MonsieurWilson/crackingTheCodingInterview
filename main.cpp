#include <iostream>

using namespace std;

#include "Chapter1.h"

int main() {
    // close the sync
    ios::sync_with_stdio(false);
    clock_t stime, etime;
    stime = clock();

    Chp1 c;

    cout << "Input the string :" << endl;
    string str;
    cin >> str;
    bool ret = c.isUniqueChar(str);
    cout << (ret ? "True" : "False") << endl;

    return 0;
}
