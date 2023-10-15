#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        
        vector<pair<int, double>> cars; 
        // Time to reach target for each car
        for (int i = 0; i < n; i++) {
            double time = (double)(target - position[i]) / speed[i];
            cars.emplace_back(position[i], time);
        }

        // Sort cars desc
        sort(cars.begin(), cars.end(), greater<pair<int, double>>());

        int fleets = 0;
        double current_time = 0;

        for (const auto& car : cars) {
            if (car.second > current_time) {
                fleets++;
                current_time = car.second;
            }
        }

        return fleets;
    }
};






int main()
{
    Solution solution;
    int result = 0;
    int target = 12;
    vector<int> position = {10,8,0,5,3};
    vector<int> speed =    {2, 4,1,1,3};

    result = solution.carFleet(target, position, speed);    
    cout << "Result: " << result << endl;
    return 0;
}