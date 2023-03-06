#include <iostream>
#include <vector>

class Solution {
public:
    int compress(std::vector<char>& chars) {
        bool i = 0;
        int j = 0;
        char element_before = '0';
        int elementAmount = 0;
        std::vector<char> charscompress;
        for(auto element : chars) {
            if(element_before != element){
                charscompress.push_back(element);
                elementAmount = 49;
                i = 0;
                j += 1;
            }
            if(element_before == element){
                elementAmount += 1;
                if(i == 0)
                    charscompress.push_back(elementAmount);
                else charscompress[j] = elementAmount;
                i = 1;
            }
            element_before = element;
        }
        return charscompress.size();
    }
};


int main(){
    Solution solution;
    std::vector<char> vec {'a','b', 'b','b', 'b','b', 'b','b', 'b', 'c', 'c', 'c'};
    std::cout << solution.compress(vec);
    return 0;
}