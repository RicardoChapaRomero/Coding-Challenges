//
//  main.cpp
//  1417. Reformat The String
//
//  Created by Ricardo Abraham Chapa Romero on 20/04/20.
//  Copyright © 2020 Ricardo Abraham Chapa Romero. All rights reserved.
//

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
