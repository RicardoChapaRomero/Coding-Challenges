/*
    Let's call an array A a mountain if the following properties hold:

    A.length >= 3
    There exists some 0 < i < A.length - 1 such that A[0] < A[1] < ... A[i-1] < A[i] > A[i+1] > ... > A[A.length - 1]
 */

#include <iostream>
#include <vector>
using namespace std;

int peakIndexInMountainArray(vector<int>& A) {
    int l=0, r=A.size()-1;
    while(l<r){
        int mid = ((l+r)/2);
        if(A[mid]<A[mid+1]) l = mid+1;
        else r = mid;
    }
    return l;
}
int main() {
    vector<int> A{0,2,1,0};
    int sol = peakIndexInMountainArray(A);
    cout<<sol;
    cout<<endl;
    return 0;
}
