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
        std::vector<int> prefProd(vec_size, 1);
        std::vector<int> sufProd(vec_size, 1);
        std::vector<int> answer(vec_size);

        int product = 1;

        for(int i = 0; i < vec_size;i++){
            prefProd[i] = product;
            product *= nums[i];
        }

        product = 1;
        for(int i = vec_size-1; i >= 0;i--){
            sufProd[i] = product;
            product *= nums[i];
        }

        for(int i = 0; i < vec_size;i++){
            answer[i] = prefProd[i] * sufProd[i];
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