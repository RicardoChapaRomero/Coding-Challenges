//
//  main.cpp
//  1418. Display Table of Food Orders in a Restaurant
//
//  Created by Ricardo Abraham Chapa Romero on 20/04/20.
//  Copyright © 2020 Ricardo Abraham Chapa Romero. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
using namespace std;
vector<vector<string>> displayTable(vector<vector<string>>& orders) {
    vector< vector<string> > ans;
    map<int,map<string,int>> tables;
    set<string> food;
    for(int i=0; i<orders.size(); i++){
        tables[stoi(orders[i][1])][orders[i][2]]++;
        food.insert(orders[i][2]);
    }
    ans.push_back(vector<string>());
    ans[0].push_back("Table");
    for(set<string>::iterator it = food.begin(); it != food.end(); it++){
        ans[0].push_back(*it);
    }
    int i=1;
    for(map<int, map<string,int>>::iterator it = tables.begin(); it != tables.end(); it++,i++){
        ans.push_back(vector<string>());
        ans[i].push_back(to_string(it->first));
        for(set<string>::iterator f = food.begin(); f != food.end(); f++){
            ans[i].push_back(to_string(it->second[*f]));
        }
    }
    return ans;
}
int main() {
    vector<vector<string>> prob {
        {"David","3","Ceviche"},
        {"Corina","10","Beef Burrito"},
        {"David","3","Fried Chicken"},
        {"Carla","5","Water"},
        {"Carla","5","Ceviche"},
        {"Rous","3","Ceviche"}
    };
    vector<vector<string>> res = displayTable(prob);
    for(int i=0; i<res.size(); i++){
        for(int j=0; j<res[i].size(); j++){
            cout<<res[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
