#include <iostream>
#include <string>

class Solution {
public:
    int longestPalindrome(std::string& s) {
        std::string reversed = reverseString(s);
        //find longest common substring
        int max_len = 0;
        int current_len = 0;
        std::string sol;
        for(int start=0; start<s.size();start++){
            for(int right = 0; right<s.size(); right++){
                if(IsPolindrome(s.substr(start,right-start+1))){
                    if(right-start+1 > max_len){
                        max_len = right-start+1;
                    }
                }
            }
        }
        return max_len;
    }

    bool IsPolindrome(const std::string& str){
        std::string reversed = reverseString(str);
        for(int i=0; i<str.size();i++){
            if(str[i] != reversed[i]){
                return false;
            }
        }
        return true;
    }

    std::string reverseString(const std::string& s){
        std::string reversed(s);
        for(int i=0; i<s.size(); i++){
            reversed[s.size()-i-1] = s[i];
        }
        return reversed;
    }
};

int main(){
    std::string str1("ababacccbd"); //5 "ababa"
    std::string str2("ababcccbad"); //7 "abcccba"
    std::string str3("abwdcefbad"); //1
    Solution s;
    int result = s.longestPalindrome(str1);
    result = s.longestPalindrome(str2);
    result = s.longestPalindrome(str3);

    return 0;
}