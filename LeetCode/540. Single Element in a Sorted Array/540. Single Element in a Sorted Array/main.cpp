//
//  main.cpp
//  540. Single Element in a Sorted Array
//
//  Created by Ricardo Abraham Chapa Romero on 21/04/20.
//  Copyright © 2020 Ricardo Abraham Chapa Romero. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

int singleNonDuplicate(vector<int>& nums) {
    int init = 0, fin = (int)nums.size()-1;
    int mid = 0;
    while(init < fin){
        mid =  init + ((fin - init)/2);
        if(mid == 0){
            if(nums[mid] == nums[mid+1]) {
                init = mid+1;
                continue;
            }
            return nums[mid];
        }
        else if(mid == nums.size()-1){
            if(nums[mid] == nums[mid-1]){
                fin = mid-1;
                continue;
            }
            return nums[mid];
        }
        
        if(mid%2 == 0){
            if(nums[mid + 1] == nums[mid]){
                init = mid + 1;
            }
            else if(nums[mid - 1] == nums[mid]){
                fin = mid - 1;
            }
            else return nums[mid];
        }
        else{
            if(nums[mid - 1] == nums[mid]){
                init = mid + 1;
            }
            else if(nums[mid + 1] == nums[mid]){
                fin = mid - 1;
            }
        }
    }
    return nums[init];
}

int main() {
    vector<int> nums {0,1,1};
    cout<<singleNonDuplicate(nums)<<endl;
    return 0;
}
