#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class KthLargest
{
  private:
    priority_queue<int, vector<int>, std::greater<int>> largests;

  public:
    KthLargest(int k, vector<int> &nums)
    {
        largests = priority_queue<int, vector<int>, std::greater<int>>(nums.begin(), nums.end());
        while (largests.size() > k)
            largests.pop();
    }

    int add(int val)
    {
        if (val <= largests.top())
            return largests.top();

        largests.push(val);
        largests.pop();

        return largests.top();
    }
};

int main()
{

    cout << "Hello World!" << endl;
    return 0;
}
