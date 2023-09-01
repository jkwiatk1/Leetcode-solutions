#include <iostream>
#include <vector>
#include <stack>
#include <string>

using namespace std;

class Solution {
private: 
    void backtrack(vector<string>& combinations, string current, int left, int right, int max){
        if(current.length() == 2* max){
            combinations.push_back(current);
            return;
        }
        if(left < max) backtrack(combinations, current + '(', left + 1, right, max);
        if(right < left) backtrack(combinations, current + ')', left, right + 1, max);
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string> combinations;
        backtrack(combinations,"",0,0,n);
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