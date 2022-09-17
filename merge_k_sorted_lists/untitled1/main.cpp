#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *mergeKLists(vector<ListNode *> &lists)
{
    ListNode *head = new ListNode();
    priority_queue<ListNode*,  vector<ListNode*>, [](ListNode* a, ListNode* b) -> bool
    {
        return a > b;
    });
    return head;
}

int main()
{
    cout << "Hello World!" << endl;
    return 0;
}
