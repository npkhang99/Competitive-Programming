#include <iostream>
#include <stdio.h>
using namespace std;

const int N=109;

int n, a[N][N];

int main(){
    cin>> n;
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++){
            char ch; cin>> ch;
            a[i][j]=(int)ch;
        }
    long long ans=0;
    for(int i=0; i<n; i++){
        int t1=0,t2=0;
        for(int j=0; j<n; j++){
            if(a[i][j]==(int)'C') t1+=1;
            if(a[j][i]==(int)'C') t2+=1;
        }
        ans+=t1*(t1-1)/2 + t2*(t2-1)/2;
    }
    cout<< ans;
    return 0;
}