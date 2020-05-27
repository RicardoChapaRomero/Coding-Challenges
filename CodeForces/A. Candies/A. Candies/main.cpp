//
//  main.cpp
//  A. Candies
//
//  Created by Ricardo Abraham Chapa Romero ona 21/04/20.
//  Copyright © 2020 Ricardo Abraham Chapa Romero. All rights reserved.
//

#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
#include <string>
#include <set>
#include <stack>
#include <queue>
#include <map>

#define sync ios_base::sync_with_stdio(false); cin.tie(NULL); //cout.tie(NULL)

using namespace std;

long long getMultiplier(long long& n, long long& lastCommon){
    long long i=lastCommon;
    for(; i<n; i++){
        if(n%i == 0)
        {
            lastCommon = i+1;
            return n/i;
        }
    }
    return 1;
}
int main() {
    sync;
    int t=0;
    long long n=0;
    bool found = true;
    cin>>t;
    vector<int> tests(t);
    for(int i=0; i<t; i++){
        cin>>tests[i];
    }
    while(t--){
        long long sum=0;
        n = tests[tests.size()-t-1];
        long long lastCommon = 2;
        long long x = getMultiplier(n, lastCommon);
        int i=0;
        found = false;
        while( x != 1 && !found){
            long long p = (n/x)-1;
            while(sum <= n){
                if(p == 1) break;
                if(sum == n){
                    cout<<x<<endl;
                    found = true;
                    break;
                }
                sum += pow(2,p-i)*x;
                i++;
            }
            if(found) break;
            x = getMultiplier(n, lastCommon);
            sum = 0;
            i=0;
        }
        if(!found)cout<<1<<endl;
    }
    return 0;
}
