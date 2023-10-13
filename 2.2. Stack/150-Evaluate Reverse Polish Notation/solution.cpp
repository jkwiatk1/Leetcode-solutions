#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <cctype>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> numbers;

        for(string token : tokens) {
            bool isDigit = true;
            for (char c : token) {  
                if ((c == '+' || c == '-' || c == '/' || c == '*') && token.size() == 1) {
                    isDigit = false;
                    break;
                }
            }
            if (isDigit) {
                numbers.push(stoi(token));
            } 
            else {
                if(token == "+") {
                    int a = numbers.top(); numbers.pop();
                    int b = numbers.top(); numbers.pop();
                    numbers.push(a+b);
                }

                else if(token == "-") {
                    int a = numbers.top(); numbers.pop();
                    int b = numbers.top(); numbers.pop();
                    numbers.push(b-a);
                }

                else if(token == "/") {
                    int a = numbers.top(); numbers.pop();
                    int b = numbers.top(); numbers.pop();
                    numbers.push(b/a);
                }

                else if(token == "*") {
                    int a = numbers.top(); numbers.pop();
                    int b = numbers.top(); numbers.pop();
                    numbers.push(a*b);
                }
            }
        }
        return numbers.top();
    }
};


int main()
{
    Solution solution;
    vector<string> tokens = {"10","6","9","3","+","-11","*","/","*","17","+","5","+"};//{"2","1","+","3","*"};
    int result = solution.evalRPN(tokens);
    cout << result << endl;

    return 0;
}