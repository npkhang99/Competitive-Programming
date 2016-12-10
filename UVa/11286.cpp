#include <bits/stdc++.h>
using namespace std;

const int N = 10009;

int n, a[5]={};
unordered_map<string,int> freq;

int main(){
    while(scanf("%d",&n), n){
        freq.clear();
        int popularity = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<5; j++)
                scanf("%d",&a[j]);
            sort(a,a+5);
            string combination = "";
            for(int j=0; j<5; j++)
                combination += to_string(a[j]);
            freq[combination] += 1;
            popularity = max(popularity, freq[combination]);
        }
        
        int ans = 0;
        for(unordered_map<string,int>::iterator it=freq.begin(); it != freq.end(); it++)
            if((it -> second) == popularity) ans += (it -> second);
        printf("%d\n",ans);
    }
    return 0;
}
