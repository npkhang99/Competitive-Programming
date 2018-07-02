#include <bits/stdc++.h>
using namespace std;

vector<int> palindrome;

bool is_palindrome(int n) {
    string st = to_string(n);
    string st_rev = st;
    reverse(st_rev.begin(), st_rev.end());
    return st == st_rev;
}

void prep() {
    palindrome.push_back(0);
    for (int i = 1; i <= 10000; i++) {
        if (is_palindrome(i)) {
            palindrome.push_back(i);
        }
    }
}

int main() {
    int TC; scanf("%d", &TC);
    prep();
    for (int CASE = 1; CASE <= TC; CASE++) {
        int n;
        scanf("%d", &n);
        int a = 0, b = 0, c = 0;
        for (int i = 0; i < (int) palindrome.size(); i++)
            for (int j = i; j < (int) palindrome.size(); j++)
                for (int k = j; k < (int) palindrome.size(); k++) {
                    if (palindrome[i] + palindrome[j] + palindrome[k] == n && a + b + c == 0) {
                        a = i;
                        b = j;
                        c = k;
                    }
                }
        printf("Case #%d\n", CASE);
        if (a == b && b == c && c == 0)
            printf("0\n");
        else if (a == b && a == 0)
            printf("1 %d\n", palindrome[c]);
        else if (a == 0)
            printf("2 %d %d\n", palindrome[b], palindrome[c]);
        else
            printf("3 %d %d %d\n", palindrome[a], palindrome[b], palindrome[c]);
    }
    return 0;
}
