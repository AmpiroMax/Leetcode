#include <iostream>
#include <queue>
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

ListNode *mergeKLists(vector<ListNode *> &lists)
{
    auto CMP = [](ListNode *a, ListNode *b) { return a->val > b->val; };
    std::priority_queue<ListNode *, vector<ListNode *>, decltype(CMP)> q(CMP);

    for (size_t i = 0; i < lists.size(); ++i)
    {
        if (lists[i])
        {
            q.push({lists[i]});
            lists[i] = lists[i]->next;
        }
    }

    if (q.empty())
        return nullptr;

    ListNode *head = new ListNode(q.top()->val);
    ListNode *curr = q.top()->next;
    q.pop();
    if (curr)
        q.push(curr);

    curr = head;

    while (!q.empty())
    {
        ListNode *tmp = q.top();
        q.pop();
        if (tmp->next)
            q.push(tmp->next);
        curr->next = tmp;
        curr = curr->next;
    }

    return head;
}

int main()
{
    cout << "Hello World!" << endl;
    return 0;
}
