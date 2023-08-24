#include<iostream>
#include<vector>
using namespace std;

vector<int> replaceElements(vector<int> &arr)
{
    int len = arr.size();
    if (len == 0 || len == 1)
    {
        arr[0] = -1;
        return arr;
    }
    int rightMax = arr[len];
    arr[len] = -1;

    for (int i = len - 2; len >= 1; i--)
    {
        int newMax = max(arr[i], rightMax);
        arr[i] = rightMax;
        rightMax = newMax;
    }
    return arr;
}
int main(){
    vector<int> target{17,18,5,4,6,1};
    replaceElements(target);

    for(int i = 0; i <= 5; i++){
        cout << target[i] << endl;
    }
}