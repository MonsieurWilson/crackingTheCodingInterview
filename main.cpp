#include "Chapter1.h"
#include "Chapter2.h"
#include "Chapter9.h"
#include "Chapter17.h"


int main() {
    // close the sync
    ios::sync_with_stdio(false);
    clock_t stime, etime;
    stime = clock();

    Chp17 ch;
    int a, b;
    while ((cout << "Input the a and b:" << endl) && (cin >> a >> b)) {
        cout << ch.getMaxII(a, b) << endl;
    }


    // Time
    cout << endl << "-------------------Time Cost-----------------------" << endl;
    etime = clock();
    cout << "The time cost is : " << 1000.0 * (etime - stime) / CLOCKS_PER_SEC << " ms." << endl;

    return 0;
}
