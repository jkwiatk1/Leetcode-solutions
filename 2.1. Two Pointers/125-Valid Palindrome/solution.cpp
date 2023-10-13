#include <iostream>
#include <string>
#include <cctype>

using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        string tmp = "";

        for(char c : s){
            if(isalnum(c)) {
                tmp += tolower(c); 
            }
        }

        const char* ptr_begin = tmp.c_str();
        const char* ptr_end = ptr_begin + tmp.size() - 1;
        cout << *ptr_begin << "  " << *ptr_end << endl; 


        while (*ptr_begin) {
            if(*ptr_begin != *ptr_end) return false;
            cout << *ptr_begin << "  " << *ptr_end << endl; 
            ptr_begin++;
            ptr_end--; 
        }
        return true;
    }
};

int main()
{
    Solution solution;
    bool result;
    string s = "A man, a plan, a canal: Panama";
    result = solution.isPalindrome(s);

    cout << "Result: " << result << endl;

    return 0;
}