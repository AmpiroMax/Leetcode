#include <iostream>

using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *swapPairs(ListNode *head)
{
    if (!head)
        return head;

    if (head->next == nullptr)
        return head;

    ListNode *newHead = head->next;
    head->next = newHead->next;
    newHead->next = head;

    ListNode *curr = head;
    ListNode *tmp1 = nullptr;
    ListNode *tmp2 = nullptr;

    if (head->next == nullptr)
        return newHead;

    while (curr->next != nullptr)
    {
        tmp1 = curr->next;
        tmp2 = curr->next->next;
        curr->next = tmp2;
        if (!tmp1->next)
        {
            curr->next = tmp1;
            break;
        }
        tmp1->next = tmp2->next;
        tmp2->next = tmp1;
        curr = tmp1;
    }

    return newHead;
}

int main()
{
    ListNode *head = new ListNode(0);
    ListNode *curr = head;

    for (int i = 0; i < 5; ++i)
    {
        ListNode *newNode = new ListNode(i, curr);
        curr = newNode;
    }

    *curr = *head;
    while (curr != nullptr)
    {
        cout << curr->val << endl;
        curr = curr->next;
    }

    return 0;
}
