/*
 Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.
 
 push(x) -- Push element x onto stack.
 pop() -- Removes the element on top of the stack.
 top() -- Get the top element.
 getMin() -- Retrieve the minimum element in the stack.
 
 */

#include <iostream>
#include <vector>
using namespace std;

class MinStack {
public:
    vector<int> nums;
    int min;
    int pastMin;
    /* initialize your data structure here. */
    MinStack() {
        min = INT_MAX;
        pastMin = INT_MAX;
    }
    
    void push(int x) {
        if(min == INT_MAX) min = x;
        else if(x <= min){
            pastMin = min;
            min = x;
        }
        nums.push_back(x);
    }
    
    void pop() {
        nums.pop_back();
        
        min = INT_MAX;
        pastMin = INT_MAX;
        for(int i=0; i<nums.size(); i++){
            if(nums[i] <= min){
                pastMin = min;
                min = nums[i];
            }
        }
        
        cout<<pastMin<<endl;
    }
    
    int top() {
        return nums[nums.size()-1];
    }
    
    int getMin() {
        return min;
    }
};



int main() {
   /* MinStack* obj = new MinStack();
    obj->push(1);
    obj->pop();
    int param_3 = obj->top();
    int param_4 = obj->getMin();*/
    
    return 0;
}
