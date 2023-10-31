#include <vector>
#include <string>
#include <limits>
#include <iostream>
#include <stdexcept>

class Solution {
public:
    std::vector<int> addToArrayForm(std::vector<int>& num, int k) 
    {
        std::string numString = "";
        long long resultInt = 0;
        std::vector<int> resultVec;

        for(auto const & val : num) {
            numString += std::to_string(val);
        }

        if (k >= 0 && std::stoll(numString) > std::numeric_limits<long long>::max() - k) {
            throw std::out_of_range("Result is out of range of long long");
        } else if (k < 0 && std::stoll(numString) < std::numeric_limits<long long>::min() - k) {
            throw std::out_of_range("Result is out of range of long long");
        }
        
        resultInt = std::stoll(numString) + k;
        numString = std::to_string(resultInt);

        for (char c : numString) {
            resultVec.push_back(static_cast<int>(c) - '0');
        }
        return resultVec;
    }
};


int main(){
    std::vector<int> vec {9,9,9,9,9,9,9,9,9,9};
    Solution solution;
    try{
        std::vector<int> res = solution.addToArrayForm(vec,1);
        for(auto const & it : res){
            std::cout << it << std::endl;
        }
    }
    catch (const std::out_of_range& ex) {
        std::cerr << "Error: " << ex.what() << std::endl;
    }
    catch (...) {
        std::cerr << "Unknown error occurred." << std::endl;
    }

    return 0;
}