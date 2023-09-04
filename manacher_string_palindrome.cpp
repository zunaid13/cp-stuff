#include<bits/stdc++.h>
#define ll long long
#define x first
#define y second
using namespace std;
const int lim = 1000006;
class Manacher
{
public:
    vector<int> p[2];
    void build(const string &s)
    {
        p[0].clear();
        p[1].clear();
        int n = s.size();
        p[0].resize(n + 1);
        p[1].resize(n);

        for (int z = 0; z < 2; z++)
            for (int i = 0, l = 0, r = 0; i < n; i++)
            {
                int t = r - i + !z;
                if (i < r) p[z][i] = min(t, p[z][l + t]);
                int L = i - p[z][i], R = i + p[z][i] - !z;
                while (L >= 1 && R + 1 < n && s[L - 1] == s[R + 1])   p[z][i]++, L--, R++;
                if (R > r) l = L, r = R;
            }
    }

    bool ispalin(int l, int r)
    {
        int mid = (l + r + 1) / 2, sz = r - l + 1;
        return 2 * p[sz % 2][mid] + sz % 2 >= sz;
    }
};
vector<bool> vis(lim, 0);
vector<vector<int>> adj(lim);
string out;
string build;
Manacher solver;
vector<string> vals;
void dfs(ll u)
{
    vis[u] = 1;
    build+=out[u];

    for(auto i : adj[u])
        if(!vis[i]) dfs(i);
    if(adj[u].size() == 1 and u!=0)
        vals.push_back(build);
    build.pop_back();

}
signed main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t;
    cin >> t;
    for (ll h = 0; h < t; ++h)
    {
        cout << "Case " << h + 1 << ": ";
        ll n, u, v;
        cin >> n;
        cin >> out;
        for (ll i = 0; i < n - 1; ++i)
        {
            cin >> u >> v;
            --u;
            --v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        dfs(0);
        for (int i = 0; i < n; ++i)
        {
            adj[i].clear();
            vis[i] = 0;
        }
        ll ans=0;
        for(auto i:vals){
            if(i.size() == 1){
                ++ans;
                continue;
            }
            solver.build(i);
            for (int j = 0; j < i.size(); ++j)
            {
                if(j==0) continue;
                if(solver.ispalin(0,j)) ++ans;
            }
        }

        ++ans;
        ll gcd = __gcd(ans, n);
        cout << ans / gcd << "/" << n / gcd << "\n";
        vals.clear();
        build.clear();

    }
}