#include <iostream>
#include <vector>

using namespace std;

class Solution
{
  public:
    int calPoints(vector<string> &ops)
    {
        vector<int> stack;

        for (int i = 0; i < ops.size(); ++i)
        {
            if (ops[i] == "+")
            {
                int tmp = stack.back();
                stack.pop_back();
                int s = tmp + stack.back();
                stack.push_back(tmp);
                stack.push_back(s);
            }
            else if (ops[i] == "C")
            {
                stack.pop_back();
            }
            else if (ops[i] == "D")
            {
                stack.push_back(stack.back() * 2);
            }
            else
            {
                stack.push_back(stoi(ops[i]));
            }
        }

        int sum = 0;
        for (int i = 0; i < stack.size(); ++i)
        {
            sum += stack[i];
        }
        return sum;
    }
};

int main()
{
    cout << "Hello World!" << endl;
    return 0;
}
