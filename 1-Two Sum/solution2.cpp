#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> numToIndex; 

        for (int i = 0; i < nums.size(); ++i) {
            int complement = target - nums[i];
            if (numToIndex.count(complement)) { 
                return {numToIndex[complement], i};
            }
            numToIndex[nums[i]] = i; 
        }

        return {}; 
    }
};


int main(){
    Solution solution;
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;
    
    vector<int> result = solution.twoSum(nums, target);
    cout << "Indices: " << result[0] << " " << result[1] << endl;
    cout << "Values: " << nums[result[0]] << " " << nums[result[1]] << endl;

    return 0;
}