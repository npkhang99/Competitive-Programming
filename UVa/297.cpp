#include <bits/stdc++.h>
using namespace std;

struct region{
    int left, right, top, bottom;

    //              childen region |        left         |      right       |         top          |     bottom       |
    region first(){  return region ((left+right) / 2 + 1 ,            right ,                  top , (top+bottom) / 2 ); }
    region second(){ return region (                left , (left+right) / 2 ,                  top , (top+bottom) / 2 ); }
    region third(){  return region (                left , (left+right) / 2 , (top+bottom) / 2 + 1 ,           bottom ); }
    region fourth(){ return region ((left+right) / 2 + 1 ,            right , (top+bottom) / 2 + 1 ,           bottom ); }

    void set(int l=0, int r=0, int t=0, int b=0){ left = l; right = r; top = t; bottom = b; }
    region child(int child_ID){
        switch(child_ID){
            case 1: return first();
            case 2: return second();
            case 3: return third();
            case 4: return fourth();
        }
    }

    region(int l, int r, int t, int b){ set(l,r,t,b); }
    region(){ set(); }
};

int T, n, a[39][39]={}, b[39][39]={}, c[39][39]={};
char fi[2048]={}, se[2048]={};

int merge(){
    int blacks = 0;
    for(int i=1; i<=32; i++){
        for(int j=1; j<=32; j++){
            c[i][j] = max(a[i][j],b[i][j]);
            if(c[i][j]) blacks+=1;
        }
    }
    return blacks;
}

void fill(int a[39][39], region fillRegion, int color, int pos){
    int l = fillRegion.left,
        r = fillRegion.right,
        t = fillRegion.top,
        b = fillRegion.bottom;

    for(int i=t; i<=b; i++)
        for(int j=l; j<=r; j++)
            a[i][j] = color;
}

int build(char* present, int a[39][39], int pos, region curr){
    int child = 1, i;
    if(present[pos] != 'p'){
        fill(a, curr, present[pos] == 'f', pos);
        return pos+1;
    }
    for(i=pos+1; child <= 4 && i < strlen(present); child++){
        if(present[i] == 'p'){
            i = build(present, a, i, curr.child(child));
            continue;
        }
        fill(a, curr.child(child), present[i] == 'f', i);
        i += 1;
    }
    return i;
}

int main(){
    scanf("%d",&T);
    while(T--){
        scanf("%s%s",fi,se);
        build(fi, a, 0, region(1,32,1,32));
        build(se, b, 0, region(1,32,1,32));
        int ans = merge();
        printf("There are %d black pixels.\n",ans);
    }
    return 0;
}
