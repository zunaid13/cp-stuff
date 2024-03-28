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

#warning CHANGE INT-LONG-LONG IN CASE OF ORDERED SET
#warning CHANGE MAX VALUE
#warning change endl and FastIO for interactive
typedef long long LL;
typedef long double LD;
#define pi acos(-1)
#define whatis(x) cout << #x << " is " << x << "\n";
#define all(x) begin(x), end(x)
#define endl "\n"
#define TESTS int test; cin>>test; for(int kase = 1 ; kase <= test ; kase++) solve(kase);
#define CASEOUT cout << "Case " << testcase << ": ";
#define int long long
#define pii pair<int,int>
#define pll pair<LL,LL>
const LL MAX = 100;
const LL MOD = (1e9) + 7;
const LL INF = (1e15) + 5;

void fileIO()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
}

void fastIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //cout.tie(NULL);
}

int n, d, currentTime, served;
vector <int> k, s, completedServe;

struct priority{
    int indx, k, s, initial, time;
    priority(int indx, int k, int s, int initial, int time) : indx(indx), k(k), s(s), initial(initial), time(time) {}
};

int solve(int testcase)
{
    currentTime = served = 0;
    cin >> n >> d;
    completedServe.resize(n);
    k.resize(n);
    s.resize(n);
    fill(all(completedServe), 0);
    for(int i = 0 ; i < n ; i++)
        cin >> k[i] >> s[i];
    // Using a lambda function directly in the priority queue declaration
    auto cmp = [](priority a, priority b) {
        if (a.initial != b.initial && a.initial != -1 && b.initial != -1) return a.initial > b.initial;
        if (a.k != b.k) return a.k < b.k;
        return a.time > b.time;
    };

    priority_queue<priority, vector<priority>, decltype(cmp)> pq(cmp);
    for(int i = 0 ; i < n ; i++)
    {
        pq.push(priority(i, k[i], s[i], i, currentTime++));
    }
    vector <vector <int>> t(d+1);
    for(int i = 1 ; i <= d ; i++)
    {
        // first serve the person
        auto [sindx, sk, ss, sinit, stime] = pq.top();
        if(completedServe[sindx] == 0)
        {
            completedServe[sindx] = 1;
            served++;
        }
        pq.pop();
        if(i + ss <= d)
            t[i+ss].push_back(sindx);
        // now enter old guys
        for(auto x : t[i])
        {
            pq.push(priority(x, k[x], s[x], -1, currentTime++));
        }
        t[i].clear();
        if(served == n)
        {
            cout << i << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}

signed main()
{
    #ifdef LOCAL
    fileIO();
    #endif

    fastIO();

    //solve(0);
    TESTS
    return 0;
}