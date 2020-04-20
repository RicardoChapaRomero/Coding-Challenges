/*
 There are n people whose IDs go from 0 to n - 1 and each person belongs exactly to
 one group. Given the array groupSizes of length n telling the group size each person
 belongs to, return the groups there are and the people's IDs each group includes.
 
 You can return any solution in any order and the same applies for IDs. Also, it is
 guaranteed that there exists at least one solution.
 
 
 //////// Test Cases //////////
 
 Input: groupSizes = [3,3,3,3,3,1,3]
 Output: [[5],[0,1,2],[3,4,6]]
 
 Input: groupSizes = [2,1,3,3,3,2]
 Output: [[1],[0,5],[2,3,4]]
 
 */

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
    unordered_map<int,int> combs;
    vector<vector<int>> res;
    int j=1;
    for(int i=0; i<groupSizes.size(); i++){
        if(!combs[groupSizes[i]]){
            combs[groupSizes[i]] = j;
            res.push_back(vector<int>{i});
            j++;
        }
        else{
            if(res[combs[groupSizes[i]] -1].size() == groupSizes[i]){
                combs[groupSizes[i]] = j;
                j++;
                res.push_back(vector<int>{i});
            }
            else{
                 res[combs[groupSizes[i]] -1].push_back(i);
            }
        }
        
    }
    return res;
}

int main() {
    vector<int> groupSizes = {2,1,3,3,3,2};
    vector<vector<int>> res = groupThePeople(groupSizes);
    for(vector<vector<int>>::iterator it = res.begin(); it != res.end(); it++){
        for(vector<int>::iterator col = (*it).begin(); col != (*it).end(); col++){
            cout<<(*col)<<" ";
        }
        cout<<endl;
    }
    return 0;
}
