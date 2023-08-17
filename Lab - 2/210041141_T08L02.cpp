#include<iostream>
#include<string>
using namespace std;
int inversionCounter(string& a){
    int count{0};
    for(int i = 0; i < a.length(); i++){
        for(int j = i+1; j < a.length(); j++){
            if(a[i] > a[j]){
                count++;
            }
        }
    }
    return count;
}

int bubbleSort(int *a, int len){
    int *tex = a;
    //using bubble sort to sort the numbers inside array
    for (int i = 0; i < len; i++)
	{
        for (int j = i+1; j < len; j++)
	    {
            if (tex[i] > tex[j]) 
			//to check that previous value has bigger ascii value than next value or not,
	    {
		//code to swap the previous and next characters
                int temporary = tex[i];
                tex[i] = tex[j];
                tex[j] = temporary;
            }
        }   
    }
    return 0;
}

int main(){
    string a[100];
    int unsortedness[100]={0}, strlen, strcnt;
    cin >> strlen >> strcnt;
    for(int i = 0; i < strcnt; i++){
        cin >> a[i];
        unsortedness[i] = inversionCounter(a[i]);
    }   
    bubbleSort(unsortedness, strcnt);
    
    for(int j = 0; j < strcnt; j++){
        for(int k = 0; k < strcnt; k++){
            if(unsortedness[j] == inversionCounter(a[k])){
                cout << a[k] << " " << unsortedness[j] << endl;
            }
        }
    }

    return 0;
}