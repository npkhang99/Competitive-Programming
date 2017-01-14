#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

typedef pair<int,int> ii;

const int N=109;

int n, k;
ii a[N];

int main(){
    cin>> n>> k;
    for(int i=0; i<n; i++){
        cin>> a[i].first;
        a[i].second = i+1;
    }
    a[n].first = 10E8;
    sort(a,a+n);
    int cnt=0, days=0;
    while(days+a[cnt].first<=k) days+=a[cnt++].first;
    printf("%d\n",cnt);
    for(int i=0; i<cnt; i++) printf("%d ",a[i].second);
    return 0;
}
