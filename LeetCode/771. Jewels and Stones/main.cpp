/*
       You're given strings J representing the types of stones that are jewels, and S representing the stones you have.  Each character in S is a type of stone you have.  You want to know how many of the stones you have are also jewels.

       The letters in J are guaranteed distinct, and all characters in J and S are letters. Letters are case sensitive, so "a" is considered a different type of stone from "A".
 */

#include <iostream>
#include <string>
using namespace std;

int numJewelsInStones(string J, string S) {
    int numJ = 0;
    for (int i=0; i< S.size(); i++)
    {
        for (int j=0; j< J.size(); j++)
        {
            if (J[j] == S[i])
            {
            numJ = numJ + 1;
            }
        }
    }
    return numJ;
}
int main() {
    string J = "aA";
    string S = "aAAbbbb";
    int sol = numJewelsInStones(J, S);
    cout<<sol<<endl;
    return 0;
}
