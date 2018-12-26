#include <iostream>

/**
 * Definition for singly-linked list.
**/
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* init_head(int val) {
    return new ListNode(val);
}

ListNode* insert_tail(ListNode *head, int val) {
    if (head == nullptr) {
        return init_head(val);
    }

    ListNode *tmp = head;
    while(tmp->next != nullptr) {
        tmp = tmp->next;
    }

    ListNode *new_node = new ListNode(val);
    tmp->next = new_node;

    return head;
}

void print_list(ListNode *head) {
    if (head == nullptr) {
        std::cout << "List is empty!" << std::endl;
        return;
    }

    std::cout << "List : [ ";
    for (; head != nullptr; head = head->next) {
        if (head->next != nullptr) {
            std::cout << head->val << ", ";
        } else {
            std::cout << head->val << " ]" << std::endl;
        }
    }

    return;
}
ListNode* remove_node(ListNode *head, int val) {
    if (head == nullptr) {
        return nullptr;
    }

    if (head->val == val) {
        delete head;
        head = nullptr;
        return nullptr;
    }

    ListNode *pre_node = head;
    ListNode *node = pre_node->next;
    while (node != nullptr) {
        if (node->val == val) {
            pre_node->next = node->next;
            delete node;
            return head;
        }

        pre_node = node;
        node = node->next;
    }

    return head;
}


