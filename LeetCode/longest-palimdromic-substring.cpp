#include <string>
using namespace std;

class Solution {
public:
    string expand(const string& s, int l, int r) {
        while (l >= 0 && r < s.length() && s[l] == s[r]) {
            l -= 1;
            r += 1;
        }

        return s.substr(l + 1, r - l - 1);
    }

    string longestPalindrome(const string& s) {
        string ans = "";
        for (int i = 0; i < s.length(); i++) {
            string odd_length = expand(s, i, i);

            string even_length = "";
            if (i > 0 && s[i - 1] == s[i]) {
                even_length = expand(s, i - 1, i);
            }

            if (ans.length() < odd_length.length()) {
                ans = odd_length;
            }
            if (ans.length() < even_length.length()) {
                ans = even_length;
            }
        }

        return ans;
    }
};
