#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair<int,int> ii;

const int N=3009;

int n, a[N];
vector<ii> v;

bool sorted(){
	for(int i=1; i<n; i++)
		if(a[i]<a[i-1]) return false;
	return true;
}

int main(){
	scanf("%d",&n);
	for(int i=0; i<n; i++) scanf("%d",&a[i]);
	if(sorted()){ printf("0\n"); return 0; }
	for(int i=0; i<n-1; i++){
		int pos=i;
		for(int j=i+1; j<n; j++)
			if(a[j]<a[pos]) pos=j;
		if(pos==i) continue;
		swap(a[i],a[pos]);
		v.push_back(ii(i,pos));
	}
	printf("%d\n",v.size());
	for(int i=0; i<v.size(); i++) printf("%d %d\n",v[i].first,v[i].second);
	return 0;
}
