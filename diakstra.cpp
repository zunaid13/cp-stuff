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
#define MAX 200005
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
#define INF 1e18

vector <pair<int, int>> adj[MAX];
vector <int> dist(MAX);
int n, m;
int x, y, z;
 
void dijkstra(int src)
{   
    for(int i = 1 ; i <= 2*n ; i++) // initialization
        dist[i] = INF;
    dist[src] = 0;
    // this is min prio queue (2nd and 3rd parameters are for min-prio)
    priority_queue <pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, 1});
    while(!pq.empty())
    {
        int u = pq.top().second; // nearest unvisited node
        int d = pq.top().first; //  distance from the src to nearest node (unvisited)
        pq.pop();
        if(dist[u] != d) continue; // already visited previously so value is changed
        for(auto v : adj[u])
        {
            if(dist[u] + v.second < dist[v.first])
            {
                dist[v.first] = dist[u] + v.second;
                pq.push({dist[v.first], v.first});
            }
        }
    }
}

int solve(int testcase)
{
    cin >> n >> m;
    for(int i = 0 ; i < m ; i++)
    {
        cin >> x >> y >> z;
        adj[x].push_back({y, z});
        adj[n+y].push_back({n+x, z});
    }
    for(int i = 1 ; i <= n ; i++)
        adj[i].push_back({i+n, 0});
    dijkstra(1);
    for(int i = 2 ; i <= n ; i++)
    {   // we check i+n because (i) will give wrong result
        if(dist[i+n] == INF) cout << -1 << " ";
        else cout << dist[i+n] << " ";
    }   // if we can go to (i) in small distance then (i+N) is auto updated
    cout << endl;
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