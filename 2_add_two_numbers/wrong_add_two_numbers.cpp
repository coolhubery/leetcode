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

        ListNode *head = nullptr, *node = nullptr;

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
                node = head;
            } else {
                node->next = new ListNode(sum);
                node = node->next;
            }
        }

        if (carry == 1) {
            node->next = new ListNode(1);
        }
        return head;
    }

    // Using so stupid method!!!
    ListNode* addTwoNumbers2(ListNode* l1, ListNode* l2) {
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

    ListNode* addTwoNumbers3(ListNode* l1, ListNode* l2) {
        LeetStack<int> stack1;
        LeetStack<int> stack2;

        for (ListNode *itr = l1; itr != nullptr; itr = itr->next) {
            stack1.push(itr->val);
        }

        for (ListNode *itr = l2; itr != nullptr; itr = itr->next) {
            stack2.push(itr->val);
        }

        int carry = 0;
        ListNode *head = nullptr;
        while (stack1.size() || stack2.size()) {
            int sum = 0;
            if (stack1.size() && stack2.size()) {
                sum = stack1.top() + stack2.top() + carry;
                stack1.pop();
                stack2.pop();
            } else if (stack1.size()) {
                sum = stack1.top() + carry;
                stack1.pop();
            } else {
                sum = stack2.top() + carry;
                stack2.pop();
            }

            if (sum > 9) {
                head = insert_tail(head, sum % 10);
                carry = 1;
            } else {
                head = insert_tail(head, sum);
                carry = 0;
            }
        }

        return head;
    }
};

int main() {

    ListNode *l1 = insert_value(vector<int>{2, 4, 3, 5, 9});
    ListNode *l2 = insert_value(vector<int>{5, 6, 4, 0, 7, 8});

    Solution solution;
    // ListNode *l3 = solution.addTwoNumbers(l1, l2);
    ListNode *l3 = solution.addTwoNumbers3(l1, l2);

    print_list(l1);
    print_list(l2);
    print_list(l3);
}
