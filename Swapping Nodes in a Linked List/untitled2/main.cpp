#include <iostream>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *swapNodes(ListNode *head, int k)
{
    int i = 0;
    ListNode *kp = head;
    ListNode *n_kp = head;
    ListNode *curr = head;

    while (curr->next)
    {
        if (i < k)
        {
            kp = kp->next;
        }
        else
        {
            cout << i << endl;
            n_kp = n_kp->next;
        }
        i++;
    }
    int tmp = kp->val;
    kp->val = n_kp->val;
    n_kp->val = tmp;

    return head;
}

int main()
{
    cout << "Hello World!" << endl;
    return 0;
}
