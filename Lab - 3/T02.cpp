#include<iostream>
#include<stack>
#include<vector>
#include<string>
using namespace std;

string grabTag(string line, int loc){
    string tag{};
    while(line[loc] != '>'){
        tag.push_back(line[loc]);
        loc++;
    }
    tag.push_back('>');
    return tag; 
}

string constructOpeningTag(string closingTag){
    string openingTag{};
    for(int i = 0; i < closingTag.length(); i++){
        if(closingTag[i] != '/'){
            openingTag.push_back(closingTag[i]);
        }
    }
    return openingTag;
}

int main(){
    string line, buffer;
    stack<string> tags;
    int linetrack{0};
 
    
    while(line != "-1"){
        getline(cin, line);
        linetrack++;
        for(int i = 0; i < line.length(); i++){
        if(line[i] == '<'){
            //tags.push(grabTag(line, i));
            if (!(line[i+1] == '/')){
                tags.push(grabTag(line, i));
            }
            else{
                if(tags.top() == constructOpeningTag(grabTag(line, i))){
                    tags.pop();
                    if(tags.size() == 0){
                        cout << "No Error" << endl;
                        line = "-1";
                    }
                }
                else{
                    cout << "Error at line " << linetrack << endl;
                    line = "-1";
                }
            }
        }
    }
    }
     return 0;
}