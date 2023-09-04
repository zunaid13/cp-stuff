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
const int MAX = 1e5 + 5;
const int MOD = (1e9) + 7;
const int INF = (1e15) + 5;



int n, m;
vector <int> adj[MAX]; // adj is needed for ANACHOR namespace
bool visited[MAX];
int sub[MAX], parent[MAX];
// for weighted graph see https://oj.uz/submission/739616
vector <int> SubTreeAns(MAX, INT_MAX);

void calculate_Subtree(int node, int parent = -1)
{
    sub[node] = 1;
    for(auto child : adj[node])
    {
        if(child != parent && !visited[child])
        {
            calculate_Subtree(child, node);
            sub[node] += sub[child];
        }
    }
}

int find_Centroid(int node, int maxSubtreeSize, int parent = -1)
{
    for(auto child : adj[node])
        if(child != parent && !visited[child] && sub[child] * 2 > maxSubtreeSize)
            return find_Centroid(child, maxSubtreeSize, node);
    return node;
}

// centroid decomposition routine -> 1 indexed
int decompose (int node = 1) {
  calculate_Subtree(node);
  int root = find_Centroid(node, sub[node]);
  visited[root] = true;
  parent[root] = root;
  for (auto child : adj[root]) 
    if (!visited[child]) 
        parent[decompose(child)] = root;
  return root;
}

namespace ANACHOR
{
    const int N = MAX, K = 20;
    int anc[N][K];
    int level[N];

    void setup(int u, int par) {
        level[u] = level[par]+1;
        anc[u][0] = par;
        for (int k=1; k<K; k++)     anc[u][k] = anc[anc[u][k-1]][k-1];

        for (int v: adj[u]) {
            if (v == par)   continue;
            setup(v, u);
        }
    }

    int lca(int u, int v) {
        if (level[u] > level[v])    swap(u, v);
        for (int k=K-1; k>=0; k--)
            if (level[u] + (1<<k) <= level[v])  v = anc[v][k];

        if (u == v) return u;
        for (int k=K-1; k>=0; k--)
            if (anc[u][k] != anc[v][k])
                u = anc[u][k], v = anc[v][k];
        return anc[u][0];
    }

    int getanc(int u, int d) {
        for (int k=0; k<K; k++)
            if (d & (1<<k))
                u = anc[u][k];
        return u;
    }

    int dist(int u, int v) {
        int g = lca(u, v);
        return level[u] + level[v] - 2*level[g];
    }
}

void colorRed(int node)
{
    SubTreeAns[node] = 0;
    int initialNode = node;
    while(parent[node] != node)
    {
        node = parent[node];
        int update = SubTreeAns[initialNode] + ANACHOR::dist(node, initialNode);
        SubTreeAns[node] = min(update, SubTreeAns[node]);
    }
}

int findRes(int node)
{
    int ans = SubTreeAns[node];
    int initialNode = node;
    while(parent[node] != node)
    {
        node = parent[node];
        int query = SubTreeAns[node] + ANACHOR::dist(node, initialNode);
        ans = min(ans, query);
    }
    return ans;
}

int solve(int testcase)
{
    cin >> n >> m;
    for (int i=0; i<n-1; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    ANACHOR::setup(1, 0);
    decompose();
    colorRed(1);
    while(m--)
    {
        int a, b;
        cin >> a >> b;
        if(a == 1) colorRed(b);
        else cout << findRes(b) << endl;
    }
    return 0;
}

signed main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //cout.tie(NULL);

    solve(0);
    //TESTS
    return 0;
}