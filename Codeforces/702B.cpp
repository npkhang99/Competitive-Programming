#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <map>
#include <vector>
using namespace std;

const int N=100009;

int n, a[N];
vector<int> v;
map<int,long long> cnt;

int main(){
	scanf("%d",&n);
	for(int i=0; i<n; i++){
		scanf("%d",&a[i]);
		cnt[a[i]] += 1;
	}
	sort(a,a+n);
	v.push_back(a[0]);
	for(int i=1; i<n; i++)
		if(a[i]!=a[i-1]) v.push_back(a[i]);

	long long ans=0;
	for(int i=0; i<v.size(); i++){
		int k=1;
		while(k<v[i]) k*=2;
		for(; k<=v[i]+v[v.size()-1]; k*=2){
			int need = k-v[i];
			if(need>v[i]) break;
			if(cnt.find(need)!=cnt.end())
				if(need == v[i]) ans+=(cnt[need])*(cnt[need]-1)/2;
				else ans+=(cnt[need])*(cnt[v[i]]);
		}
	}
	printf("%I64d\n",ans);
	return 0;
}