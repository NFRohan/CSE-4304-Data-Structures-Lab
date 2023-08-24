// fid d1:push, 2:pop, 3:isEmpty 4:isFull 5:stackSize d6:top;
#include <iostream>
#include <vector>
using namespace std;

class customstack
{
private:
    vector<int> stackArr;
    int topPtr{-1}, stackSize{0};

public:
    void setstackSize(int a)
    {
        stackSize = a;
    }
    int top()
    {
        if(topPtr == -1){
            return 404;
        }
        else{
            return stackArr[topPtr];
        }
        
    }

    void push(int a)
    {
        if (topPtr < stackSize - 1)
        {
            topPtr = stackArr.size();
            stackArr[topPtr] = a;
        }
        else
        {
            cout << "OVERFLOW" << endl;
        }
    }

    int pop()
    {
        int ret;
        if (topPtr >= 0)
        {
            ret = stackArr[topPtr];
            topPtr--;
            return ret;
        }
        else
        {
            cout << "underflow" << endl;
        }
    }
    string isEmpty()
    {
        if(stackArr.size() > 0){
            return "False";
        }
        else{
            return "True";
        }
    }
    string isFull()
    {
        if(stackArr.size() == stackSize){
            return "True";
        }
        else{
            return "False";
        }
    }
    int size(){
        return stackArr.size();
    }
    void display(){
        for(int i = 0; i <= topPtr; i++){
            cout << stackArr[i] <<" ";
        }
    }
};


int main(){
    customstack csts;
    int opcode{0}, data{0};
    cin >> data;
    csts.setstackSize(data);
    while(opcode != -1){
        cin >> opcode;
        switch(opcode){
            case 1:{
                //push
                cin >> data;
                csts.push(data);
                break;
            }
            case 2:{
                //pop
                if(csts.size() == 0){
                    cout << "UNDERFLOW" << endl;
                }
                else{
                    cout << csts.pop() << endl;
                }
                break;
            }
            case 3:{
                //isEmpty
                cout << csts.isEmpty() << endl;
                break;
            }
            case 4:{
                //isFull
                cout << csts.isFull() << endl;
                break;
            }
            case 5:{
                //stackSize
                cout << csts.size() << endl;
                break;
            }
            case 6:{
                //top
                if(csts.top() == 404){
                    cout << "Cannot Perform operation, Stack is empty." << endl;
                }
                else{
                    cout << csts.top() << endl;
                }
                break;
            }
            case -1:{
                break;
            }
            
        }

    }
    return 0;
}