#include <iostream>

using namespace std;

string getSmallestString(int n, int k)
{
    string s(n, 'a');
    int ind = n - 1;
    k -= n;

    while (k > 0)
    {
        int delta = min(25, k);
        cout << delta << endl;
        s[ind] += delta;
        k -= 25;
        ind--;
    }

    return s;
}

int main()
{
    int n = 10;
    string s(n, 'a');

    cout << getSmallestString(5, 73) << endl;
    return 0;
}
