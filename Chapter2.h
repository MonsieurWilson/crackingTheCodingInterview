#ifndef CHAPTER2
#define CHAPTER2

#include <iostream>
#include <cstring>
#include <unordered_set>
#include <stack>

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
    /* 单向链表倒数第k 个节点 */
    ListNode *kthToLast(ListNode *head, const int &k) {
        ListNode *slow = head, *fast = slow;
        for (int num = 0; num < k; ++num) {
            if (fast == nullptr) {
                return nullptr;
            }
            fast = fast->next;
        }

        while (fast) {
            slow = slow->next;
            fast = fast->next;
        }

        return slow;
    }
    /* 删除单向链表中指定节点，假定只能访问该节点*/
    bool deleteNode(ListNode *ptr) {
        if (ptr->next == nullptr) {
            return false;
        }
        ptr->val = ptr->next->val;
        ptr->next = ptr->next->next;
        return true;
    }
    /* 根据给定x 值将链表分成两部分，大于x 和小于x */
    ListNode *partition(ListNode *head, const int &x) {
        ListNode *smallPart = new ListNode(), *largePart = new ListNode();
        ListNode *spCur = smallPart, *lpCur = largePart;

        while (head != nullptr) {
            ListNode *tmp = head->next;
            head->next = nullptr;
            if (head->val < x) {
                spCur->next = head;
                spCur = head;
            }
            else {
                lpCur->next = head;
                lpCur = head;
            }
            head = tmp;
        }

        if (smallPart->next == nullptr) {
            return largePart->next;
        }
        else {
            spCur->next = largePart;
            return smallPart->next;
        }
    }
    /* 链表表示的数字求和*/
    ListNode *addLists(ListNode *l1, ListNode *l2) {
        ListNode *ret = new ListNode();
        ListNode *cur = ret;
        int carry = 0;
        while (l1 || l2 || carry) {
            if (l1) {
                carry += l1->val;
                l1 = l1->next;
            }
            if (l2) {
                carry += l2->val;
                l2 = l2->next;
            }
            if (carry) {
                cur->next = new ListNode(carry % 10);
                cur = cur->next;
                carry /= 10;
            }
        }
        return ret->next;
    }
    /* 找出有环链表的环路开始节点*/
    ListNode *findBeg(ListNode *head) {
        ListNode *slow, *fast;
        slow = fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (fast == slow) {
                break;
            }
        }

        if (fast == nullptr || fast->next == nullptr) {
            // no loop
            return nullptr;
        }

        slow = head;
        while (fast != slow) {
            slow = slow->next;
            fast = fast->next;
        }
        return slow;
    }
    /* 检测链表是否回文*/
    bool isPalindrome(ListNode *head) {
        stack<int> st;
        ListNode *slow, *fast;
        slow = fast = head;
        while (fast && fast->next) {
            st.push(slow->val);
            slow = slow->next;
            fast = fast->next->next;
        }
        if (fast) {
            slow = slow->next;
        }

        while (slow) {
            if (slow->val != st.top()) {
                return false;
            }
            st.pop();
            slow = slow->next;
        }
        return true;
    }
};
#endif
