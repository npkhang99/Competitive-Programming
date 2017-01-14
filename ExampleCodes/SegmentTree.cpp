// Simple Segment Tree (Interval Tree - IT)
#include <cstdio>
using namespace std;

const int N = 100009;

int n = 7, A[]={-1, 18, 17, 13, 19, 15, 11, 20}, st[4*N]={}, lazy[4*N]={};

// Ultilities functions
int left(int i){ return i*2; }
int right(int i){ return i*2 + 1; }
int max(int a, int b){ return a > b? a:b; }

// Build Segment Tree from an Array - O(n log n)
int build(int i, int l, int r){
    if(l == r) return st[i] = A[l];

    int mid = (l+r) / 2;
    int p1 = build(left(i), l, mid),
        p2 = build(right(i), mid+1, r);
    return st[i] = max(p1, p2);
}

// Range Maximum Query - O(log n)
int rmq(int i, int l, int r, int L, int R){
    if(r < L || R < l) return -1;
    if(L <= l && r <= R) return st[i];

    int mid = (l+r) / 2;
    int p1 = rmq(left(i), l, mid, L, R),
        p2 = rmq(right(i), mid+1, r, L, R);
    if(p1 == -1) return p2;
    if(p2 == -1) return p1;
    return max(p1 ,p2);
}

// Point Update - O(log n)
int point_update(int i, int l, int r, int p, int newValue){
    if(r < p || p < l) return st[i];
    if(l == p && r == p){
        A[p] = newValue;
        return st[i] = A[p];
    }

    int mid = (l+r) / 2;
    int p1 = point_update(left(i), l, mid, p, newValue),
        p2 = point_update(right(i), mid+1, r, p, newValue);
    return st[i] = max(p1, p2);
}

// Range Update without Lazy Propagation
int range_update_no_lazy(int i, int l, int r, int L, int R, int newValue){
    if(r < L || R < l) return st[i];
    if(l == r){
        A[l] = newValue;
        return st[i] = A[l];
    }

    int mid = (l+r) / 2;
    int p1 = range_update_no_lazy(left(i), l, mid, L, R ,newValue),
        p2 = range_update_no_lazy(right(i), mid+1, r, L, R, newValue);
    return st[i] = max(p1, p2);
}

// Range Update with Lazy Propagation - Not done
int range_update_lazy(int i, int l, int r, int L, int R, int newValue){
    if(lazy[i]){
        st[i] = max(st[i], lazy[i]);
        if(l != r){
            lazy[left(i)] = lazy[i];
            lazy[right(i)] = lazy[i];
        }
        lazy[i] = 0;
    }

    if(r < L || R < l) return st[i];
    if(L <= l && r <= R){
        st[i] = max(st[i], newValue);
        if(l != r){
            lazy[left(i)] = max(newValue, lazy[left(i)]);
            lazy[right(i)] = max(newValue, lazy[right(i)]);
        }
        return st[i];
    }

    int mid = (l+r) / 2;
    int p1 = range_update_lazy(left(i), l, mid, L, R, newValue),
        p2 = range_update_lazy(right(i), mid+1, r, L, R, newValue);
    return st[i] = max(p1, p2);
}

int main(){
    build(1, 1, n);
    printf("              idx    1,  2,  3,  4,  5,   6,  7\n");
    printf("              A is {18, 17, 13, 19, 15,  11, 20}\n");
    printf("RMQ(2, 4) = %d\n", rmq(1, 1, n, 2, 4));
    printf("RMQ(5, 7) = %d\n", rmq(1, 1, n, 5, 7));
    printf("RMQ(6, 5) = %d\n", rmq(1, 1, n, 4, 5));
    printf("RMQ(1, 1) = %d\n", rmq(1, 1, n, 1, 1));
    printf("RMQ(1, 2) = %d\n", rmq(1, 1, n, 1, 2));
    printf("RMQ(1, 7) = %d\n", rmq(1, 1, n, 1, 7));
    printf("\n");
    printf("              idx    1,  2,  3,  4,  5,   6,  7\n");
    printf("Now, modify A into {18, 17, 13, 19, 15, 100, 20}\n");
    point_update(1, 1, n, 6, 100);
    printf("These values do not change\n");
    printf("RMQ(2, 4) = %d\n", rmq(1, 1, n, 2, 4));
    printf("RMQ(4, 5) = %d\n", rmq(1, 1, n, 4, 5));
    printf("RMQ(1, 1) = %d\n", rmq(1, 1, n, 1, 1));
    printf("RMQ(1, 2) = %d\n", rmq(1, 1, n, 1, 2));
    printf("These values change\n");
    printf("RMQ(1, 7) = %d\n", rmq(1, 1, n, 1, 7));
    printf("RMQ(5, 7) = %d\n", rmq(1, 1, n, 5, 7));
    printf("RMQ(5, 6) = %d\n", rmq(1, 1, n, 5, 6));
    return 0;
}
