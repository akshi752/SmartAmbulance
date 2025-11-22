
#ifndef CITYMAP_H
#define CITYMAP_H
#include<bits/stdc++.h>
using namespace std;
//making a bidirectional weighted graph-> to represent the city
class Edge{
    public:
    string destination;
    int distance;
};

class CityMap{
    unordered_map<string,list<Edge>>adjList;
    public:
    void addCity(const string &city);
    void addRoad(const string &from,const string &to,const int distance);
    void displayMap();
    const unordered_map<string,list<Edge>>&  getAdjList() const;
};
#endif