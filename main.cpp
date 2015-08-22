#include "Chapter1.h"

int main() {
    // close the sync
    ios::sync_with_stdio(false);
    clock_t stime, etime;
    stime = clock();

    Chp1 c;

    cout << "Input the matrix's size:" << endl;
    int size;
    cin >> size;
    cout << "Input the matrix's elements:" << endl;
    int **mat = (int **)malloc(sizeof(int *) * size);
    for (int r = 0; r < size; ++r) {
        mat[r] = (int *)malloc(sizeof(int) * size);
        for (int c = 0; c < size; ++c) {
            cin >> mat[r][c];
        }
    }

    c.setZeros(mat, size);

    cout << "After setZeros, the matrix is :" << endl;
    for (int r = 0; r < size; ++r) {
        for (int c = 0; c < size; ++c) {
            cout << mat[r][c];
            if (c != size - 1) {
                cout << " ";
            }
        }
        if (r != size - 1) {
            cout << endl;
        }
    }
    free(mat);

    // Time
    cout << endl << "-------------------Time Cost-----------------------" << endl;
    etime = clock();
    cout << "The time cost is : " << 1000.0 * (etime - stime) / CLOCKS_PER_SEC << " ms." << endl;

    return 0;
}
