#include <iostream>
#include <vector>
#include <string>

class Solution {
public:
    int compress(std::vector<char>& chars) {
        int n = chars.size();
        int count;
        std::string countStr;
        if (n == 1) {
            return 1;
        }
        
        int writeIdx = 0, anchorIdx = 0;
        for (int readIdx = 0; readIdx < n; readIdx++) {
            if (readIdx == n - 1 || chars[readIdx] != chars[readIdx + 1]) {
                chars[writeIdx++] = chars[anchorIdx];
                if (readIdx > anchorIdx) {
                    count = readIdx - anchorIdx + 1;
                    countStr = std::to_string(count);
                    for (char c : countStr) {
                        chars[writeIdx++] = c;
                    }
                }
                anchorIdx = readIdx + 1;
            }
        }
        
        return writeIdx;
    }
};


int main(){
    Solution solution;
    std::vector<char> vec {'a','b', 'b','b', 'b','b', 'b','b', 'b', 'c', 'c', 'c'};
    std::cout << solution.compress(vec);
    return 0;
}