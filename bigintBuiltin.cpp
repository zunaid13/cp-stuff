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
#include <gmpxx.h>  // Include GMP C++ bindings
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
#define pii pair<int,int>
#ifdef LOCAL
 const LL MAX = 100 + 2;
#else
 const LL MAX = (1e2) + 2;
#endif
const LL pi = acos(-1);
const LL MOD = (1e9) + 7;
const LL INF = (1e15) + 5;

#define LL mpz_class
// mpz_class mod_result = (j + turns) % cycle[i].size();
// int idx = mpz_get_ui(mod_result.get_mpz_t());

typedef pair<LL, LL> PLL;

inline LL modit(LL x, LL m) {
	LL z = x%m; return z<0 ? z+m : z;
}

/// (a^b) mod m via successive squaring
LL power(LL a, LL b, LL m) {
    a = modit(a, m);
	LL ans = 1;
	while (b != 0) {
		if (b%2 != 0) ans = (ans*a)%m;
		a = (a*a)%m;
		b /= 2;
	}
	return ans;
}

/// returns g = gcd(a, b); finds x, y such that d = ax+by
LL egcd(LL a, LL b, LL &x, LL &y) {
	LL xx = y = 0;
	LL yy = x = 1;
	while (b != 0) {
		LL q = a/b;
		LL t = b; b = a%b; a = t;
		t = xx; xx = x-q*xx; x = t;
		t = yy; yy = y-q*yy; y = t;
	}
	return a;
}
/// Computes b such that ab = 1 (mod m), returns -1 on failure
LL inverse(LL a, LL m) {
	LL x, y;
	LL g = egcd(a, m, x, y);
	if (g > 1) return -1;
	return modit(x, m);
}

LL mulmod(LL a, LL b, LL m) //calculates (ab)%m
{
    if(b == 0) return 0;
    LL ret = mulmod(a, b/2, m);
    ret = (ret + ret)%m;
    if(b%2 == 1)
        ret = (ret + a)%m;
    return ret;
}

/// Chinese remainder theorem (special case): find z st z%m1 = r1, z%m2 = r2.
/// z is unique modulo M = lcm(m1, m2). Returns (z, M). On failure, M = -1.
PLL CRT(LL m1, LL r1, LL m2, LL r2) {
	LL s, t;
	LL g = egcd(m1, m2, s, t);
	if (r1%g != r2%g) return PLL(0, -1);
	LL M = m1*m2;
	// LL ss = ((s*r2)%m2)*m1;
	LL ss = (mulmod(s, r2, m2))*m1;
	// LL tt = ((t*r1)%m1)*m2;
	LL tt = (mulmod(t, r1, m1))*m2;
	LL ans = modit(ss+tt, M);
	return PLL(ans/g, M/g);
}

int solve(int testcase)
{
    int n;
    cin >> n;
    vector <int> p(n+1), a(n+1);
    for(int i = 1 ; i <= n ; i++)
        cin >> p[i];
    for(int i = 1 ; i <= n ; i++)
        cin >> a[i];
    vector <int> ans(n+1), vis(n+1, 0);
    vector <vector<int>> cycle(n+1);
    PLL current = {-1, -1}, last;
    for(int i = 1 ; i <= n ; i++)
    {
        if(vis[i]) continue;
        int curr;
        for(curr = i ; p[curr] != i ; curr = p[curr])
        {
            vis[curr] = 1;
            cycle[i].push_back(curr);
        }
        vis[curr] = 1;
        cycle[i].push_back(curr);
        vector <pii> v_i(cycle[i].size());
        for(int j = 0 ; j < cycle[i].size() ; j++)
            v_i[j] = {a[cycle[i][j]], j};
        sort(all(v_i));
        if(current == (PLL) {-1, -1})
        {
            current = {v_i[0].second, cycle[i].size()};
        }
        else
        {
            for(int j = 0 ; j < v_i.size() ; j++)
            {
                last = current;
                current = CRT(cycle[i].size(), v_i[j].second, last.second, last.first);
                if(current.second == -1) current = last;
                else break;
            }
        }
    }   
    LL turns = current.first;
    for(int i = 1 ; i <= n ; i++)
    {
        dbg(i, cycle[i]);
        for(int j = 0 ; j < cycle[i].size() ; j++)
        {
            mpz_class mod_result = (j + turns) % cycle[i].size();
            int idx = mpz_get_ui(mod_result.get_mpz_t());
            ans[cycle[i][j]] = a[cycle[i][idx]];
        }
    }
    for(int i = 1 ; i <= n ; i++)
        cout << ans[i] << " ";
    cout << endl;
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
    // cin >> testCases;
    for(int i = 1 ; i <= testCases; i++)
        solve(i);

    #ifdef LOCAL
        cerr << "\nRunning Time: " << double(clock() - start) / CLOCKS_PER_SEC * 1000 << "ms" << endl;
    #endif
    return 0;
}