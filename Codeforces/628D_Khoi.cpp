#include <bits/stdc++.h>
#define MAX_N 2010
#define MODULO 1000000007

using namespace std;

typedef long long ll;

string a , b;
int n , m , d;
ll dp[MAX_N][MAX_N][2][2];

int main ()
{
    cin >> m >> d;
    cin >> a >> b;

    n = a.size();

    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++) dp[n][0][i][j] = 1;

    for (int i = n - 1; i >= 0; i--)
        for (int r = 0; r < m; r++)
            for (int x = 0; x < 2; x++)
                for (int y = 0; y < 2; y++)
                {
                    dp[i][r][x][y] = 0;
                    for (int k = (y ? 0 : a[i] - '0'); k <= (x ? 9 : b[i] - '0'); k++)
                        if ((i % 2 && k == d) || (!(i % 2) && k != d))
                            (dp[i][r][x][y] += dp[i + 1][(r * 10 + k) % m][x | (k < b[i] - '0')][y | (k > a[i] - '0')]) %= MODULO;
                }

    cout << dp[0][0][0][0] << endl;
    return 0;
}