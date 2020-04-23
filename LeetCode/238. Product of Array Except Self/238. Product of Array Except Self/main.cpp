/*
 Given an array nums of n integers where n > 1,  return an array output
 such that output[i] is equal to the product of all the elements of nums
 except nums[i].
 
 Input:  [1,2,3,4]
 Output: [24,12,8,6]
 
 Note: Please solve it without division and in O(n).
 
 */

#include <iostream>
#include <vector>
using namespace std;

vector<int> productExceptSelf(vector<int>& nums) {
    const int n = nums.size();
    vector<int> sufix(n);
    vector<int> postfix(n);
    vector<int> ans(n);
    int x = 1;
    for(int i=0; i<nums.size(); ++i){
        sufix[i] = x * nums[i];
        x*=nums[i];
    }
     x=1;
    for(int i=nums.size()-1; i>= 0; --i){
        postfix[i] = x * nums[i];
        x *= nums[i];
    }
    for(int i=0; i<nums.size(); i++){
        if(i == 0) {
            ans[0] = postfix[1];
            continue;
        }
        else if(i == nums.size()-1){
            ans[i] = sufix[i-1];
            continue;
        }
        else{
            ans[i] = sufix[i-1] * postfix[i+1];
        }
    }
    return ans;
}

int main() {
    vector<int> nums{1,2,3,4};
    vector<int> n =  productExceptSelf(nums);
    for(auto i : n){
        cout<<i<<" ";
    }
    return 0;
}
