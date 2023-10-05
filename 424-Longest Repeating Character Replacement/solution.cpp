#include <iostream>
#include <string>
#include <map>

using namespace std;

class Solution {
public:
    int characterReplacement(string s, int k) {
        int max_res = 0;
        int left_pointer = 0;
        int right_pointer = 1;
        map<char, int> chars_frequency = {{s[left_pointer],1}};

        while(right_pointer < s.size()) {
            int max_frequency = 0;
            chars_frequency[s[right_pointer]]++;

            for (const auto& pair : chars_frequency) {
                if (pair.second > max_frequency) {
                    max_frequency = pair.second;
                }
            }

            while((right_pointer - left_pointer + 1) - max_frequency > k) {    //right_pointer - left_pointer + 1 => window length
                chars_frequency[s[left_pointer]]--;
                left_pointer++;
            }
   
            if(right_pointer - left_pointer + 1 > max_res)
                max_res = right_pointer - left_pointer + 1;

            right_pointer++;
        }

        return max_res;
    }
};





int main()
{
    Solution solution;
    int result;
    int k = 0;
    string s = "ABAA";

    result = solution.characterReplacement(s,k);

    cout << "Result: " << result << endl;    


    return 0;
}