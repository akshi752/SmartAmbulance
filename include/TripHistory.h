#ifndef TRIPHISTORY_H
#define TRIPHISTORY_H

#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct TripNode {
    string patientID;
    string ambulanceID;
    vector<string> route;
    TripNode* next;
};

class TripHistory {
    TripNode* head;
public:
    TripHistory();
    void addTrip(string patientID, string ambulanceID, vector<string> route);
    void displayHistory();
};

#endif
int main() {
    TripHistory history;

    vector<string> route1 = {"A", "B", "C"};
    vector<string> route2 = {"C", "D"};

    history.addTrip("P1", "AMB1", route1);
    history.addTrip("P2", "AMB2", route2);

    history.displayHistory();

    return 0;
}
