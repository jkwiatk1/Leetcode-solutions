#include <iostream>
#include <vector>
#include <stack>
#include <string>

using namespace std;

class Solution {
public:
    bool isValidCombination(const string& combination) {
        stack<char> stack;

        for (char c : combination) {
            if (c == '(') {
                stack.push(c);
            } else if (c == ')' && !stack.empty()) {
                stack.pop();
            } else {
                return false; 
            }
        }

        return true; 
    }

    vector<string> generateParenthesis(int n) {
        vector<string> combinations;
        stack<pair<string, int>> parentheses;

        parentheses.push({"",n});

        while(!parentheses.empty()) {
            pair<string,int> current_combination = parentheses.top();
            parentheses.pop();

            if(current_combination.first.length() == 2*n){
                if(isValidCombination(current_combination.first))
                    combinations.push_back(current_combination.first);
            }
                
            else{
                if (current_combination.second > 0) {
                    parentheses.push({current_combination.first + '(', current_combination.second - 1}); 
                }
                if (current_combination.first.length() < 2 * n - current_combination.second) {
                    parentheses.push({current_combination.first + ')', current_combination.second});  
                }
            }
        }
        return combinations;
    }
};


int main()
{
    Solution solution;
    vector<string> result;
    int n = 2;
    result = solution.generateParenthesis(n);
    for(string res : result){
        cout << "Result: " << res << endl  ;
    }

    return 0;
}