#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>

using namespace std;

class FreqStack
{
  private:
    class Compare
    {
      public:
        bool operator()(pair<int, pair<int, int>> lhs, pair<int, pair<int, int>> rhs)
        {
            if (lhs.first == rhs.first)
                return lhs.second.first <= rhs.second.first;
            return lhs.first < rhs.first;
        }
    };

    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, Compare> queue;
    unordered_map<int, int> hash;
    int index;

  public:
    FreqStack() { index = 0; }

    void push(int val)
    {
        if (!hash.count(val))
            hash[val] = 1;
        else
            hash[val] += 1;
        queue.push({hash[val], {index, val}});
        index++;
    }

    int pop()
    {
        int val = queue.top().second.second;
        hash[val] -= 1;
        queue.pop();
        return val;
    }
};
/*

1 5
1 7
1 5
1 7
1 4
1 5
2
2
2
2
2


1 4
1 0
1 9
1 3
1 4
1 2
2
1 6
2
1 1
2
1 1
2
1 4
2
2
2
2
2
2
*/
int main()
{
    FreqStack *obj = new FreqStack();

    char command = ' ';
    cout << "Commands: 1 - push val \n"
         << "          2 - pop val" << endl;
    while (command != '0')
    {
        cout << "Command: ";
        cin >> command;

        if (command == '1')
        {
            cout << "val = ";
            int val;
            cin >> val;
            obj->push(val);
        }
        if (command == '2')
        {
            cout << obj->pop() << endl;
        }
    }
    return 0;
}
