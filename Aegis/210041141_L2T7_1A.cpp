#include <iostream>
#include <vector>
#include <bits/stdc++.h>
// P.L : first we store the marks and the corresponding grade in two arrays
//  then for every test case, we check which grade mark is closest, but lower than the target mark
using namespace std;

// we need this to find the grade that matches the testcase, or the one that is the closest and below the testing mark
int next(vector<int> arr, int target)
{
    if (target < arr[0])
        return 0;
    if (target > arr[arr.size() - 1])
        return arr.size() - 1;
    return (lower_bound(arr.begin(), arr.end(), target) - arr.begin()) - 1;
}

int main()
{
    int num;
    string grade;
    vector<int> gradeMark;
    vector<string> gradeLetter;
    int trials, levels;
    cin >> levels >> trials;
    for (int i = 0; i < levels; i++)
    {
        cin >> num >> grade;
        gradeMark.push_back(num);
        gradeLetter.push_back(grade);
    }

    for (int j = 0; j < trials; j++)
    {
        int testMark;
        cin >> testMark;
        cout << gradeLetter[next(gradeMark, testMark)] << endl;
    }

    // for(int x: gradeMark){
    //     cout << x << endl;
    // }

    return 0;
}
