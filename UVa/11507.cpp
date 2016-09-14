#include <bits/stdc++.h>
using namespace std;

int n;

int main(){
    while(cin>> n, n){
        string st, ans="+x";
        for(int i=1; i<n; i++){
            cin>> st;
            if(st=="+y")
                if(ans=="+x") ans = "+y";
                else if(ans=="-x") ans = "-y";
                else if(ans=="+y") ans = "-x";
                else if(ans=="-y") ans = "+x";
            if(st=="-y")
                if(ans=="+x") ans = "-y";
                else if(ans=="-x") ans = "+y";
                else if(ans=="+y") ans = "+x";
                else if(ans=="-y") ans = "-x";
            if(st=="+z")
                if(ans=="+x") ans = "+z";
                else if(ans=="-x") ans = "-z";
                else if(ans=="+z") ans = "-x";
                else if(ans=="-z") ans = "+x";
            if(st=="-z")
                if(ans=="+x") ans = "-z";
                else if(ans=="-x") ans = "+z";
                else if(ans=="+z") ans = "+x";
                else if(ans=="-z") ans = "-x";
        }
        printf("%s\n",ans.c_str());
    }
    return 0;
}
