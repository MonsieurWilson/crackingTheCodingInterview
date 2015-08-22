#ifndef CHAPTER2
#define CHAPTER2

#include <iostream>
#include <cstring>
#include <unordered_set>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(): val(0), next(nullptr) {}
    ListNode(const int &v): val(v), next(nullptr) {}
    ListNode(const int &v, ListNode *n): val(v), next(n) {}
};

class Chp2 {
public:
    /* 移除未排序链表中的重复节点 */
    void deleteDup(ListNode *head) {
        unordered_set<int> hashtb;
        ListNode *ahead = new ListNode(0, head);
        ListNode *cur = ahead;
        while (cur != nullptr && cur->next != nullptr) {
            if (hashtb.count(cur->next->val) > 0) {
                cur->next = cur->next->next;
            }
            else {
                hashtb.insert(cur->next->val);
                cur = cur->next;
            }
        }
    }
    /* 单向链表导数第k 个节点 */
    ListNode *kthToLast(ListNode *head, const int &k) {
        ListNode *slow = head, *fast = slow;
        for (int num = 0; num < k; ++num) {
            if (fast == nullptr) {
                return nullptr;
            }
            fast = fast->next;
        }

        while (fast != nullptr) {
            slow = slow->next;
            fast = fast->next;
        }

        return slow;
    }
};
#endif
