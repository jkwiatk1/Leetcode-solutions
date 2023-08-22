#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());

        if(s == t) return true;
        else return false;
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