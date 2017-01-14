#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;

string st;

int main(){
    while(getline(cin,st)) printf("%s\n",st.c_str());
    return 0;
}
