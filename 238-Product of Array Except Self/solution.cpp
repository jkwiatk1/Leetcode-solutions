#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> answer;
        queue<vector<int>> vectorQueue;
        int vec_size = nums.size();
        int j = 0;

        for(int i = 0; i < vec_size; i++){
            vectorQueue.push(nums);
        }
        
        

        while (!vectorQueue.empty()) {
            std::vector<int> currentVector = vectorQueue.front();
            vectorQueue.pop();
            int z = 0;
            int sum = 1;
            for (const int& num : currentVector) {
                if(z != j)
                    sum *= num;
                z++;
            }
            answer.push_back(sum);
            j++;
        }



        return answer; 
    }
};





int main(){
    Solution solution;
    vector<int> originalVector = {1,2,3,4};
    vector<int> result = solution.productExceptSelf(originalVector);
    for (const int& res : result) {
            cout << res << " ";
    }
    cout << endl;
    return 0;
}