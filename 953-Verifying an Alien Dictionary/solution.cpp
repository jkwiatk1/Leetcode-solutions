#include <vector>
#include <string>
#include <iostream>


class Solution {
public:
    bool isAlienSorted(std::vector<std::string>& words, std::string order) {
        int word;
        int words_size = words.size();
        for(int j = 0; j < words_size - 1; j++){
            word = words[j].size();
            for(int i = 0; i < word; i++) {
                if((order.find(words[j][i]) > order.find(words[j+1][i])) || (words[j+1][i] == NULL)) return false;
                if((order.find(words[j][i]) < order.find(words[j+1][i])) || (words[j][i] == NULL)) break;
            }
        }
        return true; 
    }
};

int main(){
    Solution solution;
    std::vector<std::string> words{"apple","app"};
    std::string order = "abcdefghijklmnopqrstuvwxyz";
    bool output;
    output = solution.isAlienSorted(words,order);
    std::cout << output << std::endl;
    return 0;
}