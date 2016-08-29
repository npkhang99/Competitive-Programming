#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;

const int N=1009;

int n, m, cnt=0, dong[N]={}, cot[N]={};
string a[N];

int main(){
	scanf("%d%d\n",&n,&m);
	for(int i=0; i<n; i++) cin>> a[i];
	for(int i=0; i<n; i++)
		for(int j=0; j<m; j++)
			if(a[i][j]=='*'){
				dong[i] += 1;
				cot[j] += 1;
				cnt+=1;
			}
	if(cnt==0){ printf("YES\n1 1\n"); return 0; }
	for(int i=0; i<n; i++)
		for(int j=0; j<m; j++){
			int del = dong[i]+cot[j];
			if(a[i][j]=='*') del-=1;
			if(del==cnt){
				printf("YES\n%d %d\n",i+1,j+1);
				return 0;
			}
		}
	printf("NO\n");
	return 0;
}