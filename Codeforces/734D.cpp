#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair<int,int> ii;
typedef pair<ii,char> cii;

#define type second
#define x first.first
#define y first.second

const int N = 500009;

int n;
cii king, a[N];
vector<cii> ver, hor, mdiag, sdiag;

int comp_y(cii a, cii b){
    swap(a.x,a.y); swap(b.x,b.y);
    return a < b;
}

void checkVertical(int prev, int next, int size){
    if((prev >= 0 && ver[prev].type != 'B') || (next < size && ver[next].type != 'B')){
        printf("YES\n");
        exit(0);
    }
}

void checkHorizontal(int prev, int next, int size){
    if((prev >= 0 && hor[prev].type != 'B') || (next < size && hor[next].type != 'B')){
        printf("YES\n");
        exit(0);
    }
}

void checkMainDiagonal(int prev, int next, int size){
    if((prev >= 0 && mdiag[prev].type != 'R') || (next < size && mdiag[next].type != 'R')){
        printf("YES\n");
        exit(0);
    }
}

void checkSecondaryDiagonal(int prev, int next, int size){
    if((prev >= 0 && sdiag[prev].type != 'R') || (next < size && sdiag[next].type != 'R')){
        printf("YES\n");
        exit(0);
    }
}

int main(){
    scanf("%d %d %d ",&n,&king.x,&king.y);
    king.type = 'K';
    ver.push_back(king);
    hor.push_back(king);
    mdiag.push_back(king);
    sdiag.push_back(king);
    for(int i=0; i<n; i++){
        scanf("%c %d %d ",&a[i].type,&a[i].x,&a[i].y);
        if(a[i].x == king.x) ver.push_back(a[i]);
        if(a[i].y == king.y) hor.push_back(a[i]);
        if(a[i].x - a[i].y == king.x - king.y) mdiag.push_back(a[i]);
        if(a[i].x + a[i].y == king.x + king.y) sdiag.push_back(a[i]);
    }
    
    sort(ver.begin(),ver.end(),comp_y);
    for(int i=0; i<ver.size(); i++)
        if(ver[i].type == 'K'){
            checkVertical(i-1, i+1, ver.size());
            break;
        }

    sort(hor.begin(),hor.end());
    for(int i=0; i<hor.size(); i++)
        if(hor[i].type == 'K'){
            checkHorizontal(i-1, i+1, hor.size());
            break;
        }

    sort(mdiag.begin(),mdiag.end());
    for(int i=0; i<mdiag.size(); i++)
        if(mdiag[i].type == 'K'){
            checkMainDiagonal(i-1, i+1, mdiag.size());
            break;
        }

    sort(sdiag.begin(),sdiag.end());
    for(int i=0; i<sdiag.size(); i++)
        if(sdiag[i].type == 'K'){
            checkSecondaryDiagonal(i-1, i+1, sdiag.size());
            break;
        }

    printf("NO\n");
    return 0;
}
