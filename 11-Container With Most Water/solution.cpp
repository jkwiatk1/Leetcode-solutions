#include <iostream>
#include <cctype>
#include <vector>

using namespace std;

class SolutionBrutal{
public:
    int maxArea(vector<int>& height) {
        int area = 0;
        int max_area = 0;
        for(int l = 0; l < height.size();l++){
            for(int r = l; r < height.size();r++){
                area = (r-l)*min(height[l],height[r]);
                if(area > max_area) max_area = area;
            }
        }
        return max_area;
    }
};


int main()
{
    SolutionBrutal solution;
    int result;
    vector<int> numbers = {1,8,6,2,5,4,8,3,7};

    result = solution.maxArea(numbers);

    cout << "Result: " << result << endl;    


    return 0;
}