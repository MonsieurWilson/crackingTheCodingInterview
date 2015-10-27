#include "Chapter1.h"
#include "Chapter2.h"
#include "Chapter9.h"


int main() {
    // close the sync
    ios::sync_with_stdio(false);
    clock_t stime, etime;
    stime = clock();

    Chp9 chp;
    int n;
    while (cin >> n) {
    }


    // Time
    cout << endl << "-------------------Time Cost-----------------------" << endl;
    etime = clock();
    cout << "The time cost is : " << 1000.0 * (etime - stime) / CLOCKS_PER_SEC << " ms." << endl;

    return 0;
}
