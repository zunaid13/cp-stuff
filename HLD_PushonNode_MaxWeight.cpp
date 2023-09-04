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
using namespace std;
// #include "ext/pb_ds/assoc_container.hpp"
// #include "ext/pb_ds/tree_policy.hpp"

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

typedef long long LL;
typedef long double LD;
#define pi acos(-1)
#define whatis(x) cout << #x << " is " << x << "\n";
#define all(x) x.begin(), x.end()
#define endl "\n"
#define DEB cout << "TESTING" NL
#define TESTS int test; cin>>test; for(int kase = 1 ; kase <= test ; kase++) solve(kase);
#define CASEOUT cout << "Case " << testcase << ": " << 
#define YESNO cout << (possible? "YES\n" : "NO\n");
// #define YES cout << "YES\n";
// #define NO cout << "NO\n";
#define int long long
#define pii pair<int,int>
const int MAX = 1e4 + 5;
const int MOD = (1e9) + 7;
const int INF = (1e15) + 5;


int n, subSize[MAX], val[MAX], edge[MAX], par[MAX], vCnt, depth[MAX], treeFirst[MAX];
pii location[MAX];
vector <int> vect[MAX];
vector <pii> adj[MAX];
map <pii, int> mp;

class SegTree
{
    vector <int> seg;
    vector <int> vec;
    public:
    void build(vector <int> &v)
    {
        vec = v;
        seg.resize(4 * v.size() + 2);
        build(1, 0, v.size()-1);
    }
    int build(int node, int b, int e)
    {
        if(b == e)
            return seg[node] = vec[b];
            
        int mid = (b+e)/2;
        int l = 2*node;
        int r = l+1;
        return seg[node] = max(build(l, b, mid), build(r, mid+1, e));
    }
    int query(int l, int r)
    {
        return query(1, 0, vec.size()-1, l, r);
    }
    int query(int node, int b, int e, int i, int j)
    {
         if(i > e || j < b)
             return 0;
         if(b >= i && e <= j)
             return seg[node];
         int left = 2*node;
         int right = left+1;
         int mid = (b+e)/2;
         int ret1 = query(left, b, mid, i, j);
         int ret2 = query(right, mid+1, e, i, j);
         return max(ret1, ret2);
    }
    void update(int i, int val)
    {
        update(1, 0, vec.size()-1, i, val);
    }
    void update(int node, int b, int e, int i, int newvalue) // update
    {
        if(i > e || i < b)
            return;
        if(b >= i && e <= i)
        {
            seg[node] = newvalue;
            return;
        }
        int left = 2*node;
        int right = left+1;
        int mid = (b+e)/2;
        update(left, b, mid, i, newvalue);
        update(right, mid+1, e, i, newvalue);
        seg[node] = max(seg[left], seg[right]);
    }
    void clear()
    {
        vec.clear();
        seg.clear();
    }
};

vector <SegTree> heavyChains(MAX);


int dfs(int node, int parent, int d)
{
    subSize[node] = 1;
    depth[node] = d;
    for(auto &x : adj[node])
    {
        int child = x.first;
        int weight = x.second;
        if(child == parent) continue;
        par[child] = node;
        val[child] = weight;
        edge[mp[{child, node}]] = child;
        subSize[node] = max(subSize[node], 1 + dfs(child, node, d+1));
        if(subSize[node] == subSize[child] + 1)
            swap(adj[node][0], x);
    }
    return subSize[node];
}

void createChain(int node, int parent, int curr)
{
    location[node] = {curr, vect[curr].size()};
    vect[curr].push_back(val[node]);
    if(vect[curr].size() == 1) treeFirst[curr] = node;
    for(int i = 0 ; i < adj[node].size() ; i++)
    {
        int child = adj[node][i].first;
        if(child == parent) continue;
        if(i == 0) createChain(child, node, curr);
        else createChain(child, node, ++vCnt);
    }
    if(adj[node].size() == 1 && parent != -1)
        heavyChains[curr].build(vect[curr]);
}

int askMe(int u, int v)
{
    if(u == v) return 0;
    if(location[u].first == location[v].first)
    {
        if(depth[u] > depth[v]) swap(u, v);
        return heavyChains[location[u].first].query(location[u].second + 1, location[v].second);
    }
    if(depth[u] - location[u].second < depth[v] - location[v].second)
        swap(u, v);
    return max(heavyChains[location[u].first].query(0, location[u].second), askMe(par[treeFirst[location[u].first]], v));
}

void updateEdge(int indx, int value)
{
    int node = edge[indx];
    val[node] = value;
    heavyChains[location[node].first].update(location[node].second, value);
}

void clearStuff()
{
    for(int i = 0 ; i <= vCnt ; i++)
    {
        vect[i].clear();
        heavyChains[i].clear();
    }
    mp.clear();
    for(int i = 0 ; i <= n ; i++)
        adj[i].clear();
    vCnt = 0;
}


int solve(int testcase)
{
    clearStuff();
    cin >> n;
    for(int i = 0 ; i < n ; i++)
    {
        adj[i].clear();
        par[i] = i;
    }
    for(int i = 0 ; i < n-1 ; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
        mp[{u,v}] = i+1;
        mp[{v,u}] = i+1;
    }
    dfs(1, -1, 1);
    createChain(1, -1, 0);
    // for(int i = 0 ; i <= vCnt ; i++)
    // {
    //     for(int j = 0 ; j < vect[i].size() ; j++)
    //         cout << vect[i][j] << " \n"[j == vect[i].size()-1];
    // }
    string q;
    int u, v;
    while(1)
    {
        cin >> q;
        if(q == "DONE") break;
        else if(q == "QUERY")
        {
            cin >> u >> v;
            cout << askMe(u, v) << endl;
        }
        else
        {
            cin >> u >> v;
            updateEdge(u, v);
        }
    }
    return 0;
}

signed main()
{
    #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //cout.tie(NULL);

    // solve(0);
    TESTS
    return 0;
}