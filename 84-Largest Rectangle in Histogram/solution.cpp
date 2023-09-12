#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <utility>

using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<pair<int,int>> pairStack; //index, height
        int maxArea = 0;

        pairStack.push(make_pair(0,heights[0]));

        for(int i = 1; i < heights.size(); i++){
            int top_index = i;
            while(!pairStack.empty() && heights[i] < pairStack.top().second){
                top_index = pairStack.top().first; 
                int tmpArea = pairStack.top().second * (i-top_index);
                if(tmpArea > maxArea) maxArea = tmpArea;
                pairStack.pop();
            }

            pairStack.push(make_pair(top_index,heights[i]));
        
            if(heights[i] > pairStack.top().second){
                pairStack.push(make_pair(i,heights[i]));
            }
        }

        while(!pairStack.empty()) {
            int tmpArea = pairStack.top().second * (heights.size() - pairStack.top().first);
            if(tmpArea > maxArea) maxArea = tmpArea;
            pairStack.pop();
        } 

        return maxArea;
    }
};


int main()
{
    Solution solution;
    int result;
    vector<int> heights = {2,1,5,6,2,3};

    result = solution.largestRectangleArea(heights);

    cout << "Result: " << result << endl  ;

    return 0;
}