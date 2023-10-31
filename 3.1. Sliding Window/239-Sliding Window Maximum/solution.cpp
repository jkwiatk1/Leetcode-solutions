#include <iostream>
#include <deque>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> result; 
        deque<int> dq;      // Index

        for (int i = 0; i < nums.size(); i++) {
            // Remove elements that are out of the current window
            if (!dq.empty() && dq.front() < i - k + 1) {
                dq.pop_front();
            }

            // Pop smaller elements from the back of the deque
            while (!dq.empty() && nums[dq.back()] < nums[i]) {
                dq.pop_back();
            }

            dq.push_back(i); // Add current index to the deque

            // Adding the maximum value to the results after reaching the window size
            if (i >= k - 1) {
                result.push_back(nums[dq.front()]);
            }
        }

        return result;
    }
};





int main()
{
    Solution solution;
    vector<int> result = {};
    vector<int> nums = {1,3,-1,-3,5,3,6,7};
    int k = 3;

    result = solution.maxSlidingWindow(nums,k);

    cout << "Result: " << endl;
    for(int res : result) 
        cout << ": " << res << endl;    


    return 0;
}