#include<iostream>
using namespace std;

int findMaxFunc(int* a, int len){
    int max{0};
    for(int i = 0; i < len; i++){
        if(a[i] > max){
            max = a[i];
        }
    }
    return max;
}

int findMinFunc(int *a, int len){
    int min = a[0];
    for(int i = 0; i < len; i++){
        if(a[i] < min){
            min = a[i];
        }
    }
    return min;
}

int totalSumFunc(int *a, int len){
    int sum{0};
    for(int i=0; i<len; i++){
        sum += a[i];
    }
    return sum;
}


int main(){
    int arr[1024]={0}, len{0}, totalSum{0}, maxVal{0}, minVal{0};
    cin >> len;
    for(int i = 0; i < len; i++){
        cin >> arr[i];
    }

    totalSum = totalSumFunc(arr, len);
    maxVal = findMaxFunc(arr, len);
    minVal = findMinFunc(arr, len);

    cout << (totalSum - maxVal) << " " << (totalSum - minVal);
    
    return 0;
}