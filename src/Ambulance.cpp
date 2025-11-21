#ifndef AMBULANCE_H
#define AMBULANCE_H

#include <string>
#include <iostream>
using namespace std;

class Patient; 

class Ambulance {
public:
    string ambulanceID;
    string location;
    bool available;

    Ambulance(string id, string loc);

    void assignToPatient(Patient &p);
    void updateLocation(const string &newLoc);
};

#endif
