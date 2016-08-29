#include <iostream>
#include <algorithm>
using namespace std;

#define long long long

long n, a, b, c;

long bs(long l, long r){
    while(l<=r){
        long j = (l+r)/2LL;
        if(n-j*(b-c)<c) r=j-1;
        else l=j+1;
    }
	return r+max(0LL,(n-(b-c)*r)/a);
}

void xuly(){
	long count=0;
	if(a<=b-c) count=n/a;
	else count=bs(1,n/(b-c)+1);
	cout<< count<< endl;
}

int main(){
    cin>> n>> a>> b>> c;
	xuly();
	return 0;
}
