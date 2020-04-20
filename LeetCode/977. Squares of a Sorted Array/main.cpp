/*
        Given an array of integers A sorted in non-decreasing order, return an array of the squares of each number, also in sorted non-decreasing order.
 */

#include <iostream>
#include <vector>
using namespace std;

vector<int> sortedSquares(vector<int>& A) {
   for(int i=0; i<A.size(); i++){
       A[i] = (A[i]*A[i]);
   }
    sort(A.begin(), A.end());
    return A;
}
int main() {
    vector<int> prob{-4,-1,0,3,10};
    vector<int> sol = sortedSquares(prob);
    for(int i=0; i<sol.size(); i++){
        cout<<sol[i]<<" ";
    }
    cout<<endl;
    return 0;
}
