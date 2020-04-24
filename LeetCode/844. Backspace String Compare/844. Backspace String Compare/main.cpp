/*
 
 Given two strings S and T, return if they are equal when both are typed into empty text editors. # means a
 backspace character.
 
 Note that after backspacing an empty text, the text will continue empty.
 
 Input: S = "ab#c", T = "ad#c"
 Output: true
 Explanation: Both S and T become "ac".
 
 Input: S = "ab##", T = "c#d#"
 Output: true
 Explanation: Both S and T become "".
 
 Input: S = "a#c", T = "b"
 Output: false
 Explanation: S becomes "c" while T becomes "b".
 
 */

#include <iostream>
#include <string>
using namespace std;

bool backspaceCompare(string S, string T) {
    for(int i=0; i<S.size(); i++){
        if(S[0]=='#'){
            S.erase(0,1);
            continue;
        }
        else if(S[i]=='#'){
            S.erase(i-1,2);
            i-=2;
        }
    }
    for(int i=0; i<T.size(); i++){
        if(T[0]=='#'){
            T.erase(0,1);
            i--;
            continue;
        }
        else if(T[i]=='#'){
            T.erase(i-1,2);
            i-=2;
        }
    }
    return (S == T);
}

int main() {
    string a = "a#c", b = "b";
    cout<<backspaceCompare(a, b)<<endl;
    return 0;
}
