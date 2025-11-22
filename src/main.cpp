
#include "../include/CityMap.h"
#include "../include/RouteFinder.h"
#include "../include/Ambulance.h"
#include "../include/Patient.h"
#include "../include/TripHistory.h"
#include <iostream>
using namespace std;

int main() {
    // --- 1. Create City Map ---
    CityMap city;
    city.addCity("A");
    city.addCity("B");
    city.addCity("C");
    city.addCity("D");

    city.addRoad("A", "B", 5);
    city.addRoad("B", "C", 10);
    city.addRoad("A", "C", 15);
    city.addRoad("C", "D", 20);

    cout << "City Map:" << endl;
    city.displayMap();
    cout << "-------------------------" << endl;

    // --- 2. Create Ambulances ---
    Ambulance amb1("AMB1", "A");
    Ambulance amb2("AMB2", "B");

    // --- 3. Create Patients ---
    Patient pat1("P1", "C", "High");
    Patient pat2("P2", "D", "Medium");

    pat1.requestAmbulance();
    pat2.requestAmbulance();
    cout << "-------------------------" << endl;

    // --- 4. RouteFinder ---
    RouteFinder rf(city);

    std::pair<int, std::vector<std::string>> result1 = rf.dijkstra(amb1.location, pat1.location);
int dist1 = result1.first;
std::vector<std::string> path1 = result1.second;

std::pair<int, std::vector<std::string>> result2 = rf.dijkstra(amb2.location, pat2.location);
int dist2 = result2.first;
std::vector<std::string> path2 = result2.second;

    cout << "Route for AMB1 to P1: ";
    for(auto &loc : path1) cout << loc << " ";
    cout << "| Distance: " << dist1 << endl;

    cout << "Route for AMB2 to P2: ";
    for(auto &loc : path2) cout << loc << " ";
    cout << "| Distance: " << dist2 << endl;
    cout << "-------------------------" << endl;

    // --- 5. Assign Ambulances ---
    amb1.assignToPatient(pat1);
    amb2.assignToPatient(pat2);

    amb1.updateLocation(pat1.location);
    amb2.updateLocation(pat2.location);
    cout << "-------------------------" << endl;

    // --- 6. Trip History ---
    TripHistory history;
    history.addTrip(pat1.patientID, amb1.ambulanceID, path1);
    history.addTrip(pat2.patientID, amb2.ambulanceID, path2);

    history.displayHistory();

    return 0;
}


