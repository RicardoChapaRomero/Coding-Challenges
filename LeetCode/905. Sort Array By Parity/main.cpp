/*
    Given an array A of non-negative integers, return an array consisting of all the even elements of A, followed by all the odd elements of A.

    You may return any answer array that satisfies this condition.
 */

#include <iostream>
#include <vector>
using namespace std;

vector<int> sortArrayByParity(vector<int>& A) {
   int le = 0;
   int ri = A.size()-1;
   
   while(le<ri){
       if(A[le]%2!=0 && A[ri]%2==0){
           swap(A[le], A[ri]);
           le++;
           ri--;
           continue;
       }
       if(A[le]%2!=0 && A[ri]%2!=0){
           ri--;
           continue;
       }
       if(A[le]%2==0 && A[ri]%2!=0){
           le++;
           continue;
       }
        if(A[le]%2==0 && A[ri]%2==0){
           le++;
           continue;
       }
   }
   return A;
}
int main() {
    vector<int> prob{3,1,2,4};
    prob = sortArrayByParity(prob);
    for(int i=0; i<prob.size(); i++){
        cout<<prob[i]<<" ";
    }
    return 0;
}
