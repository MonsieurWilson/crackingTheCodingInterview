#include "Chapter1.h"
#include "Chapter2.h"


int main() {
    // close the sync
    ios::sync_with_stdio(false);
    clock_t stime, etime;
    stime = clock();

    // Chp1 c;
    Chp2 c;

    cout << "Input the list :" << endl;
    ListNode *ahead = new ListNode(), *cur = ahead;
    int val;
    while (cin >> val && val != -1) {
        cur->next = new ListNode(val);
        cur = cur->next;
    }

    bool ret = c.isPalindrome(ahead->next);
    cout << (ret ? "True" : "False") << endl;


    // Time
    cout << endl << "-------------------Time Cost-----------------------" << endl;
    etime = clock();
    cout << "The time cost is : " << 1000.0 * (etime - stime) / CLOCKS_PER_SEC << " ms." << endl;

    return 0;
}
