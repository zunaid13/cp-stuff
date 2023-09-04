/*
    So, which of the favours
    of your Lord would you deny?
*/

#include <bits/stdc++.h>

using namespace std;

#define LL long long
#define FPP(i, start, end) for (int i = start; i < end; i++)
#define FMM(i, start, end) for (int i = end - 1; i >= start; i--)
#define bolo(s) cout << #s << "\n";
#define show(x) cout << #x << ": " << x << endl;
#define all(x) x.begin(), x.end()
#define MAXN 1000006

const LL p = 31, mod = 1e9+9;
vector<int> adj[MAXN];
string s;
int ans = 0;

LL binpow(LL a, LL b)
{   
    if(b == 0) return 1;
    LL res = binpow(a, b/2);
    if(b % 2) return (((res * res)%mod) * a)%mod;
    return (res * res)%mod;
}

void dfs(int curr, int par, LL hl, LL hr, int lvl)
{
    // THIS IS THE HASH
    hl = ((hl*p) % mod + (s[curr]-'A')) %mod;
    hr = (hr + (s[curr] - 'A') * binpow(p, lvl)) % mod;
    // END OF HASH
    if(hl == hr) ans++;
    for(auto child: adj[curr])
    {
        if(child == par) continue;
        dfs(child, curr, hl, hr, lvl+1);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(NULL);
    int T = 1;
    cin >> T;
    FPP(t,1,T+1)
    {
        int n;
        cin >> n >> s;
        s = '#' + s;
        FPP(i,0,n-1)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        dfs(1,0,0,0,0);
        LL g = __gcd(ans, n);
        ans /= g;
        n /= g;
        cout << "Case " << t << ": " << ans << "/" << n << "\n";

        ans = 0;
        FPP(i,0,n+1)
        {
            adj[i].clear();
        }
    }
    return 0;
}