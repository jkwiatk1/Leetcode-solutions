#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int> sortedNums;
        int prevValue;
        int tempConsecutive = 1;
        int longestConsecutive = 1; 
        if(nums.size() > 0){
            tempConsecutive = 1;
            longestConsecutive = 1;
        }
        else{
            tempConsecutive = 0;
            longestConsecutive = 0;
        }
    
        for (int num : nums) {
            sortedNums.insert(num);
        }


        prevValue = *sortedNums.begin(); 

        for (set<int>::const_iterator it = sortedNums.begin(); it != sortedNums.end(); ++it) {
            if (*it - prevValue == 1) {
                tempConsecutive++;
            }

            if(tempConsecutive > longestConsecutive) {
                longestConsecutive = tempConsecutive;
            }

            if (*it - prevValue > 1) {
                tempConsecutive = 1;
            }

            prevValue = *it;
        }

        return longestConsecutive;
    }
};

int main(){
    Solution solution;
    vector<int> inputBoard = {0,3,7,2,5,8,4,6,0,1};
    int result = solution.longestConsecutive(inputBoard);
    cout << "Value: " << result << " ";


    return 0;
}