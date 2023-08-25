#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<int, int> board_col;
        unordered_map<int, int> board_row;
        unordered_map<int, int> board_box;

        for (int r = 0; r < 9; r++) {
            for (int c = 0; c < 9; c++) {
                char val = board[r][c];
                if (val != '.') {
                    int box = (r / 3) * 3 + c / 3; 
                    int num = val - '0'; 

                    if (board_row[r * 9 + num] || board_col[c * 9 + num] || board_box[box * 9 + num]) {
                        return false;
                    }
                    board_row[r * 9 + num] = 1;
                    board_col[c * 9 + num] = 1;
                    board_box[box * 9 + num] = 1;
                }
            }
        }

        return true;
    }
};

int main(){
    Solution solution;
    vector<vector<char>> inputBoard = {
        {'5','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}
    };
    bool result = solution.isValidSudoku(inputBoard);
    cout << "Value: " << result << " ";


    return 0;
}