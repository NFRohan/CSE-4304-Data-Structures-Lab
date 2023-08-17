#include <iostream>
#include<time.h>
using namespace std;

int main() {
    int arr[1024]={0}, count{0}, sum{0}, len{0}, posflag{0};
    cin >> len;
    for(int i=0; i<len; i++){
        cin>>arr[i];
    }
    //check if positive values exist in array
    for(int j=0; j<len; j++){
        if(arr[j] >=0 ){
            posflag = 1;
        }
    }
    //if positive values exist, find sum by only adding non-negative values
    if(posflag){
        for(int k=0; k<len; k++){
        if(arr[k] >=0 ){
            sum += arr[k];
            count++;
            }
        }
    }
    //if no positive values, find the largest value and count its occurences
    else{
        sum = arr[0];
        count=1;
        for(int l=0; l<len; l++){
            if(arr[l] > sum){
                sum=arr[l];
                count=1;
            }
            else if(arr[l]==sum){
                count++;
                }
            }
            
            
        }
        

    
    cout << sum <<" "<<count;
    
    return 0;
}