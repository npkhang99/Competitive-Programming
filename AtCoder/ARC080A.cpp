#include <bits/stdc++.h>
using namespace std;

const int N = 100009;

int n, a[N];
vector<long long> fin, mul, two, trash;

int pop(vector<long long> &a){
    int x = a.back();
    a.pop_back();
    return x;
}

int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    for(int i = 0; i < n; i++)
        if(a[i] % 4 == 0) mul.push_back(a[i]);
        else if(a[i] % 2 == 0) two.push_back(a[i]);
        else trash.push_back(a[i]);

    fin = two;
    while(fin.size() != n){
        if(fin.size() != 0 && mul.size() != 0) fin.push_back(pop(mul));
        if(trash.size() != 0) fin.push_back(pop(trash));
        if(fin.size() == 0 && mul.size() != 0) fin.push_back(pop(mul));
    }

    fprintf(stderr, "%d\n", fin.size());
    for(int i = 0; i < n; i++)
        fprintf(stderr, "%d ", fin[i]);
    fprintf(stderr, "\n");

    if(fin.size() != n){
        printf("No\n");
        return 0;
    }

    for(int i = 0; i < n-1; i++)
        if(fin[i] * fin[i+1] % 4 != 0){
            printf("No\n");
            return 0;
        }
    printf("Yes\n");
    return 0;
}
