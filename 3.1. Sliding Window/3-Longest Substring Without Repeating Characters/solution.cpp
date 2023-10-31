#include <iostream>
#include <set>
#include <string>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int longest_substring_length = 0;
        set<char> unique_substring = {};
        int left_pointer = 0;

        for(int r = 0; r <= s.size(); r++) {
            while(unique_substring.find(s[r]) != unique_substring.end()){
                unique_substring.erase(s[left_pointer]);
                left_pointer++;
            } 
            unique_substring.insert(s[r]);
            int tmp_res = r - left_pointer + 1; 
            if(tmp_res > longest_substring_length) longest_substring_length = tmp_res; 
        }

        return longest_substring_length;        
    }
};


int main()
{
    Solution solution;
    int result;
    string s = "abcabcbb";

    result = solution.lengthOfLongestSubstring(s);

    cout << "Result: " << result << endl;    

    return 0;
}