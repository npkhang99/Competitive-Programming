// HackerRank - Weef of Code 27 - Drawing Book
#include <iostream>
using namespace std;

int n, k;

int main(){
    cin>> n>> k;
    int front = 0, back = (n%2 == 0? n:n-1), ans1=0, ans2=0;
    for(; k-front > 1; front+=2, ans1++);
    for(; k-back < 0; back-=2, ans2++);
    cout<< (ans1 < ans2? ans1:ans2)<< endl;
    return 0;
}
