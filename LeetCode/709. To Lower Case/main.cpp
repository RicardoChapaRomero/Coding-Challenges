/*
    Implement function ToLowerCase() that has a string parameter str, and returns the same string in lowercase.
 */

#include <iostream>
#include <string>
using namespace std;

string toLowerCase(string str) {
       for(int i=0; i<str.length(); i++){
          str[i] = tolower(str[i]);
       }
       return str;
   }
int main() {
    string prob = "LOVELY";
    string sol = toLowerCase(prob);
    for(int i=0; i<sol.length();i++){
        cout<<sol[i];
    }
    return 0;
}
