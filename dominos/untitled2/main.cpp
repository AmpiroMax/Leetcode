#include <iostream>
#include <vector>

using namespace std;

int minDominoRotations(vector<int> &tops, vector<int> &bottoms)
{
    int i = 0;
    int n = tops.size();
    int cand1 = tops[i];
    int cand2 = bottoms[i];

    while (i < n && (cand1 == tops[i] || cand1 == bottoms[i]) && (cand2 == tops[i] || cand2 == bottoms[i]))
    {
        i++;
    }

    int trueCand = 0;

    if (i == n)
        trueCand = cand1;
    else
    {
        if ((cand1 == tops[i] || cand1 == bottoms[i]))
            trueCand = cand1;
        if ((cand2 == tops[i] || cand2 == bottoms[i]))
            trueCand = cand2;
    }

    int td = 0;
    int bd = 0;

    for (int j = 0; j < tops.size(); ++j)
    {
        if (trueCand != tops[j])
            td++;
        if (trueCand != bottoms[j])
            bd++;

        if (trueCand != tops[j] && trueCand != bottoms[j])
            return -1;
    }

    return min(min(td, n - td), min(bd, n - bd));
}

int main()
{
    vector<int> tops1({2, 1, 2, 4, 2, 2});
    vector<int> bottons1({5, 2, 6, 2, 3, 2});

    vector<int> tops2({2, 2, 2});
    vector<int> bottons2({2, 2, 2});

    vector<int> tops3({1, 4, 1, 6, 6, 1, 6, 2});
    vector<int> bottons3({2, 2, 5, 3, 1, 5, 6, 6});

    cout << minDominoRotations(tops3, bottons3) << endl;

    return 0;
}
