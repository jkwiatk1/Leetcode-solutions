#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> numsFreq;
        vector<int> result;

        for(const int& num : nums) {
            numsFreq[num]++;
        }

        for(int i = 0; i < k; i++) {
            int maxKey = 0;  
            int maxFreq = 0;
            bool foundMax = false;

            for (const auto& pair : numsFreq) {
                if (!foundMax || pair.second > maxFreq) {
                    foundMax = true;
                    maxFreq = pair.second;
                    maxKey = pair.first;
                }
            }

            if (foundMax) {
                result.push_back(maxKey);
                numsFreq[maxKey] = 0;  // The key has already been added to the result
            }
        }

        return result; 
    }
};





int main(){
    Solution solution;
    int k = 2;
    vector<int> originalVector = {1,1,1,2,2,3};
    vector<int> result = solution.topKFrequent(originalVector,k);
    for (const int& res : result) {
            cout << res << " ";
    }
    cout << endl;
    return 0;
}