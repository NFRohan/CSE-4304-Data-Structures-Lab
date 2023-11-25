#include <cstdio>
//bren melt
#include <iostream>
#include <queue>
#include <string> 
using namespace std;

const int MAX_TEAMS = 1005;
const int MAX_STUDENTS = 1000005;

int n;
int team[MAX_STUDENTS];
string s;
int tc = 0;

int main() {
    while (1) {
        tc++;

        // Exit the loop after the third iteration
        if (tc == 3) {
            break;
        }

        int flag = 0;
        queue<int> q;
        queue<int> p[MAX_TEAMS];

        // Input the number of teams
        cin >> n;

        // Exit the program if n is zero
        if (n == 0) {
            return 0;
        }

        // Input the students and their respective teams
        for (int i = 1; i <= n; i++) {
            int num_students_in_team;
            cin >> num_students_in_team;

            for (int j = 1; j <= num_students_in_team; j++) {
                int student_id;
                cin >> student_id;
                team[student_id] = i;
            }
        }

        // Process the commands for the current scenario
        while (1) {
            cin >> s;
            int num;

            if (s[0] == 'E') {
                // Enqueue a student into their team's queue
                cin >> num;

                if (p[team[num]].empty()) {
                    q.push(team[num]);
                    p[team[num]].push(num);
                } else {
                    p[team[num]].push(num);
                }
            } else if (s[0] == 'D') {
                // Dequeue and print the front student in the queue
                if (flag == 0) {
                    cout << "Scenario #" << tc << endl;
                    flag = 1;
                }

                if (p[q.front()].empty()) {
                    q.pop();
                }

                cout << p[q.front()].front() << endl;
                p[q.front()].pop();
            } else if (s[0] == 'S') {
                // End of scenario, print a newline and break from the loop
                cout << endl;
                break;
            }
        }
    }

    return 0;
}
