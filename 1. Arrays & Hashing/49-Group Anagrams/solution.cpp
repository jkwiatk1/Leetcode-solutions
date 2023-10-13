#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        std::unordered_map<string, vector<string>> sortedWords;
        vector<vector<string>> result;

        for (const string& str : strs) {
            string sortedStr = str;
            sort(sortedStr.begin(), sortedStr.end());

            sortedWords[sortedStr].push_back(str);
        }

        for (const auto& pair : sortedWords) {
            result.push_back(pair.second);
        }

        return result;
    }
};


int main(){
    Solution solution;
    vector<string> originalVector = {"eat","tea","tan","ate","nat","bat"};
    vector<vector<string>> result = solution.groupAnagrams(originalVector);
    for (const vector<string>& group : result) {
        for (const string& word : group) {
            cout << word << " ";
        }
        cout << endl;
    }


    return 0;
}