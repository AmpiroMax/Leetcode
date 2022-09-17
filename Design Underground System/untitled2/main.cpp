#include <iostream>
#include <set>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class UndergroundSystem
{
  private:
    unordered_map<int, pair<string, int>> inRoad;
    unordered_map<string, unordered_map<string, pair<int, int>>> time;

  public:
    UndergroundSystem() {}

    void checkIn(int id, string stationName, int t) { inRoad[id] = {stationName, t}; }

    void checkOut(int id, string finish, int t2)
    {
        string start = inRoad[id].first;
        int t1 = inRoad[id].second;
        inRoad.erase(id);

        if (!time[start].count(finish))
        {
            time[start][finish] = {t2 - t1, 1};
        }
        else
        {
            time[start][finish] = {time[start][finish].first + t2 - t1, time[start][finish].second + 1};
        }
    }

    double getAverageTime(string startStation, string endStation)
    {
        int dumb;
        return 1.0 * time[startStation][endStation].first / time[startStation][endStation].second;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */

int main()
{
    cout << "Hello World!" << endl;
    return 0;
}
