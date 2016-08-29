#include <stdio.h>
#include <algorithm>
using namespace std;

int n, m, x, y;

int check(int have){
	return have - have/x >= n
		&& have - have/y >= m
		&& have - have/x - have/y + have/(x*y) >= n+m - (n+m)/x - (n+m)/y + (n+m)/(x*y);
}

int bsearch(long long l, long long r){
	while(l<=r){
		int mid = (l+r)/2;
		if(check(mid)) r = mid-1;
		else l = mid+1;
	}
	return l;
}

int main(){
	while(scanf("%d%d%d%d",&n,&m,&x,&y)!=EOF)
		printf("%d\n",bsearch(1, 2000000000));
	return 0;
}
