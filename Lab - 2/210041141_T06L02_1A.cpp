#include<iostream>
using namespace std;
int main(){
    int positionArr[1024]={0},  index{0}, pipeVar{0};
    string rawDataArr[1024]={}, fixedArr[1024]={};
    //fill position array
    while(1){
        cin >> pipeVar;
        if(pipeVar != -1){
            positionArr[index] = pipeVar;
            index++;
        }
        else{
            break;
        }
    }
    //fill raw data array
    for(int i=0; i < index; i++){
        cin >> rawDataArr[i];
    }
    //fill fixed data array
    for(int j=0; j <= index; j++){
        fixedArr[positionArr[j]] = rawDataArr[j];
    }

    for(int k=0; k <= index; k++){
        cout<<fixedArr[k]<<endl;
    }
    return 0;
}