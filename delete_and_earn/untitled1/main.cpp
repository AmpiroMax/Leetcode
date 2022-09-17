#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

pair<int, int> keyPointMax(unordered_map<int, int> &hash)
{
    int pointsMax = 0;
    int keyMax = 0;

    for (auto &[key, value] : hash)
    {
        if (key * value > pointsMax)
        {
            pointsMax = key * value;
            keyMax = key;

            if (hash.count(key + 2) == 0 && (key - 1) * hash[key - 1] + (key + 1) * hash[key + 1] > pointsMax)
            {
                pointsMax = (key - 1) * hash[key - 1] + (key + 1) * hash[key + 1];
                keyMax = key + 1;
            }
        }
    }

    return {keyMax, pointsMax};
}

void deleteKey(unordered_map<int, int> &hash, int key)
{
    hash.erase(key + 1);
    hash.erase(key);
    hash.erase(key - 1);
}

int deleteAndEarn(vector<int> &nums)
{
    unordered_map<int, int> hash;

    for (auto num : nums)
    {
        if (!hash.count(num))
            hash[num] = 1;
        else
            hash[num] += 1;
    }

    for (auto &[key, value] : hash)
    {
        cout << key << ": " << value << endl;
    }
    cout << endl;

    int sumPoints = 0;
    int p = 0;
    int k = 0;

    while (!hash.empty())
    {
        pair<int, int> kp = keyPointMax(hash);
        k = kp.first;
        p = kp.second;

        cout << k << " " << p << endl;

        sumPoints += p;
        deleteKey(hash, k);
    }

    return sumPoints;
}

int main()
{
    vector<int> vec1({3, 4, 2});
    vector<int> vec2({2, 2, 3, 3, 3, 4});
    vector<int> vec3({8, 3, 4, 7, 6, 6, 9, 2, 5, 8, 2, 4, 9, 5, 9, 1, 5, 7, 1, 4});

    int ans = deleteAndEarn(vec3);

    cout << ans << endl;

    return 0;
}
