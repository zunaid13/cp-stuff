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

int solve(int testcase)
{
    int n;
    cin >> n;
    vector <int> a(n), b(n);
    for(auto &x : a) cin >> x;
    for(auto &x : b) cin >> x;
    int ans = 0, cnt = 1;
    for(int i = 0 ; i < n ; i++)
    {
        for(int j = i ; j < n ; j++)
        {
            for(int k = i ; k <= j ; k++)
                swap(a[k], b[k]);
            int gA = 0, gB = 0;
            for(int k = 0 ; k < n ; k++)
            {
                gA = __gcd(a[k], gA);
                gB = __gcd(b[k], gB);
            }
            if(ans < gA + gB)
            {
                ans = gA + gB;
                cnt = 1;
            }
            else if(ans == gA + gB)
                cnt++;
            for(int k = i ; k <= j ; k++)
                swap(a[k], b[k]);
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