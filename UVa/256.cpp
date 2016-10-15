#include <cstdio>
#include <cstring>

const char* a[] = { "00","01","81",
                    "0000","0001","2025","3025","9801",
                    "000000","000001","088209","494209","998001",
                    "00000000","00000001","04941729","07441984","24502500","25502500","52881984","60481729","99980001"};

int n;

int main(){
    while(scanf("%d",&n)!=EOF){
        for(int i=0; i<22; i++)
            if(strlen(a[i]) == n) printf("%s\n",a[i]);
            else if(strlen(a[i]) > n) break;
    }
    return 0;
}
