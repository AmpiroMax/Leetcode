#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct Node
{
    int value;
    int operNum;
};

// class Compare
//{
//  public:
//    bool operator()(Node lhs, Node rhs)
//    {
//        if (lhs.dist == rhs.dist)
//            return lhs.operNum > rhs.operNum;
//        else
//            return lhs.dist > rhs.dist;
//    }
//};

int brokenCalc(int startValue, int target)
{
    int opNum = 0;
    while (target > startValue)
    {
        if (target % 2 == 0)
            target /= 2;
        else
            target += 1;
        opNum++;
    }

    return opNum + startValue - target;
}
int main()
{
    cout << brokenCalc(1, 1000000000) << endl;
    return 0;
}
