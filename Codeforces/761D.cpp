#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> ii;

const int N = 100009;

int n, l, r, a[N]={}, b[N]={}, c[N]={};
ii p[N]={};

int calc(int first, int second){
    if(first >= second) return first;
    else return second - first;
}

int main(){
    scanf("%d%d%d", &n, &l, &r);

    if(n > r - l + 1){
        printf("-1\n");
        return 0;
    }

    for(int i=0; i<n; i++)
        scanf("%d",&a[i]);
    for(int i=0; i<n; i++){
        scanf("%d",&p[i].first);
        p[i].second = i;
    }

    sort(p, p+n);
    // cerr<< a[p[0].second]<< " "<< *min_element(a,a+n)<< endl;
    // int curr = l - a[p[0].second] + (*min_element(a,a+n) < a[p[0].second]? (a[p[0].second] - *min_element(a,a+n)):0);
    // for(int i=0; i<n; i++)
    //     c[p[i].second] = curr++;

    int curr = r - a[p[n-1].second] - calc(a[p[n-1].second], *max_element(a,a+n));
    for(int i=n-1; i>=0; i--)
        c[p[i].second] = curr--;

    for(int i=0; i<n; i++)
        cerr<< c[i]<< " "; cerr<< endl;

    for(int i=0; i<n; i++){
        b[i] = a[i] + c[i];
        cerr<< b[i]<< " ";
        if(b[i] < l|| r < b[i]){
            cerr<< endl; printf("-1\n");
            return 0;
        }
    } cerr<< endl;

    for(int i=0; i<n; i++)
        printf("%d%c", b[i], i < n-1? ' ':'\n');
    return 0;
}
