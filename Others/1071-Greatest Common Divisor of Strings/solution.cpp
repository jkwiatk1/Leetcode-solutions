#include <string>
#include <iostream>

class Solution {
public:
    std::string gcdOfStrings(std::string str1, std::string str2){ 
        int str1_size = str1.size();
        int str2_size = str2.size();
        if (str1_size < str2_size) {
            return gcdOfStrings(str2, str1);
        }
        if (str2.empty()) {
            return str1;
        }
        if (str1.substr(0, str2_size) != str2) {
            return "";
        }
        return gcdOfStrings(str1.substr(str2_size), str2);
        }
};

int main(){
    Solution solution;
    std::string output = solution.gcdOfStrings("TAUXXTAUXXTAUXXTAUXXTAUXXTAUXXTAUXXTAUXXTAUXX","TAUXXTAUXXTAUXXTAUXXTAUXX");
    std::cout << "\n" << output << std::endl;
    return 0;
}
