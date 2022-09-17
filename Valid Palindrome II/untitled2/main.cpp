#include <iostream>

using namespace std;

bool validPalindrome(string s)
{
    int i = 0;
    int j = s.size() - 1;

    while (i < j && s[i] == s[j])
    {
        i++;
        j--;
    }
    if (i >= j)
        return true;

    bool flag1 = true;
    bool flag2 = true;
    int i0 = i;
    int j0 = j;

    if (s[i] == s[j - 1])
    {
        j--;
        while (i < j)
        {
            i++;
            j--;
            if (s[i] != s[j])
            {
                flag1 = false;
                break;
            }
        }
    }
    else
        flag1 = false;
    i = i0;
    j = j0;
    if (s[i + 1] == s[j])
    {
        i++;
        while (i < j)
        {
            i++;
            j--;
            if (s[i] != s[j])
            {
                flag2 = false;
                break;
            }
        }
    }
    else
        flag2 = false;

    return flag1 || flag2;
}

int main()
{
    string s1("deeeeee");
    string s2("ebcbbececabbacecbbcbe");
    string s3("abobcva");
    cout << validPalindrome(s3) << endl;
    return 0;
}
