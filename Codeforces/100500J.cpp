#include <cstdio>

struct time{
    int hour, minutes;
    int toMinute(){ return hour*60 + minutes; }
} start, finish;

int main(){
    int TC; scanf("%d",&TC);
    for(int T=1; T<=TC; T++){
        scanf("%d%d%d%d", &start.hour, &start.minutes, &finish.hour, &finish.minutes);
        int ans = 0;
        for(int i=start.toMinute(); i<finish.toMinute(); i = (i+1) % 1440) ans++;
        printf("Case %d: %d\n", T, ans);
    }
    return 0;
}
