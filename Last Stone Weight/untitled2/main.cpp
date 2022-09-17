#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int lastStoneWeight(vector<int> &stones)
{
    priority_queue<int> q(stones.begin(), stones.end());

    while (q.size() > 1)
    {
        int lhs = q.top();
        q.pop();
        int rhs = q.top();
        q.pop();

        cout << lhs << " " << rhs << " " << q.size() << endl;

        if (lhs != rhs)
            q.push(lhs - rhs);
    }
    if (q.size() == 0)
        return 0;
    return q.top();
}

int main()
{
    cout << "Hello World!" << endl;
    return 0;
}
