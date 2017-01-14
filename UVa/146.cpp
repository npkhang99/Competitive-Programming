#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

char st[60];

int main(){
    while(scanf("%s",st), strcmp(st,"#")){
        bool success = next_permutation(st,st+strlen(st));
        printf("%s\n", success? st:"No Successor");
    }
    return 0;
}
