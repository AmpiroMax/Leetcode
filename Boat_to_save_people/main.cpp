#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int numRescueBoats(vector<int> &people, int limit)
{
    sort(people.rbegin(), people.rend());
    int result = 0;
    int i = 0;
    int j = people.size() - 1;
    while (i <= j)
    {
        if (people[i] + people[j] <= limit)
            j--;

        i++;
        result++;
    }
    return result;
}

int main()
{
    vector<int> people1({3, 5, 3, 4});
    int limit1 = 5;

    vector<int> people2({3, 2, 2, 1});
    int limit2 = 3;

    vector<int> people3({2, 49, 10, 7, 11, 41, 47, 2, 22, 6, 13, 12, 33, 18, 10, 26, 2, 6, 50, 10});
    int limit3 = 50;
    cout << numRescueBoats(people1, limit1) << endl;
    cout << numRescueBoats(people2, limit2) << endl;
    cout << numRescueBoats(people3, limit3) << endl;

    return 0;
}
