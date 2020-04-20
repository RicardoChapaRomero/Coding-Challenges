/*
 Implement pow(x, n), which calculates x raised to the power n (x^n).
 
 //////////Test Cases//////////////
 Input:  2.00000, 10
 Output: 1024.00000
 
 Input:  2.10000, 3
 Output: 9.26100
 
 Input:  2.00000, -2
 Output: 0.25000
 
 
 */

#include <iostream>
#include <unordered_map>
using namespace std;


double getMinimum(double x, int n,const int num ,unordered_map<double,double>& dp){
    if(n != 1) {
        if(n%2 != 0){
            dp[n] = (getMinimum(x,(n-1)/2,num,dp)*x);
            if(n == num) return dp[n];
            dp[n*2] = dp[n] * dp[n];
            return dp[n*2];
        }
        dp[n] = getMinimum(x,n/2,num,dp);
        dp[n*2] = dp[n] * dp[n];
        return dp[n*2];
    }
    dp[1] = x;
    dp[2] = x*x;
    return dp[2];
}

double myPow(double x, int n) {
    bool isMin = false;
    if(n == 0) return 1;
    else if(n == 1) return x;
    else if(n == INT_MIN){
        n += 1;
        isMin = true;
    }
    
    int num = n;
    unordered_map<double,double> dp;
    if(n == 0) return 1;
    else if(n < 0){
        n *= -1;
        num *= -1;
        getMinimum(x,n,num,dp);
        if(isMin) return (1 /(dp[n]*x));
        return (1/dp[n]);
    }
    getMinimum(x,n,num,dp);
    return dp[n];
}

int main() {
    cout<<myPow(1, INT_MIN)<<endl;
    return 0;
}
