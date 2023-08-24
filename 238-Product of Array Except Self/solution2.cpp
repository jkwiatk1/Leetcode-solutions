#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int vec_size = nums.size();
        std::vector<int> answer(vec_size,0);

        int product = 1;
        int zero_counts = 0;

        for(int i = 0; i < vec_size;i++){
            if(nums[i] == 0)
                zero_counts++;
            else product *= nums[i];
        }

        if (zero_counts > 1) {
            return answer; 
        }
        
        if(zero_counts == 0){
            for(int i = 0; i < vec_size;i++){
                answer[i] = product/nums[i];
            }
        }
        else if(zero_counts == 1) {
            for(int i = 0; i < vec_size;i++){
                if(nums[i] == 0)
                    answer[i] = product;
                }
        }

        return answer;
    }
};





int main(){
    Solution solution;
    vector<int> originalVector = {1,2,3,4,0,5};
    vector<int> result = solution.productExceptSelf(originalVector);
    for (const int& res : result) {
            cout << res << " ";
    }
    cout << endl;
    return 0;
}