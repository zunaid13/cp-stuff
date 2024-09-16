/*
⡆⣐⢕⢕⢕⢕⢕⢕⢕⢕⠅⢗⢕⢕⢕⢕⢕⢕⢕⠕⠕⢕⢕⢕⢕⢕⢕⢕⢕⢕
⢐⢕⢕⢕⢕⢕⣕⢕⢕⠕⠁⢕⢕⢕⢕⢕⢕⢕⢕⠅⡄⢕⢕⢕⢕⢕⢕⢕⢕⢕
⢕⢕⢕⢕⢕⠅⢗⢕⠕⣠⠄⣗⢕⢕⠕⢕⢕⢕⠕⢠⣿⠐⢕⢕⢕⠑⢕⢕⠵⢕
⢕⢕⢕⢕⠁⢜⠕⢁⣴⣿⡇⢓⢕⢵⢐⢕⢕⠕⢁⣾⢿⣧⠑⢕⢕⠄⢑⢕⠅⢕
⢕⢕⠵⢁⠔⢁⣤⣤⣶⣶⣶⡐⣕⢽⠐⢕⠕⣡⣾⣶⣶⣶⣤⡁⢓⢕⠄⢑⢅⢑
⠍⣧⠄⣶⣾⣿⣿⣿⣿⣿⣿⣷⣔⢕⢄⢡⣾⣿⣿⣿⣿⣿⣿⣿⣦⡑⢕⢤⠱⢐
⢠⢕⠅⣾⣿⠋⢿⣿⣿⣿⠉⣿⣿⣷⣦⣶⣽⣿⣿⠈⣿⣿⣿⣿⠏⢹⣷⣷⡅⢐
⣔⢕⢥⢻⣿⡀⠈⠛⠛⠁⢠⣿⣿⣿⣿⣿⣿⣿⣿⡀⠈⠛⠛⠁⠄⣼⣿⣿⡇⢔
⢕⢕⢽⢸⢟⢟⢖⢖⢤⣶⡟⢻⣿⡿⠻⣿⣿⡟⢀⣿⣦⢤⢤⢔⢞⢿⢿⣿⠁⢕
⢕⢕⠅⣐⢕⢕⢕⢕⢕⣿⣿⡄⠛⢀⣦⠈⠛⢁⣼⣿⢗⢕⢕⢕⢕⢕⢕⡏⣘⢕
⢕⢕⠅⢓⣕⣕⣕⣕⣵⣿⣿⣿⣾⣿⣿⣿⣿⣿⣿⣿⣷⣕⢕⢕⢕⢕⡵⢀⢕⢕
⢑⢕⠃⡈⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⢃⢕⢕⢕
⣆⢕⠄⢱⣄⠛⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠿⢁⢕⢕⠕⢁
⣿⣦⡀⣿⣿⣷⣶⣬⣍⣛⣛⣛⡛⠿⠿⠿⠛⠛⢛⣛⣉⣭⣤⣂⢜⠕⢑⣡⣴⣿
*/
#include <bits/stdc++.h>
// #pragma GCC optimize("Ofast,unroll-loops")
// #pragma GCC target("avx2,popcnt,lzcnt,abm,bmi,bmi2,fma,tune=native")

using namespace std;
#ifdef LOCAL
 #include "Dbug.h"
#else
 #define dbg(...)
#endif
typedef long long LL;
typedef long double LD;
#define all(x) begin(x), end(x)
#define endl "\n"
#define CASEOUT cout << "Case " << testcase << ": "
#define int long long
#define pii pair<int,int>
#ifdef LOCAL
 const LL MAX = 100 + 2;
#else
 const LL MAX = (1e2) + 2;
#endif
const LL pi = acos(-1);
const LL MOD = (1e9) + 7;
const LL INF = (1e15) + 5;


class SparseTableGCD {
public:
    vector<vector<int>> sparse_table;
    vector<int> log_table;
    int n;

    // Constructor: Builds the sparse table
    SparseTableGCD(const vector<int>& arr) {
        n = arr.size();
        buildLogTable(n);
        buildSparseTable(arr);
    }

    // Precompute the logarithms
    void buildLogTable(int n) {
        log_table.resize(n + 1);
        log_table[1] = 0;
        for (int i = 2; i <= n; i++) {
            log_table[i] = log_table[i / 2] + 1;
        }
    }

    // Build the sparse table for GCD
    void buildSparseTable(const vector<int>& arr) {
        int k = log_table[n];  // k is the maximum power of 2 <= n
        sparse_table.assign(n, vector<int>(k + 1));

        // Initialize the sparse table for intervals of length 1 (2^0)
        for (int i = 0; i < n; i++) {
            sparse_table[i][0] = arr[i];
        }

        // Build the table
        for (int j = 1; j <= k; j++) {
            for (int i = 0; i + (1 << j) <= n; i++) {
                sparse_table[i][j] = __gcd(sparse_table[i][j - 1], sparse_table[i + (1 << (j - 1))][j - 1]);
            }
        }
    }

    // Query the GCD for range [L, R]
    int query(int L, int R) {
        // Check if L and R are within valid bounds
        if (L > R || L < 0 || R >= n) {
            return 0;
        }
        int j = log_table[R - L + 1];  // Find the largest power of 2 that fits in the range length
        return __gcd(sparse_table[L][j], sparse_table[R - (1 << j) + 1][j]);
    }
};


int solve(int testcase)
{
    int n;
    cin >> n;
    vector <int> a(n, 0), b(n, 0);
    for(int i = 0 ; i < n ; i++)
        cin >> a[i];
    for(int i = 0 ; i < n ; i++)
        cin >> b[i];
    SparseTableGCD A(a), B(b);

    
    auto check = [&](int l, int r)
    {
        int retA = __gcd(A.query(0, l-1), B.query(l, r));
        retA = __gcd(retA,  A.query(r+1, n-1));
        int retB = __gcd(B.query(0, l-1), A.query(l, r));
        retB = __gcd(retB, B.query(r+1, n-1));
        return retA + retB;
    };
    int ans = 0, cnt = 1;
    for(int i = 0 ; i < n ; i++)
    {
        int node = i;
        while(1)
        {
            int curr = check(i, node);
            if(curr > ans)
            {
                cnt = 0;
                ans = curr;
            }
            int l = node, r = n-1;
            while(l <= r)
            {
                int mid = (l + r) / 2;
                if(A.query(i, mid) == A.query(i, node) && B.query(i, mid) == B.query(i, node) && A.query(mid+1, n-1) == A.query(node+1, n-1) && B.query(mid+1, n-1) == B.query(mid+1, n-1))
                    l = mid + 1;
                else r = mid - 1;
            }
            if(curr == ans) cnt += l - node;
            node = l;
            if(node == n) break;
        }
    }
    cout << ans << " " << cnt << endl;
    return testcase;
}

signed main()
{
    #ifdef LOCAL
       freopen("in.txt", "r", stdin);
       freopen("out.txt", "w", stdout);
       clock_t start = clock();
    #endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //cout.tie(NULL);

    int testCases = 1;
    cin >> testCases;
    for(int i = 1 ; i <= testCases; i++)
        solve(i);

    #ifdef LOCAL
        cerr << "\nRunning Time: " << double(clock() - start) / CLOCKS_PER_SEC * 1000 << "ms" << endl;
    #endif
    return 0;
}