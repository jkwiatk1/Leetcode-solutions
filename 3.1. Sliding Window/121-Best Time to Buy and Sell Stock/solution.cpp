#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() == 0) {return 0;}    

        int left = 0;
        int right = 1;
        int max_result = 0;

        while(right < prices.size()){
            if(prices[right] > prices[left]) {
                int result = prices[right] - prices[left];
                if(result > max_result) max_result = result;    
            }
            else
                left = right;

            right += 1;
        }
        return max_result;
    }
};



int main()
{
    Solution solution;
    int result;
    vector<int> numbers = {7,1,5,3,6,4};

    result = solution.maxProfit(numbers);

    cout << "Result: " << result << endl;    


    return 0;
}