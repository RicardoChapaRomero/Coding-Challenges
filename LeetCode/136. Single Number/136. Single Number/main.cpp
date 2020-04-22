//
//  main.cpp
//  136. Single Number
//
//  Created by Ricardo Abraham Chapa Romero on 21/04/20.
//  Copyright © 2020 Ricardo Abraham Chapa Romero. All rights reserved.
//

#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int singleNumber(vector<int>& nums) {
    unordered_map<int,int> num;
    for(int i=0; i<nums.size(); i++){
        if(num[nums[i]] > 0)
            num[nums[i]]--;
        else
            num[nums[i]]++;
    }
    for(unordered_map<int,int>::iterator it = num.begin(); it != num.end(); it++){
        if(it->second != 0) return it->first;
    }
    return -1;
}

int main() {
    vector<int> nums {4,1,2,1,2};
    cout<<singleNumber(nums)<<endl;
    
    return 0;
}
