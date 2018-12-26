#include <cstdlib>
#include <vector>
#include <iostream>
#include "../lib/list.h"
#include "../lib/stack.h"
using namespace std;

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

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        vector<int> vec1, vec2;
        for (ListNode *it = l1; it != NULL; it = it->next) {
            vec1.push_back(it->val);
        }
        for (ListNode *it = l2; it != NULL; it = it->next) {
            vec2.push_back(it->val);
        }

        ListNode *head = nullptr, *tmp;

        int carry = 0;
        int sum = 0;

        while (vec1.size() || vec2.size()) {
            if (vec1.size() && vec2.size()) {
                sum = vec1.back() + vec2.back();
                vec1.pop_back();
                vec2.pop_back();
            } else if (vec1.size()) {
                sum = vec1.back();
                vec1.pop_back();
            } else {
                sum = vec2.back();
                vec2.pop_back();
            }

            if (sum + carry > 9) {
                sum = (sum + carry) % 10;
                carry = 1;
            } else {
                sum = sum + carry;
                carry = 0;
            }

            if (head == nullptr) {
                head = new ListNode(sum);
            } else {
                tmp = new ListNode(sum);
                tmp->next = head;
                head = tmp;
            }
        }

        if (carry == 1) {
            tmp = new ListNode(1);
            tmp->next = head;
            head = tmp;
        }

        return head;
    }
};

int main() {

    ListNode *l1 = insert_value(vector<int>{2, 4, 3, 5, 9});
    ListNode *l2 = insert_value(vector<int>{5, 6, 4, 0, 7, 8});

    Solution solution;
    ListNode *l3 = solution.addTwoNumbers(l1, l2);

    print_list(l1);
    print_list(l2);
    print_list(l3);
}
