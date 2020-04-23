//
//  main.cpp
//  X. Counting Elements
//
//  Created by Ricardo Abraham Chapa Romero on 22/04/20.
//  Copyright © 2020 Ricardo Abraham Chapa Romero. All rights reserved.
//

#include <iostream>
#include <vector>
#include <set>
#include <unordered_map>

using namespace std;

int countElements(vector<int>& arr) {
    set<int> nums;
    unordered_map<int,int> reps;
    int res=0;
    for(int i=0; i<arr.size(); i++){
        nums.insert(arr[i]);
        reps[arr[i]+1]++;
    }
    for(int i=0; i<arr.size(); i++){
        int n = (arr[i] + 1);
        if(nums.find(n) != nums.end()){
                res++;
            }
    }
    return res;
}

int main() {
    vector<int> nums {1,1,2};
    cout<<countElements(nums)<<endl;
    return 0;
}
