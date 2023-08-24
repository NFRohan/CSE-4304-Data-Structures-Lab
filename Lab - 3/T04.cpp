#include<iostream>
#include<vector>
#include<stack>
using namespace std;

int main(){
    int loc, rightMax, buffer;
    vector<int> numList;
    vector<int> ngeList;
    stack<int> proc;

    while(buffer != -1){
        cin >> buffer;
        numList.push_back(buffer);
        ngeList.push_back(-1);
    }
    


    for(int i = 0; i < numList.size(); ++i){
        while(!proc.empty() && numList[i] > numList[proc.top()]){

            int a = proc.top();
            proc.pop();
            ngeList[a] = numList[i];
        }
        proc.push(i);
    }



    for(int j = 0; j < ngeList.size(); j++){
        cout << ngeList[j] << endl;
    }

    
    return 0;
}