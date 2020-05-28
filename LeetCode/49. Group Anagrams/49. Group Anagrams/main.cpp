/*
 Given an array of strings, group anagrams together.
 
 Input: ["eat", "tea", "tan", "ate", "nat", "bat"],
 Output:
         [
         ["ate","eat","tea"],
         ["nat","tan"],
         ["bat"]
         ]
 
 */

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

vector<vector<string>> groupAnagrams(vector<string>& strs) {
    //pair<string,int> types;
    vector<vector<string>> res;
    int aux = 0;
    int y = 0;
    unordered_map<string, int> types;
    int n=0;
    for(int i=0; i<strs.size(); i++){
        string temp = strs[i];
        sort(temp.begin(), temp.end());
        if (types.find(temp) == types.end()){
            types[temp] = n;
            res.push_back(vector<string>());
            res[n].push_back(strs[i]);
            n++;
        }
        else{
            res[types[temp]].push_back(strs[i]);
        }
    }
    return res;
}

int main() {
    vector<string> strs {"eat", "tea", "tan", "ate", "nat", "bat"};
    vector<vector<string>> ans = groupAnagrams(strs);
    for(int i=0; i<ans.size(); i++){
        for(int j=0; j<ans[i].size(); j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
