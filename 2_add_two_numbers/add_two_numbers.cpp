#include <cstdlib>
#include <vector>
#include <iostream>
using namespace std;

/**
 * Definition for singly-linked list.
**/
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* insert_value(vector<int> vec) {
    ListNode *head = nullptr;
    ListNode *node = nullptr;
    for (int val : vec) {
        if (head == nullptr) {
            head = new ListNode(val);
            node = head;
        } else {
            node->next = new ListNode(val);
            node = node->next;
        }
    }

    return head;
}
class Solution {
public:
    // Using so stupid method!!!
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        vector<int> vec1, vec2;
        for (ListNode *it = l1; it != NULL; it = it->next) {
            vec1.push_back(it->val);
        }
        for (ListNode *it = l2; it != NULL; it = it->next) {
            vec2.push_back(it->val);
        }

        ListNode *head = nullptr, *node = nullptr;

        int i = vec1.size();
        int j = vec2.size();
        bool carry = false;
        for (; i > 0 || j > 0; --i, --j) {
            int val;

            if ((i != 0 && j != 0) || (i == 0 && j == 0)) {
                val = vec1[i-1] + vec2[j-1];
            } else if (i == 0) {
                val = vec2[j-1];
            } else {
                val = vec1[i-1];
            }

            // If the lower level add operation carriies...
            if (carry)
            {
                val += 1;
                carry = false;
            }

            if (val > 9) {
                carry = true;
                val %= 10;
            }

            if (node == nullptr) {
                head = new ListNode(val);
                node = head;
            } else {
                node->next = new ListNode(val);
                node = node->next;
            }
        }

        return head;
    }
};

int main() {

    ListNode *l1 = insert_value(vector<int>{2, 4, 3});
    ListNode *l2 = insert_value(vector<int>{5, 6, 4});

    Solution solution;
    ListNode *l3 = solution.addTwoNumbers(l1, l2);

    for (ListNode *it = l1; it != nullptr; it = it->next) {
        cout << it->val << " ";
    }
    cout << endl;

    for (ListNode *it = l2; it != nullptr; it = it->next) {
        cout << it->val << " ";
    }
    cout << endl;

    for (ListNode *it = l3; it != nullptr; it = it->next) {
        cout << it->val << " ";
    }
    cout << endl;
}
