#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

// Definition for a Node.
class Node
{
  public:
    int val;
    Node *next;
    Node *random;

    Node(int _val)
    {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

Node *copyRandomList(Node *head)
{
    if (!head)
        return nullptr;

    unordered_map<Node *, Node *> hash;
    Node *newHead = new Node(head->val);
    hash[head] = newHead;
    Node *newCurr = newHead;
    Node *curr = head;

    while (curr->next)
    {
        curr = curr->next;
        Node *newNode = new Node(curr->val);
        newCurr->next = newNode;

        hash[curr] = newNode;

        newCurr = newCurr->next;
    }

    newCurr = newHead;
    curr = head;

    while (curr)
    {
        newCurr->random = hash[curr->random];
        curr = curr->next;
        newCurr = newCurr->next;
    }

    return newHead;
}

void printList(Node *head)
{
    cout << "printing list" << endl;
    Node *curr = head;
    while (curr)
    {
        cout << curr->val << " ";
        curr = curr->next;
    }
    cout << endl;
}

Node *makeList(vector<int> vec)
{
    Node *head = new Node(vec[0]);
    Node *curr = head;

    for (auto el : vec)
    {
        Node *newNode = new Node(el);
        curr->next = newNode;
        curr = curr->next;
    }

    return head->next;
}

int main()
{
    vector<int> vec1({2, 4, 3, 5, 6, 7});

    Node *head = makeList(vec1);

    printList(head);

    Node *newList = copyRandomList(head);

    printList(newList);

    return 0;
}
