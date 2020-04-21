/*
 
 Given the array orders, which represents the orders that customers have done in a restaurant. More specifically
 orders[i]=[customerNamei,tableNumberi,foodItemi] where customerNamei is the name of the customer, tableNumberi
 is the table customer sit at, and foodItemi is the item customer orders.
 
 Return the restaurant's “display table”. The “display table” is a table whose row entries denote how many of
 each food item each table ordered. The first column is the table number and the remaining columns correspond to
 each food item in alphabetical order. The first row should be a header whose first column is “Table”, followed
 by the names of the food items. Note that the customer names are not part of the table. Additionally, the rows
 should be sorted in numerically increasing order.
 
 
 /////////Test Cases//////////
 
 Input: orders = [["David","3","Ceviche"],["Corina","10","Beef Burrito"],["David","3","Fried
                 Chicken"],["Carla","5","Water"],["Carla","5","Ceviche"],["Rous","3","Ceviche"]]
 Output: [["Table","Beef Burrito","Ceviche","Fried
        Chicken","Water"],["3","0","2","1","0"],["5","0","1","0","1"],["10","1","0","0","0"]]
 Explanation:
         The displaying table looks like:
         Table,Beef Burrito,Ceviche,Fried Chicken,Water
         3    ,0           ,2      ,1            ,0
         5    ,0           ,1      ,0            ,1
         10   ,1           ,0      ,0            ,0
 
 Input: orders = [["James","12","Fried Chicken"],["Ratesh","12","Fried Chicken"],["Amadeus","12","Fried
                    Chicken"],["Adam","1","Canadian Waffles"],["Brianna","1","Canadian Waffles"]]
 Output: [["Table","Canadian Waffles","Fried Chicken"],["1","2","0"],["12","0","3"]]
 
 */

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
