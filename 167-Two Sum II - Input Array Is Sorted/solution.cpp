#include <iostream>
#include <string>
#include <cctype>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left = 0;
        int right = numbers.size() - 1;

        while (left < right) {
            int sum = numbers[left] + numbers[right];
            if (sum == target) {
                return {left + 1, right + 1};
            } else if (sum < target) {
                left++;
            } else {
                right--;
            }
        }
        return {};
    }
};

int main()
{
    Solution solution;
    vector<int> result;
    vector<int> numbers = {2,3,4};// {2,7,11,15};
    int target = 6; //9;
    result = solution.twoSum(numbers, target);

    for(int res : result) {
        cout << "Result: " << res << endl;    
    }

    return 0;
}