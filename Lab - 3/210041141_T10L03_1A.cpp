#include <iostream>
#include <stack>
#include <vector>
using namespace std;

bool canreordertrucks(const vector<int>& arrivalOrder) {
    stack<int> sideStreet;
    int expectedTruck = 1;

    for (int truck : arrivalOrder) {
        while (!sideStreet.empty() && sideStreet.top() == expectedTruck) {
            sideStreet.pop();
            expectedTruck++;
        }

        if (truck == expectedTruck) {
            expectedTruck++;
        } else {
            sideStreet.push(truck);
        }
    }

    while (!sideStreet.empty() && sideStreet.top() == expectedTruck) {
        sideStreet.pop();
        expectedTruck++;
    }

    return expectedTruck - 1 == arrivalOrder.size();
}

int main() {
        int numTrucks, buffer;
        vector<int> arrivalOrder;
        
        cin >> numTrucks;
        
        
        for (int j = 0; j < numTrucks; j++) {
            cin >> buffer;
            arrivalOrder.push_back(buffer);
        }

        if (canreordertrucks(arrivalOrder)) {
            cout << "yes" <<    endl;
        } else {
            cout << "no" << endl;
        }

    return 0;
}