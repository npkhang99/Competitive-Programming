#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> ii;

const int N = 1009;

int n, A, B, D, b[N]={};
long long ans = 10E17, memo[N][10009] = {};
ii a[N]={};

int f(int startTime, int p){
    return abs((startTime + a[p].first) - D) * a[p].second;
}

// subtask 1 + 2
void sub2(int i, int time, long long cost){
    if(i == n){
        ans = min(ans, cost);
        return;
    }
    for(int j=0; j<n; j++)
        if(!b[j]){
            b[j] = 1;
            sub2(i+1, time + a[j].first, cost + f(time,j));
            b[j] = 0;
        }
}

void subtask2(){
    int totalNeed = 0;
    for(int i=0; i<n; i++)
        totalNeed += a[i].first;

    for(int i=A; i<=B - totalNeed; i++)
        for(int j=0; j<n; j++){
            b[j] = 1;
            sub2(1, i+a[j].first, f(i,j));
            b[j] = 0;
        }
    printf("%lld\n",ans);
}

// subtask 3
int comp(ii a, ii b){
    return ((double)(a.second) / (double)(a.first)) > ((double)(b.second) / (double)(b.first));
}

void subtask3(){
    ans = 0;
    sort(a,a+n,comp);
    for(int i=0, time = D; i<n; time+=a[i++].first){
        ans += f(time,i);
    }
    printf("%lld\n",ans);
}

// subtask 4
void subtask4(){
    ans = 0;
    sort(a,a+n,comp);
    for(int i=0, time = D; i<n; time-=a[i++].first){
        ans += f(time-a[i].first,i);
    }
    printf("%lld\n",ans);
}

// subtask 5 + 6
void arrange(int i, int t1, int t2, long long cost){
    if(i == n){
        ans = min(ans, cost);
        return;
    }
    if(t1 - a[i].first >= A) arrange(i+1, t1-a[i].first,            t2, cost + f(t1-a[i].first,i));
    if(t2 + a[i].first <= B) arrange(i+1,            t1, t2+a[i].first, cost + f(t2,i));
}

void subtask6(){
    ans = 10E17;
    sort(a,a+n,comp);
    for(int i=max(A,D-100); i<=min(D+100,B-a[0].first); i++)
        arrange(1,i,i+a[0].first,f(i,0));
    printf("%d\n",ans);
}

// subtask 7 (can use for all subtasks)
long long arrange7(int i, int t1, int t2){
    if(i == n) return 0;
    if(memo[i][t1] != -1) return memo[i][t1];
    long long temp = 10E17;
    if(t1 - a[i].first >= A) temp = min(temp, arrange7(i+1, t1-a[i].first,            t2) + f(t1-a[i].first,i));
    if(t2 + a[i].first <= B) temp = min(temp, arrange7(i+1,            t1, t2+a[i].first) + f(t2,i));
    return memo[i][t1] = temp;
}

void subtask7(){
    ans = 10E17;
    sort(a,a+n,comp);
    memset(memo, -1, sizeof memo);
    for(int i = max(A,D-100); i <= min(D+100,B-a[0].first); i++){
        ans = min(ans, arrange7(1,i,i+a[0].first) + f(i,0));
    }
    printf("%lld\n",ans);
}

int main(){
    // freopen("DBG.inp","r",stdin);
    // freopen("DBG.out","w",stdout);
    scanf("%d%d%d%d",&n,&A,&B,&D);
    for(int i=0; i<n; i++)
        scanf("%d%d",&a[i].first,&a[i].second);
    if(n <= 8) subtask2();
    else if(A == D) subtask3();
    else if(D == B) subtask4();
    else if(n <= 20) subtask6();
    else subtask7();
    return 0;
}
