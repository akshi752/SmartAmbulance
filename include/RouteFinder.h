#include "CityMap.h"
#include <queue>
#include <unordered_map>
#include <vector>
using namespace std;

class RouteFinder {
    const CityMap &cityMap;
public:
    RouteFinder(const CityMap &map) { cityMap = map; }
    pair<int, vector<string>> dijkstra(const string &source, const string &destination);
};
