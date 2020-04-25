/*
 We have a collection of stones, each stone has a positive integer weight.
 
 Each turn, we choose the two heaviest stones and smash them together.  Suppose the stones have
 weights x and y with x <= y.  The result of this smash is:
 
    If x == y, both stones are totally destroyed;
    If x != y, the stone of weight x is totally destroyed, and the stone of weight y has new weight
    y-x.
 At the end, there is at most 1 stone left.  Return the weight of this stone (or 0 if there are no
 stones left.)
 
 
 Input: [2,7,4,1,8,1]
 Output: 1
 Explanation:
 We combine 7 and 8 to get 1 so the array converts to [2,4,1,1,1] then,
 we combine 2 and 4 to get 2 so the array converts to [2,1,1,1] then,
 we combine 2 and 1 to get 1 so the array converts to [1,1,1] then,
 we combine 1 and 1 to get 0 so the array converts to [1] then that's the value of last stone.
 
 */

#include <iostream>
#include <vector>
using namespace std;

int lastStoneWeight(vector<int>& stones) {
    
    while(stones.size() > 1){
        int x=-1, y=-1, si=0, sj=0;
        for(int i=0; i<stones.size(); i++){
            if(stones[i] > y){
                if(y > x){
                    x = y;
                    sj = si;
                }
                y = stones[i];
                si = i;
                continue;
            }
            if(stones[i] > x){
                x = stones[i];
                sj = i;
                continue;
            }
        }
        int smash = y - x;
        if(smash == 0){
            if(si > sj){
                stones.erase(stones.begin()+sj);
                stones.erase(stones.begin()+sj-1);
            }
            else{
                stones.erase(stones.begin()+si);
                stones.erase(stones.begin()+sj-1);
            }
        }
        else{
            stones[si] = smash;
            stones.erase(stones.begin()+sj);
        }
    }
    if(stones.size() == 0) return 0;
    return stones[0];
}

int main() {
    vector<int> nums {2,2};
    cout<<lastStoneWeight(nums)<<endl;
    return 0;
}
