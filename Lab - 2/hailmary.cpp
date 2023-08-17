#include <iostream>
#include <vector>

using namespace std;

int binarySearch(const vector<int>& soldiers, int power) {
    int left = 0, right = soldiers.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (soldiers[mid] <= power) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return left;
}

int main() {
    int N, R;
    cin >> N >> R;

    vector<int> soldiers(N);
    for (int i = 0; i < N; ++i) {
        cin >> soldiers[i];
    }

    for (int i = 0; i < R; ++i) {
        int power;
        cin >> power;

        int kills = binarySearch(soldiers, power);
        cout << kills << endl;
    }


    return 0;
}
