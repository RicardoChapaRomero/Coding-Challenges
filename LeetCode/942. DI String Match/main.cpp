/*
  Given a string S that only contains "I" (increase) or "D" (decrease), let N = S.length.

    Return any permutation A of [0, 1, ..., N] such that for all i = 0, ..., N-1:

    If S[i] == "I", then A[i] < A[i+1]
    If S[i] == "D", then A[i] > A[i+1]
 */

#include <iostream>
#include <vector>
using namespace std;

vector<int> diStringMatch(string S) {
    vector<int> res;
    int add=0;
    int less=S.length();
    
    for(int i=0; i<=S.length(); i++){
       if(S[i]=='I'){
           res.push_back(add);
           add++;
       }
        else{
            res.push_back(less);
            less--;
        }
    }
    return res;
}

int main() {
    string prob = "IDID";
    vector<int> sol = diStringMatch(prob);
    for(int i=0; i<sol.size(); i++){
        cout<<sol[i]<<" ";
    }
    cout<<endl;
    return 0;
}
