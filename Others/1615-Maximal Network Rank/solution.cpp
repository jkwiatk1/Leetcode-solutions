#include <string>
#include <iostream>
#include <vector> 

using namespace std; 

class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        // Create the matrix to represent city connections
        vector<vector<int>> connections(n, vector<int>(n, 0));

        // Populate the matrix with road connections
        for (const vector<int>& road : roads) {
            int a = road[0];
            int b = road[1];
            connections[a][b] = 1;
            connections[b][a] = 1;
        }

        int max_rank = 0;

        // Calculate network rank for all pairs of cities
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                int rank = 0;
                for (int k = 0; k < n; ++k) {
                    rank += connections[i][k] + connections[j][k];
                }
                if (connections[i][j] == 1) {
                    rank -= 1;
                }
                max_rank = max(max_rank, rank);
            }
        }
        return max_rank;
    }
};

int main(){
    Solution solution;
    vector<vector<int>> roads = {{0, 1}, {0, 3}, {1, 2}, {1, 3}, {2, 3}, {2, 4}};
    cout << solution.maximalNetworkRank(5, roads) << endl;
    return 0;
}