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

ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
{
    ListNode *head = new ListNode();
    ListNode *curr = head;
    int digit = 0;
    int l1Val = 0;
    int l2Val = 0;
    int sum = 0;

    while (l1 || l2 || digit)
    {
        ListNode *newNode = new ListNode();
        if (l1)
        {
            l1Val = l1->val;
            l1 = l1->next;
        }
        else
        {
            l1Val = 0;
        }
        if (l2)
        {
            l2Val = l2->val;
            l2 = l2->next;
        }
        else
        {
            l2Val = 0;
        }

        sum = l1Val + l2Val + digit;

        if (sum >= 10)
        {
            digit = 1;
            sum = sum - 10;
        }
        else
        {
            digit = 0;
        }

        newNode->val = sum;
        curr->next = newNode;
        curr = curr->next;
    }

    return head->next;
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

    ListNode *l1 = makeList(vec1);
    ListNode *l2 = makeList(vec2);

    printList(l1);
    printList(l2);

    ListNode *newList = addTwoNumbers(l1, l2);

    printList(newList);

    return 0;
}
