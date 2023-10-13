#include <iostream>
#include <cctype>
#include <vector>

using namespace std;

class Solution{
public:
    int maxArea(vector<int>& height){
        int left = 0;
        int right = height.size() - 1;
        int max_area = 0;

        while (left < right) {
            int area =(right - left)*min(height[left], height[right]);
            if (area > max_area) max_area = area;
            if (height[left] <  height[right]) {
                left++;
            } else {
                right--;
            }
        }
        return max_area;
    }
};


int main()
{
    Solution solution;
    int result;
    vector<int> numbers = {1,2,4,3};//{1,8,6,2,5,4,8,3,7};

    result = solution.maxArea(numbers);

    cout << "Result: " << result << endl;    


    return 0;
}