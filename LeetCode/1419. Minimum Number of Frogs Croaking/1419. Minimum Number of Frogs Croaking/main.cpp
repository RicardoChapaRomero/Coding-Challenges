//
//  main.cpp
//  1419. Minimum Number of Frogs Croaking
//
//  Created by Ricardo Abraham Chapa Romero on 20/04/20.
//  Copyright © 2020 Ricardo Abraham Chapa Romero. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
using namespace std;

int minNumberOfFrogs(string croakOfFrogs) {
    /*vector<string> frogs;
    bool chars[26] = { 0 };
    int Cs=0, maxCs = 0;
    for(int i=0; i<croakOfFrogs.size(); i++){
        int index = croakOfFrogs[i] - 'a';
        chars[index] = !chars[index];
        
        if(croakOfFrogs[i] == 'c'){
            Cs++;
            if(Cs > maxCs) maxCs = Cs;
        }
        else if(croakOfFrogs[i] == 'k') Cs--;
    }
    for(int i=0; i<26; i++){
        if(chars[i]) return -1;
    }*/
    
    bool isComplete = true;
    int Cs=0, maxCs = 0;
    int lastC = 0;
    string example = "croak";
    int eC = 0;
   while(isComplete){
       isComplete = false;
       string compare = "";
       int j=0;
       for(int i=0; i<croakOfFrogs.size(); i++){
           if(compare == example || compare.size() > example.size()) break;
           if(croakOfFrogs[i] == example[j]) {
               compare += croakOfFrogs[i];
               croakOfFrogs.erase(i,1);
               j++;
               i--;
           }
           else{
               if(croakOfFrogs[i] == 'c'){
                   if(i > lastC){
                       lastC = i;
                       Cs++;
                   }
               }
           }
       }
       if(compare != example) return -1;
       if(compare == example){
           isComplete = true;
           maxCs =  1;
       }
       if(croakOfFrogs.size() == 0)
           return maxCs + Cs;
    }
    return -1;
}

int main() {
    cout<<minNumberOfFrogs("crocracokrakoak")<<endl;
    return 0;
}
