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

ListNode *deleteDuplicates(ListNode *head)
{
    if (!head)
        return head;

    ListNode *curr = head;
    ListNode *prev = nullptr;
    while (curr->next)
    {
        if (curr->next->val == head->val)
        {
            while (curr && curr->val == head->val)
                curr = curr->next;
            if (curr)
                head = curr;
            else
                return nullptr;
            continue;
        }

        if (curr->val != curr->next->val)
        {
            prev = curr;
            curr = curr->next;
            continue;
        }
        else
        {
            while (curr->next && curr->val == curr->next->val)
                curr = curr->next;

            if (!curr->next)
            {
                prev->next = nullptr;
                return head;
            }
            else
            {
                curr = curr->next;
                prev->next = curr;
            }
        }
    }
    return head;
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
    vector<int> vec1({1, 1, 1, 2, 3});
    vector<int> vec2({1, 1, 1, 2, 3, 4, 4});
    vector<int> vec3({1, 1, 1});
    vector<int> vec4({1, 1, 1, 3});
    vector<int> vec5({1, 1, 1, 3, 3, 4, 4, 5, 5, 6, 7, 7, 7, 8, 9, 10, 10, 10, 11});

    ListNode *head = makeList(vec5);

    printList(head);

    ListNode *newList = deleteDuplicates(head);

    printList(newList);

    return 0;
}
