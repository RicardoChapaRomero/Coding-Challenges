//
//  main.cpp
//  202. Happy Number
//
//  Created by Ricardo Abraham Chapa Romero on 22/04/20.
//  Copyright © 2020 Ricardo Abraham Chapa Romero. All rights reserved.
//

#include <iostream>
#include <math.h>
#include <set>
using namespace std;
bool isHappy(int n) {
    long long temp = 0;
    set<long long> reps;
    while(temp != 1){
        temp = 0;
        if(temp > LONG_MAX){
            return false;
        }
        else{
            while(n){
                temp += pow(n%10, 2);
                n/=10;
            }
            if(temp == 1) return true;
            if(reps.find(temp) == reps.end()) reps.insert(temp);
            else return false;
        }
        n = temp;
    }
    return true;
}

int main() {
    cout<<isHappy(134)<<endl;
    return 0;
}
