#include <vector>
#include <string>
#include <limits>
#include <iostream>
#include <stdexcept>
#include <algorithm>

class Solution {
public:
    std::vector<int> addToArrayForm(std::vector<int>& num, int k) 
    {
        std::vector<int> resultVec;
        int numSize = num.size() - 1;
        int carry = 0;
        while(numSize >= 0 || carry > 0 || k > 0) {
            if(k > 0){
                int lastValue;
                if(numSize >= 0) lastValue = k % 10 + num[numSize] + carry;
                else lastValue = k % 10 + carry;
                carry = lastValue / 10;
                lastValue = lastValue % 10;
                resultVec.push_back(lastValue);
                numSize--;
                k = k / 10;
            }
            else if(carry > 0){
                int lastValue;
                if(numSize >= 0) lastValue = carry % 10 + num[numSize];
                else lastValue = carry % 10;
                carry = lastValue / 10;
                lastValue = lastValue % 10;
                resultVec.push_back(lastValue);
                numSize--;
            }
            else{
                int lastValue;
                if(numSize >= 0) lastValue = k % 10 + num[numSize];
                else lastValue = k % 10;
                resultVec.push_back(lastValue);
                numSize--;
                k = k / 10;
            } 
        }
        reverse(resultVec.begin(), resultVec.end());
        return resultVec;
    }
};


int main(){
    std::vector<int> vec {0};
    Solution solution;
    std::vector<int> res = solution.addToArrayForm(vec,23);
    for(auto const & it : res){
        std::cout << it << std::endl;
    }

    return 0;
}