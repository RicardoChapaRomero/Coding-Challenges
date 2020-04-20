/*
    In a array A of size 2N, there are N+1 unique elements, and exactly one of these elements is repeated N times.

    Return the element repeated N times.
 */

#include <iostream>
#include <vector>
#include <set>
using namespace std;

int repeatedNTimes(vector<int>& A) {
  set<int> nums;
    
    for(int i=0; i<A.size(); i++){
        if(nums.find(A[i])==nums.end()){
            nums.insert(A[i]);
        }
        else return A[i];
    }
    return -1;
}
int main() {
    vector<int> prob{1,2,3,3};
    cout<<repeatedNTimes(prob)<<endl;
    
    return 0;
}
