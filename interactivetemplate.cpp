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
#define pi acos(-1)
#define all(x) begin(x), end(x)
// #define endl "\n"
#define TESTS int test; cin>>test; for(int kase = 1 ; kase <= test ; kase++) solve(kase);
#define CASEOUT cout << "Case " << testcase << ": "
#define int long long
#define pii pair<int,int>
#ifdef LOCAL
 const LL MAX = 100 + 2;
#else
 const LL MAX = (1e2) + 2;
#endif
const LL MOD = (1e9) + 7;
const LL INF = (1e15) + 5;



int rand(int a, int b) {
    static std::mt19937_64 rng(std::chrono::steady_clock::now().time_since_epoch().count());
    std::uniform_int_distribution<int> dist(a, b);
    return dist(rng);
}

int n, k;

namespace judge{
    int query(int a)
    {
        int ret;
        cout << "? " << a << endl;
        cin >> ret;
        return ret;
    }

    void answer(int a)
    {
        cout << "! " << a << endl;
        return;
    }

    void takeInput()
    {
        cin >> n >> k;
    }
}


namespace offline{
    int ans;
    vector <int> v;
    int query(int a)
    {
        cout << "? " << a << endl;
        int ret = 0;
        for(int i = a-1, j = 1 ; j <= k ; i++, j++)
        {
            ret ^= v[i];
            if(j != k && i == n-1)
            {
                cout << "Wrong query" << endl;
                assert(false);
            }
        }
        reverse(v.begin() + a - 1, v.begin() + a - 1 + k);
        return ret;
    }

    void answer(int a)
    {
        cout << "! " << a << endl;
        assert(a == ans);
        return;
    }

    void takeInput()
    {
        n = rand(4, 6);
        n *= 2;
        k = rand(1, n/2);
        k *= 2;
        v.resize(n);
        for(auto &x : v)
            x = rand(1, 99999);
        ans = 0;
        for(auto &x : v)
            ans ^= x;
        cout << "Input taken" << endl;
        cout << n << " " << k << endl;
        for(auto &x : v)
            cout << x << " ";
        cout << endl;
    }
}

#ifdef LOCAL
    using namespace offline;
#else
    using namespace judge;
#endif



int solve(int testcase)
{
    takeInput();
    int ans = 0;
    int indx = 1, rem = (n%k)/2;

    while(indx + k - 1 <= n)
    {
        ans ^= query(indx);
        if(n%k != 0 && (indx == 1 || indx == 1+rem))
            indx += rem;
        else indx += k;
    }
    answer(ans);
    return testcase;
}

signed main()
{
    #ifdef LOCAL
    //    freopen("in.txt", "r", stdin);
    //    freopen("out.txt", "w", stdout);
       clock_t start = clock();
    #endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //cout.tie(NULL);

    //solve(0);
    TESTS

    #ifdef LOCAL
        cerr << "\nRunning Time: " << double(clock() - start) / CLOCKS_PER_SEC * 1000 << "ms" << endl;
    #endif
    return 0;
}