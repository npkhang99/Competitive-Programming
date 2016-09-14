#include <iostream>
#include <string>
using namespace std;

int n, s;
string  dpmin[109][909], dpmax[109][909];

string min(string a, string b){
    if(a.size()<b.size()) return a;
    if(a.size()>b.size()) return b;
    if(a<b) return a;
    return b;
}

string max(string a, string b){
    if(a.size()>b.size()) return a;
    if(a.size()<b.size()) return b;
    if(a>b) return a;
    return b;
}

void xuly(){
    for(int i=0; i<=10; i++) dpmin[1][i] = dpmax[1][i] = char(i+48);
    for(int i=2; i<=n; i++){
        dpmin[i][0] = dpmax[i][0] = "-1";
        for(int j=1; j<=s; j++)
            for(int k=1; k<=j; k++){
                for(int h=0; h<=9; h++)
                    if(k+h == j) { dpmin[i][j] = min(dpmin[i][k]+char(h+48), char(h+48)+dpmin[i][k]); break; }
                dpmax[i][j] = dpmin[i][j];
                for(int h=9; h>0; h--)
                    if(k+h == j) { dpmax[i][j] = max(char(h+48)+dpmax[i][k], dpmax[i][j]+char(h+48)); break; }
            }
    }
    cout<< dpmin[n][s]<< " "<< dpmax[n][s];
}

int main(){
    cin>> n>> s;
    xuly();
    return 0;
}