#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


class Solution {
public:
    int trap(vector<int>& height) {
        vector<int> left_height = {0};
        vector<int> right_height = {0};
        vector<int> min;
        int max_left = 0;
        int max_right = 0;
        int amount_height = height.size() - 1;
        int sum = 0;

        for(int i = 0; i < amount_height; i++) {
            if(height[i] > max_left){
                max_left = height[i];
                left_height.push_back(height[i]);
            }
            else left_height.push_back(max_left);

            if(height[amount_height - i] > max_right){
                max_right = height[amount_height - i];
                right_height.push_back(height[amount_height - i]);
            }
            else right_height.push_back(max_right);
        }

        std::reverse(right_height.begin(), right_height.end());

        transform(left_height.begin(), left_height.end(), right_height.begin(), std::back_inserter(min), [](int a, int b) 
        { return std::min(a, b); });

        for(int i = 0; i < amount_height; i++) {
            int diff = min[i] - height[i];
            if(diff < 0) min[i] = 0;
            else min[i] = diff;
        }

        for (int val : min) {
            sum += val;
        }

        return sum;
    }
};



int main()
{
    Solution solution;
    int result;
    vector<int> numbers = {0,1,0,2,1,0,1,3,2,1,2,1};

    result = solution.trap(numbers);

    cout << "Result: " << result << endl;    


    return 0;
}