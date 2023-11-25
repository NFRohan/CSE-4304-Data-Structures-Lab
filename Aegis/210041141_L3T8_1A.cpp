#include <iostream>
#include <stack>
#include <string>

bool checkParentheses(const std::string &code)
{
    std::stack<char> parentheses;

    for (char ch : code)
    {
        if (ch == '(' || ch == '[' || ch == '{')
        {
            parentheses.push(ch);
        }
        else if (ch == ')' || ch == ']' || ch == '}')
        {
            if (parentheses.empty())
            {
                return false;
            }

            char top = parentheses.top();
            // parentheses.pop();

            if ((ch == ')' && top != '(') || (ch == ']' && top != '[') || (ch == '}' && top != '{'))
            {
                return false;
            }
            else{
                parentheses.pop();
            }
            
        }
    }
    if(!parentheses.size()){ return true;}
    else{return false;}
}

int main()
{
    int lines;
    std::cin >> lines;
    std::string code, drx;
    std::cout << "Enter the block of code:\n";
    std::cin.ignore();
    for (int i = 0; i < lines; i++)
    {
        std::getline(std::cin, drx);
        code += drx;
    }

    if (checkParentheses(code))
    {
        std::cout << "No Error.\n";
    }
    else
    {
        std::cout << "Error\n";
    }

    return 0;
}
