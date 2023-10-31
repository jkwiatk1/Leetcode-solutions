#include <iostream>
#include <vector>
#include <string>

class Solution {
public:
    int compress(std::vector<char>& chars) {
        int size = chars.size();
        int charscompressSize = 0;
        int elementAmount;  

        if(size == 1) return 1;    

        for(int i = 0; i < size; i++) {
            elementAmount = 1;
            while(i < size && chars[i]==chars[i+1])
            {
                i++;
                elementAmount++;
            } 
            chars[charscompressSize] = chars[i];
            charscompressSize += 1;  
            if(elementAmount > 1){
                std::string countStr = std::to_string(elementAmount);
                for (char c : countStr) {
                    chars[charscompressSize++] = c;
                }
            }     
        }
        
        return charscompressSize;
    }
};


int main(){
    Solution solution;
    std::vector<char> vec {'a','b', 'b','b', 'b','b', 'b','b', 'b', 'b','b', 'b','b','b','b', 'b','b'};
    std::cout << solution.compress(vec);
    return 0;
}