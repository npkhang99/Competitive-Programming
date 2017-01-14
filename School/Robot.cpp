#include <bits/stdc++.h>
using namespace std;

const int N = 3e5 + 9;

int n, m, x[N]={}, y[N]={}, c_x = 0, c_y = 0;
char s[N]={};

void move(int& x, int& y, char ch){
    if(ch == 'S') y++;
    else if(ch == 'J') y--;
    else if(ch == 'I') x++;
    else x--;
}

long long complete(){
    long long dist = 0;
    for(int i=0; i<n; i++)
        dist += abs(c_x - x[i]) + abs(c_y - y[i]);
    return dist;
}

long long vertical(int factor){
    int p = (factor == 1? lower_bound(y, y+n+1, c_y):upper_bound(y, y+n+1, c_y)) - y;
    // cerr<< p<< " ";
    return (n-p - p)*factor;
}

long long horizontal(int factor){
    int p = (factor == 1? lower_bound(x, x+n+1, c_x):upper_bound(x, x+n+1, c_x)) - x;
    // cerr<< p<< " ";
    return (n-p - p)*factor;
}

int main(){
    // freopen("Robot.inp","r",stdin);
    // freopen("Robot.out","w",stdout);
    scanf("%d %d",&n,&m);
    for(int i=0; i<n; i++)
        scanf("%d %d ",&x[i],&y[i]);
    scanf("%s",s);
    
    long long dist = 0;
    c_x = c_y = 0;
    for(int i=0; i<n; i++)
        dist += abs(x[i]) + abs(y[i]);
    sort(x, x+n);
    sort(y, y+n);
    x[n] = y[n] = 1000009;
    // cerr<< "Initial distance: "<< dist<< endl;
    for(int i=0; i<m; i++){
        // cerr<< c_x<< " "<< c_y<< " -> ";
        // fprintf(stderr, "%3d%3d -> ", c_x,c_y);
        
        // fprintf(stderr, "%3d%3d - ", c_x,c_y);
        if(s[i] == 'I' || s[i] == 'Z')
            // cerr<< "Goes horizontal - ",
            dist += horizontal(s[i] == 'I'? -1:1);
        else
            // cerr<< "Goes vertical   - ",
            dist += vertical(s[i] == 'S'? -1:1);
        move(c_x,c_y,s[i]);
        // fprintf(stderr, "%3lld - ", complete());
        printf("%lld\n",dist);
    }
    // cerr<< endl;
    return 0;
}
