/*
       Given a valid (IPv4) IP address, return a defanged version of that IP address.

        A defanged IP address replaces every period "." with "[.]".
 */

#include <iostream>
#include <string>
using namespace std;

string defangIPaddr(string address) {
   string ipAdress;
   for(int i=0; i<address.length(); i++){
       if(isdigit(address[i])){
       ipAdress+=address[i];
       }
       else{
           ipAdress+="[.]";
       }
   }
   return ipAdress;
}
int main() {
    string prob = "1.1.1.1";
    string sol = defangIPaddr(prob);
    for(int i=0; i<sol.length(); i++){
        cout<<sol[i];
    }
    cout<<endl;
    return 0;
}
