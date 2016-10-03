#include <bits/stdc++.h>
using namespace std;

int n, mirror[256]={};
string st;

void preprocess(){
    mirror['A'] = 'A';
    mirror['E'] = '3';
    mirror['H'] = 'H';
    mirror['I'] = 'I';
    mirror['J'] = 'L';
    mirror['L'] = 'J';
    mirror['M'] = 'M';
    mirror['O'] = 'O';
    mirror['S'] = '2';
    mirror['T'] = 'T';
    mirror['U'] = 'U';
    mirror['V'] = 'V';
    mirror['W'] = 'W';
    mirror['X'] = 'X';
    mirror['Y'] = 'Y';
    mirror['Z'] = '5';
    mirror['1'] = '1';
    mirror['2'] = 'S';
    mirror['3'] = 'E';
    mirror['5'] = 'Z';
    mirror['8'] = '8';
}

bool isPalindrome(){
    for(int i=0; i<n/2; i++)
        if(st[i] != st[n-i-1]) return false;
    return true;
}

bool isMirrored(){
    for(int i=0; i<(int)ceil(n/2.0); i++)
        if(st[i] != mirror[st[n-i-1]]) return false;
    return true;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    preprocess();
    while(cin>> st){
        n = st.size();
        if(isPalindrome()){
            if(isMirrored()) cout<< st<< " -- is a mirrored palindrome.\n\n";
            else cout<< st<< " -- is a regular palindrome.\n\n";
            continue;
        }
        if(isMirrored()){
            cout<< st<< " -- is a mirrored string.\n\n";
            continue;
        }
        cout<< st<< " -- is not a palindrome.\n\n";
    }
    return 0;
}
