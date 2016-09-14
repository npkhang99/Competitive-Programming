#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;

int n, m;
string st1, st2;

int main(){
    while(getline(cin,st1)){
        getline(cin,st2);
        n = m = 0;
        for(int i=0; i<st1.size(); i++)
            if(isupper(st1[i])) n+=st1[i]-'A'+1;
            else if(islower(st1[i])) n+=st1[i]-'a'+1;
        for(int i=0; i<st2.size(); i++)
            if(isupper(st2[i])) m+=st2[i]-'A'+1;
            else if(islower(st2[i])) m+=st2[i]-'a'+1;
        if(n%9==0) n=9;
        else n%=9;
        if(m%9==0) m=9;
        else m%=9;
        if(n>m) swap(n,m);
        printf("%.2f %\n",n*100.0/m);
    }
    return 0;
}