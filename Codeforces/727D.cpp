#include <bits/stdc++.h>
using namespace std;

const int N = 100009;

int n, remain[10]={}, option_1[N]={}, option_2[N]={};
string ans[N];

int map_value(string st){
    if(st == "S") return 0;
    if(st == "M") return 1;
    if(st == "L") return 2;
    if(st == "XL") return 3;
    if(st == "XXL") return 4;
    if(st == "XXXL") return 5;
}

string get_size(int size){
    switch(size){
        case 0: return "S";
        case 1: return "M";
        case 2: return "L";
        case 3: return "XL";
        case 4: return "XXL";
        case 5: return "XXXL";
        default: return "undefined";
    }
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    for(int i=0; i<6; i++)
        cin>> remain[i];
    cin>> n;
    for(int i=0; i<n; i++){
        string st; cin>> st;
        int p = st.find(',');
        if(p != string::npos){
            option_1[i] = map_value(st.substr(0,p));
            option_2[i] = map_value(st.substr(p+1,st.size()));
        }else{
            ans[i] = st;
            option_1[i] = option_2[i] = map_value(st);
            remain[option_1[i]]--;
        }
    }

    int k1 = 0, k2 = 1;
    while(k1 < 6){
        for(int i=0; i<n; i++){
            if(ans[i] != "" || option_1[i] != k1 || option_2[i] != k2) continue;
            if(remain[option_1[i]] > 0) ans[i] = get_size(option_1[i]);
            else ans[i] = get_size(option_2[i]);
            remain[map_value(ans[i])]--;
        }

        k1++; k2++;
    }

    for(int i=0; i<6; i++)
        if(remain[i] < 0){
            cout<< "NO\n";
            return 0;
        }

    cout<< "YES\n";
    for(int i=0; i<n; i++)
        cout<< ans[i]<< '\n';
    return 0;
}
