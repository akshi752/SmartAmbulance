#include "../include/CityMap.h"
void CityMap::addCity(const string &city){
    if(adjList.find(city)==adjList.end()){
        //city not found already
        adjList[city]=list<Edge>();

    }

}
void  CityMap::addRoad(const string&from,const string &to,int distance){
    //bidirectional map
    adjList[from].push_back({to,distance});
    adjList[to].push_back({from,distance});

}
void  CityMap::displayMap(){
for(auto &pair:adjList){//traversing over map
    cout<<pair.first<<"->";
    for(auto &edge:pair.second){
     cout<<edge.destination<<"("<<edge.distance<<")";
    }
    cout<<endl;
}
}
const unordered_map<string,list<Edge>> & CityMap::getAdjList() const {
return adjList;
}