#include <bits/stdc++.h>
using namespace std;

struct node {
    node* child[2];
    node* prev;
    bool blocked;

    node() {
        prev = child[0] = child[1] = NULL;
        blocked = false;
    }
};

pair<int,int> length[1009] = {};
string ans[1009];
node* root = new node();

bool add_word(int length, int id) {
    node* tmp = root;
    string word("0", length);

    int i = 0;
    while (i < length) {
        int next_char = -1;
        for (int j = 0; j < 2; j++) {
            if (tmp->child[j] == NULL || tmp->child[j]->blocked == false) {
                next_char = j;
                break;
            }
        }

        if (next_char == -1) {
            if (tmp == root) {
                return false;
            }
            else {
                tmp->blocked = true;
                tmp = tmp->prev;
                i -= 1;
            }
        }
        else {
            if (tmp->child[next_char] == NULL) {
                tmp->child[next_char] = new node();
            }
            tmp->child[next_char]->prev = tmp;
            tmp = tmp->child[next_char];
            word[i] = '0' + next_char;
            i += 1;
        }
    }

    tmp->blocked = true;
    ans[id] = word;

    return true;
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> length[i].first;
        length[i].second = i;
    }

    sort(length, length + n);
    for (int i = 0; i < n; i++) {
        if (!add_word(length[i].first, length[i].second)) {
            cout << "NO\n";
            return 0;
        }
    }

    cout << "YES\n";
    for (int i = 0; i < n; i++) {
        cout << ans[i] << "\n";
    }
    return 0;
}
