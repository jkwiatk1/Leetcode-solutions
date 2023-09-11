#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <utility>

using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> answer(temperatures.size(),0);
        stack<pair<int,int>> pairStack;

        pairStack.push(make_pair(temperatures[0],0));

        for(int i = 1; i < temperatures.size(); i++) {
            while(!pairStack.empty() && temperatures[i] > pairStack.top().first) {
                answer[pairStack.top().second]= i - pairStack.top().second;
                pairStack.pop();
            } 
            pairStack.push(make_pair(temperatures[i],i));
        }

        return answer;
    }
};


int main()
{
    Solution solution;
    vector<int> result;
    vector<int> temperatures = {73,74,75,71,69,72,76,73};

    result = solution.dailyTemperatures(temperatures);

    for(int res : result){
        cout << "Result: " << res << endl  ;
    }

    return 0;
}