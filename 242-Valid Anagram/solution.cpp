#include <iostream>
#include <string>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution {
public:
    //Solution 1
    bool isAnagram(string s, string t) {
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());

        if(s == t) return true;
        else return false;
    }

    //Solution 2
    bool isAnagram2(string s, string t) {
        std::unordered_map<char, int> charCount;

        for (char c : s) {
            charCount[c]++;
        }

        for (char c : t) {
            charCount[c]--;
        }

        for (const auto& pair : charCount) {
            if (pair.second != 0) {
                return false;
            }
        }

        return true;
    }
};


int main(){
    Solution solution;

    string word1 = "listen";
    string word2 = "silent";
    bool result = solution.isAnagram(word1,word2);
    cout << "Return: " << result << endl;

    return 0;
}