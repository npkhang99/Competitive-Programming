// Finding the minimum element in every window of size K in an array size N using deque (Double-Ended Queue)
#include <iostream>
#include <stdio.h>	// printf scanf freopen
#include <deque>	// deque empty front back pop_back pop_front push_back
using namespace std;

const int N=500009;

int n, a[N], k;
deque<int> deQ;

int main(){
	scanf("%d %d\n",&n,&k);
	for(int i=0; i<n; i++) scanf("%d",&a[i]);
	int i=0;
	for(; i<k; i++){
		// if the current element is smaller than the rear element then the rear element
		// is useless so remove it
		while(!deQ.empty() && a[i]<=a[deQ.back()]) deQ.pop_back();
		// put the current element at rear of the queue
		deQ.push_back(i);
	}
	for(; i<n; i++){
		// the front element of the queue is the smallest element of the previous window
		// so print it
		printf("%d\n",a[deQ.front()]);
		// if the front element of the queue is out-of-date (out of the window size)
		// then remove it
		while(!deQ.empty() && deQ.front()<=i-k) deQ.pop_front();
		// remove useless elements from the rear (like above)
		while(!deQ.empty() && a[i]<=a[deQ.back()]) deQ.pop_back();
		// put the current element at rear of the queue
		deQ.push_back(i);
	}
	// print out the answer for the last window
	printf("%d\n",a[deQ.front()]);
	return 0;
}
