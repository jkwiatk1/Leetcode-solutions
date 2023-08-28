#include <iostream>
#include <string>
#include <stack>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> bracketStack;

        for (char c : s) {
            if (c == '(' || c == '[' || c == '{') {
                bracketStack.push(c);
            } 
            else if (c == ')' || c == ']' || c == '}') {
                if (bracketStack.empty()) {
                    return false;  
                }

                char openingBracket = bracketStack.top();
                bracketStack.pop();

                if ((openingBracket == '(' && c != ')') ||
                    (openingBracket == '[' && c != ']') ||
                    (openingBracket == '{' && c != '}')) {
                    return false; 
                }
            }
        }

        return bracketStack.empty();  
        
    }
};

int main(){
    Solution solution;
    string input= "()[]{}";
    bool result = solution.isValid(input);
    cout << "Value: " << result << " ";


    return 0;
}