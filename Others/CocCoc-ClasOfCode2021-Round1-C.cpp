#include <iostream>
#include <vector>
using namespace std;

class segment_tree {
private:
    vector<vector<int>> tree;
    int n;

    int get_left(int index) {
        return index * 2 + 1;
    }

    int get_right(int index) {
        return index * 2 + 2;
    }

    void build(int index, int left, int right, const vector<int>& arr) {
        if (left == right) {
            for (int i = 0; i < 31; i++) {
                if ((arr[left] >> i) & 1) {
                    tree[index][i] = 1;
                }
            }
            return;
        }

        int mid = (left + right) / 2;
        build(get_left(index), left, mid, arr);
        build(get_right(index), mid + 1, right, arr);

        for (int i = 0; i < 31; i++) {
            tree[index][i] = tree[get_left(index)][i] + tree[get_right(index)][i];
        }
    }

    void update(int index, int left, int right, int pos, int value) {
        if (right < pos || pos < left) {
            return;
        }

        if (left == pos && right == pos) {
            for (int i = 0; i < 31; i++) {
                if ((value >> i) & 1) {
                    tree[index][i] = 1;
                }
                else {
                    tree[index][i] = 0;
                }
            }
            return;
        }

        int mid = (left + right) / 2;
        update(get_left(index), left, mid, pos, value);
        update(get_right(index), mid + 1, right, pos, value);

        for (int i = 0; i < 31; i++) {
            tree[index][i] = tree[get_left(index)][i] + tree[get_right(index)][i];
        }
    }

    vector<int> get(int index, int left, int right, int L, int R) {
        if (right < L || R < left) {
            return vector<int>(31, 0);
        }

        if (L <= left && right <= R) {
            return tree[index];
        }

        int mid = (left + right) / 2;
        auto left_bits = get(get_left(index), left, mid, L, R);
        auto right_bits = get(get_right(index), mid + 1, right, L, R);

        vector<int> bits(31, 0);
        for (int i = 0; i < 31; i++) {
            bits[i] = left_bits[i] + right_bits[i];
        }

        return bits;
    }

public:
    segment_tree (const vector<int>& arr) {
        n = arr.size();

        tree.resize(4 * n, vector<int>(31, 0));

        build(0, 0, n - 1, arr);
    }

    void update(int pos, int value) {
        update(0, 0, n - 1, pos, value);
    }

    vector<int> get(int left, int right) {
        return get(0, 0, n - 1, left, right);
    }
};

int main() {
    int n, q;
    cin >> n >> q;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    segment_tree tree(a);
    vector<int> tree_bits = tree.get(0, n - 1);

    while (q--) {
        int t;
        cin >> t;

        if (t == 1) {
            int pos, value;
            cin >> pos >> value;

            tree.update(pos - 1, value);
        }
        else {
            int left, right;
            cin >> left >> right;

            vector<int> z_bits = tree.get(left - 1, right - 1);
            int z = 0;
            int segment_length = right - left + 1;

            for (int i = 0; i < 31; i++) {
                if (2 * z_bits[i] < segment_length) {
                    z |= 1 << i;
                }
            }

            cout << z << endl;
        }
    }
    return 0;
}
