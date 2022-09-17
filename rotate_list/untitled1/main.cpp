#include <iostream>
#include <vector>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *rotateRight(ListNode *head, int k)
{
    if (!head)
        return nullptr;

    ListNode *curr = head;

    int n = 0;
    while (curr)
    {
        curr = curr->next;
        n++;
    }

    k = k % n;

    // index of new head is equal to n - k
    // head of list has index 0
    curr = head;
    int i = 0;
    while (i != n - k - 1)
    {
        curr = curr->next;
        i++;
    }

    if (!curr->next)
        return head;

    ListNode *newHead = curr->next;
    curr->next = nullptr;
    curr = newHead;

    while (curr->next)
    {
        curr = curr->next;
    }

    curr->next = head;

    return newHead;
}

void printList(ListNode *head)
{
    cout << "printing list" << endl;
    ListNode *curr = head;
    while (curr)
    {
        cout << curr->val << " ";
        curr = curr->next;
    }
    cout << endl;
}

ListNode *makeList(vector<int> vec)
{
    ListNode *head = new ListNode(vec[0]);
    ListNode *curr = head;

    for (auto el : vec)
    {
        ListNode *newNode = new ListNode(el);
        curr->next = newNode;
        curr = curr->next;
    }

    return head->next;
}

int main()
{
    vector<int> vec1({2, 4, 3});
    vector<int> vec2({5, 6, 4});
    vector<int> vec3({9, 9, 9, 9, 9, 9, 9});
    vector<int> vec4({9, 9, 9, 9});
    vector<int> vec5({1, 1, 1, 3, 3, 4, 4, 5, 5, 6, 7, 7, 7, 8, 9, 10, 10, 10, 11});

    ListNode *head = makeList(vec1);

    printList(head);

    ListNode *newList = rotateRight(head, 4);

    printList(newList);

    return 0;
}
