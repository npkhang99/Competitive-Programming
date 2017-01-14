#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string>
using namespace std;

const int N=100009;

int n, a[N]={}, cnt=0, c[N]={}, p[300]={};
bool b[300]={};
string st;

int main(){
    ios::sync_with_stdio(false);
    cin>> n>> st;
    for(int i=0; i<n; c[i++]=cnt)
        if(!b[st[i]]) b[st[i]]=true, cnt+=1;
    if(cnt<3){ printf("%d\n",cnt); return 0; }
    
    // let tmp is the number of different letters that occur in the current
    // sub-string, l is the left pointer, r is the right pointer and p[] is
    // the letter counter
    int l=-1, r=-1, tmp=0;
    // get the right pointer to the fist position that
    // all the letters in the given string occur (tmp equals cnt)
    while(tmp<cnt){
        p[st[++r]]+=1;
        if(p[st[r]]==1) tmp+=1;
    }
    // current answer is r+1 (0 indexed)
    int ans = r+1;
    // while the right pointer not reached the end of the string, do 2 things
    // 1. check that if we increase the left pointer will make
    //    the sub-string still have all the letters in the given string
    //    if yes, then increase it til' we can't increase it anymore and
    //    if not then don't
    // 2. update the answer and increase the right pointer by 1
    while(r<n-1){
        while(p[st[l+1]]-1>0) p[st[++l]]-=1;
        ans=min(ans,r-l);
        p[st[++r]]+=1;
    }
    // if the right pointer reached the end, we still need to check
    // whether we increase the left pointer will make the sub-string
    // met the problem's condition or not and then update the final answer
    while(p[st[l+1]]-1>0) p[st[++l]]-=1;
    ans=min(ans,r-l);

    printf("%d\n",ans);
    return 0;
}
