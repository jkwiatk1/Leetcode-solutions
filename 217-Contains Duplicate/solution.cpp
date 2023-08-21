#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> uniqueNumbers(nums.begin(), nums.end());
        if(uniqueNumbers.size() != nums.size())
            return true;
        else
            return false;
    }
};


int main(){
    Solution solution;
    vector<int> nums = {2,5, 7, 11, 12,13,15};
    
    bool result = solution.containsDuplicate(nums);
    cout << "Return: " << result << endl;

    return 0;
}