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
const int MAX = 2*(1e5)+5;
// const int MAX = 11;
const int MOD = (1e9) + 7;
const int INF = (1e15) + 5;


int n;
vector <int> adj[MAX];
vector <pii> hashVals[MAX]; // stores {subtree-hash, subtree-root}
map <vector <int>, int> ID;
int cnt;

int hashTree(int node, int parent)
{
    vector <int> sub;
    for(auto child : adj[node])
    {
        if(child == parent) continue;
        hashVals[node].push_back({hashTree(child, node), child});
        sub.emplace_back(hashVals[node].back().first);
    }
    sort(all(sub));
    if(!ID.count(sub)) ID[sub] = ++cnt;
    return ID[sub];
}

bool checkSymmetry(int node)
{
    unordered_set <int> oddVals;
    for(auto x : hashVals[node])
    {
        if(oddVals.find(x.first) == oddVals.end())
            oddVals.insert(x.first);
        else oddVals.erase(x.first);
    }
    
    if(oddVals.size() == 0) return true;
    if(oddVals.size() > 1) return false;
    bool ret = false;
    for(auto x : hashVals[node])
        if(x.first == *oddVals.begin())
            ret |= checkSymmetry(x.second);
    return ret;
}

int solve(int testcase)
{
    cin >> n;
    for(int i = 1 ; i <= n ; i++)
    {
        adj[i].clear();
        hashVals[i].clear();
    }
    ID.clear();
    cnt = 1;
    ID[vector<int>(0)] = cnt;
    for(int i = 0 ; i < n-1 ; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    hashTree(1, 0);
    if(checkSymmetry(1)) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}

signed main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //cout.tie(NULL);

    //solve(0);
    TESTS
    return 0;
}