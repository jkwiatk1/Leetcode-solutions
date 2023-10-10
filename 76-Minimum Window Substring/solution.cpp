#include <iostream>
#include <string>
#include <map>

using namespace std;

class Solution {
    int best_j;
    int best_i;
    int minLen;
    int freqT_size;
    int freqS_size;


public:
    string minWindow(string s, string t) {
        if(s.size() < t.size()) return "";

        int i=0, j=0;
        freqS_size = 0;
        best_i = i;
        best_j = s.size();
        minLen = INT_MAX;
        
        map<char,int> freqS = {};
        map<char,int> freqT = {};

        for(char c: t) {freqT[c]++;}
        freqT_size = freqT.size();
        

        while(j < s.size()){
            freqS[s[j]]++;         
            if(freqT.find(s[j]) != freqT.end() && freqS[s[j]] == freqT[s[j]]){     //true if s[j] is in freqT and s[j] freqs in maps are equal 
                freqS_size++;
            }
            
            while(freqS_size==freqT_size){        //true if freqS contains all necessary elements
                if(j - i <= best_j - best_i) {    //true if new window is shorter
                    best_j = j;
                    best_i = i;
                    minLen = best_j - best_i;
                }
                freqS[s[i]]--;
                if(freqT.find(s[i]) != freqT.end() && freqS[s[i]] < freqT[s[i]])     //true if s[i] is in freqT and s[i] freq is less in freqS then in freqT
                    freqS_size--;
                i++;    
            }
            j++;
        }

        if(minLen == INT_MAX) return "";

        return s.substr(best_i, best_j - best_i + 1);
    }
};



int main()
{
    Solution solution;
    string result;
    string s1 = "ADOBECODEBANC";
    string s2 = "ABC";

    result = solution.minWindow(s1,s2);

    cout << "Result: " << result << endl;    


    return 0;
}