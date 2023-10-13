#include <iostream>
#include <cctype>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> triplets;
        set<vector<int>> unique_triplets;
        sort(nums.begin(), nums.end());

        for(int i = 0; i < nums.size(); i++) {
            int left = i + 1;
            int right = nums.size() - 1;
            while (left < right){
                int sum = nums[i] + nums[left] + nums[right];
                if(sum == 0){
                    if(unique_triplets.find({nums[i], nums[left], nums[right]}) == unique_triplets.end()){
                        unique_triplets.insert({nums[i], nums[left], nums[right]});
                        triplets.push_back({nums[i], nums[left], nums[right]});
                    }
                    while (left < right && nums[left] == nums[left + 1]) {
                        left++;
                    }
                    left++;
                }   
                else if (sum < 0) {
                    left++;
                } else {
                    right--;
                }
            }

        }
        return triplets;
    }
};

int main()
{
    Solution solution;
    vector<vector<int>> results;
    vector<int> nums = {-1,0,1,2,-1,-4,-2,-3,3,0,4}; //{1,-1,-1,0};//{-1,0,1,2,-1,-4};
    results = solution.threeSum(nums);

    for(const auto& result : results) {
        for (int value : result) {
            cout << value << " ";
        }
        cout << endl;
    }
    return 0;
}