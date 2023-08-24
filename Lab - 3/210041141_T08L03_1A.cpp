#include <iostream>
#include <vector>
#include <stack>
#include <string>

using namespace std;

char findOpeningParenthesis(char x)
{
    if (x == ')')
    {
        return '(';
    }

    if (x == '}')
    {
        return '{';
    }

    if (x == ']')
    {
        return '[';
    }
}

int main()
{
    stack<char> parenthesisProc;
    string line;
    int lc;
    cin >> lc;
    while (lc >= 0)
    {
        getline(cin, line);
        for (int i = 0; i < line.length(); i++)
        {
            if (line[i] == '(' || line[i] == '{' || line[i] == '[')
            {
                parenthesisProc.push(line[i]);
            }
            if (line[i] == ')' || line[i] == '}' || line[i] == ']')
            {
                if (parenthesisProc.size() > 0 && parenthesisProc.top() == findOpeningParenthesis(line[i]))
                {
                    parenthesisProc.pop();
                }
                else
                {
                    cout << "Error" << endl;
                    return 0;
                }
            }
        }
        lc--;
    }

    if (parenthesisProc.size() == 0)
    {
        cout << "No Errors" << endl;
    }
    else
    {
        cout << "Error" << endl;
    }
}