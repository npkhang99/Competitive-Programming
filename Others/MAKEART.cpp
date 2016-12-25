// CodeChef
#include <cstdio>
using namespace std;

const int N = 100009;

int n, a[N]={};

int main(){
    int TC; scanf("%d",&TC);
    while(TC--){
        scanf("%d",&n);
        for(int i=0; i<n; i++)
            scanf("%d",&a[i]);
        int last = a[0], cnt = 1;
        bool flag = false;
        for(int i=1; i<n; i++){
            if(a[i] != last){
                last = a[i];
                cnt = 1;
                continue;
            }
            if(++cnt == 3){
                flag = true;
                break;
            }
        }

        printf("%s\n", flag? "Yes":"No");
    }
    return 0;
}
