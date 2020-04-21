/*
 
 Given alphanumeric string s. (Alphanumeric string is a string consisting of
 lowercase English letters and digits).
 
 You have to find a permutation of the string where no letter is followed by another
 letter and no digit is followed by another digit. That is, no two adjacent
 characters have the same type.
 
 Return the reformatted string or return an empty string if it is impossible to
 reformat the string.
 
 //////////Test Cases/////////
 
 Input: s = "a0b1c2"
 Output: "0a1b2c"
 
 Input: s = "leetcode"
 Output: ""
 Explanation: "leetcode" has only characters so we cannot separate them by
                digits.
 
 Input: s = "covid2019"
 Output: "c2o0v1i9d"
 
 */

#include <iostream>
#include <stack>
#include <string>
using namespace std;

string reformat(string s) {
    stack<char> chars;
    stack<char> nums;
    string ans = "";
    if(s.size() == 1) return s;
    for(int i=0; i<s.size(); i++){
        bool isChar = isalpha(s[i]);
            if(isChar) chars.push(s[i]);
            else nums.push(s[i]);
    }
    if(nums.size() == 0 || chars.size() == 0) return ans;
    bool flag = nums.size() > chars.size();
    while(chars.size() != 0 || nums.size() != 0){
        if(flag){
            flag = false;
            if(nums.size() == 0) continue;
            ans += nums.top();
            nums.pop();
        }
        else {
            flag = true;
            if(chars.size() == 0) continue;
            ans += chars. top();
            chars.pop();
        }
    }
    return ans;
}

int main() {
    string ans = reformat("a0b1c2");
    cout<< ans<<endl;
    return 0;
}
