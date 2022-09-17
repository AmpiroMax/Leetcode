#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

bool validateStackSequences(vector<int> &pushed, vector<int> &popped)
{
    reverse(pushed.begin(), pushed.end());
    reverse(popped.begin(), popped.end());
    stack<int> stk;

    while (!pushed.empty())
    {
        stk.push(pushed.back());
        pushed.pop_back();

        while (!stk.empty() && !popped.empty() && popped.back() == stk.top())
        {
            stk.pop();
            popped.pop_back();
        }
    }

    while (!popped.empty() && popped.back() == stk.top())
    {
        stk.pop();
        popped.pop_back();
    }

    return stk.empty();
}

int main()
{
    vector<int> pushed({1, 2, 3, 4, 5});
    vector<int> popped({4, 5, 3, 2, 1});

    cout << validateStackSequences(pushed, popped) << endl;
    return 0;
}
