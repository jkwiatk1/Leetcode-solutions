#include <iostream>
#include <string>
#include <map>

using namespace std;
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int left_pointer = 0;
        int right_pointer = s1.size();
        map<char, int> s1_chars = {};
        map<char, int> s2_chars = {};

        for(char s : s1) {
            s1_chars[s]++;
        }


        while(right_pointer <= s2.length()) {

            for(int i = left_pointer; i < right_pointer; i++){
                s2_chars[s2[i]]++;
            }

            if(s1_chars == s2_chars) return true;   // if hash map equal s2 contains a permutation of s1

            s2_chars.clear();

            left_pointer++;     // Move window by 1
            right_pointer++;
        }
        
        return false;
    }
};

// TODO repair
// class Solution {
// public:
//     bool checkInclusion(string s1, string s2) {
//         int left_pointer = 0;
//         int right_pointer = s1.size();
//         map<char, int> s1_chars = {};
//         map<char, int> s2_chars = {};

//         for(char s : s1) {
//             s1_chars[s]++;
//         }

//         for(int i = 0; i < right_pointer; i++){
//             s2_chars[s2[i]]++;
//         }


//         while(right_pointer <= s2.length()) {

//             if(s1_chars == s2_chars) return true;   // if hash map equal s2 contains a permutation of s1

//             s2_chars.erase(s2[left_pointer]);

//             left_pointer++;     // Move window by 1
//             right_pointer++;

//             s2_chars[s2[right_pointer]]++;
//         }
        
//         return false;
//     }
// };



int main()
{
    Solution solution;
    bool result;
    string s1 = "rvwrk";
    string s2 = "lznomzggwrvrkxecjaq";
    // string s1 = "abc";
    // string s2 = "bbbca";
    // string s1 = "ab";
    // string s2 = "eidbaooo";

    result = solution.checkInclusion(s1,s2);

    cout << "Result: " << result << endl;    


    return 0;
}