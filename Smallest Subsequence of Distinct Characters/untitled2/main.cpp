#include <iostream>
#include <stack>
#include <string.h>
#include <unordered_map>
#include <vector>
using namespace std;

/*

*/

string removeDuplicateLetters(string s)
{
    string ans = "";
    stack<pair<char, int>> stk;
    unordered_map<char, int> hash;
    unordered_map<char, int> is_in_stack;

    for (int i = 0; i < s.size(); ++i)
    {
        if (!hash.count(s[i]))
            hash[s[i]] = 1;
        else
            hash[s[i]] += 1;
        is_in_stack[s[i]] = 0;
    }

    for (int i = 0; i < s.size(); ++i)
    {
        hash[s[i]] -= 1;

        if (is_in_stack[s[i]])
            continue;

        while (!stk.empty() && stk.top().first >= s[i] && hash[stk.top().first] > 0)
        {
            is_in_stack[stk.top().first] = 0;
            stk.pop();
        }
        stk.push({s[i], i});
        is_in_stack[s[i]] = 1;
    }

    while (!stk.empty())
    {
        ans = ans + stk.top().first;
        stk.pop();
    }

    return string(ans.rbegin(), ans.rend());
}

int main()
{
    string s1 = "bcabc";
    string s2 = "cbacdcbc";
    string s3 = "cba";
    string s4 = "aboba";

    cout << removeDuplicateLetters(s1) << endl;
    cout << endl;
    cout << removeDuplicateLetters(s2) << endl;
    cout << endl;
    cout << removeDuplicateLetters(s3) << endl;
    cout << endl;
    cout << removeDuplicateLetters(s4) << endl;
    cout << endl;

    return 0;
}
