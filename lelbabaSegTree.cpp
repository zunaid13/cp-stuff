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
#ifdef LOCAL
 #include "Dbug.h"
#else
 #define dbg(...)
#endif

// #warning CHANGE INT-LONG-LONG IN CASE OF ORDERED SET
// #warning CHANGE MAX VALUE
// #warning change endl and FastIO for interactive
typedef long long LL;
typedef long double LD;
#define pi acos(-1)
#define all(x) begin(x), end(x)
#define endl "\n"
#define TESTS int test; cin>>test; for(int kase = 1 ; kase <= test ; kase++) solve(kase);
#define CASEOUT cout << "Case " << testcase << ": ";
#define int long long
#define pii pair<int,int>
#ifdef LOCAL
 const LL MAX = 100;
#else
 const LL MAX = 1e2;
#endif
const LL MOD = (1e9) + 7;
const LL INF = (1e15) + 5;


class SegTree{
  private:
  const int N = 1000006;
  using DT = LL;
  using LT = LL;
  DT I = 0;
  LT None = 0;
  vector <DT> val;
  vector <LT> lazy;
  int L, R;

  DT merge(const DT &a, const DT &b) { return a + b; }
  
  void apply(const LT &uval, int s, int e, int u) {
    if (uval == None) return;
    val[u] += (e - s + 1) * uval;
    lazy[u] += uval;
  }
  
  void pull(int s, int e, int u) {
    val[u] = merge(val[u << 1], val[u << 1 | 1]);
  }
  
  void reset(int u) { lazy[u] = None; }
  
  DT get(int s, int e, int u) { return val[u]; }
  
  void push(int s, int e, int u) {
    if (s == e) return;
    apply(lazy[u], s, s + e >> 1, u << 1);
    apply(lazy[u], s + e + 2 >> 1, e, u << 1 | 1);
    reset(u);
  }
  
  void build(int s, int e, vector<DT> &v, int u = 1) {
    lazy[u] = None;
    if (s == e) {
      val[u] = v[s];
      return;
    }
    int m = s + e >> 1;
    build(s, m, v, u<<1);
    build(m + 1, e, v, u<<1|1);
    pull(s, e, u);
  }

  void update(int l, int r, LT uval, int s, int e, int u = 1) {
    if (l > e or s > r) return;
    if (l <= s and e <= r) {
      apply(uval, s, e, u);
      return;
    }
    push(s, e, u);
    int m = s+e >> 1;
    update(l, r, uval, s, m, u<<1);
    update(l, r, uval, m+1, e, u<<1|1);
    pull(s, e, u);
  }

  DT query(int l, int r, int s, int e, int u = 1) {
    if (l > e or s > r) return I;
    if (l <= s and e <= r) return get(s, e, u);
    push(s, e, u);
    int m = s+e >> 1;
    DT ql = query(l, r, s, m, u<<1),
       qr = query(l, r, m+1, e, u<<1|1);
    return merge(ql, qr);
  }

  public:
  void update(int l, int r, LT uval)
  {
    update(l, r, uval, L, R);
  }

  void pointUpdate(int indx, int uval)
  {
    int oldVal = query(indx, indx);
    update(indx, indx, uval-oldVal);
  }

  DT query(int l, int r)
  {
    return query(l, r, L, R);
  }
  void init(int _L, int _R, vector<DT> &v) {
    val.resize((v.size() + 1) * 4);
    lazy.resize((v.size() + 1) * 4);
    L = _L, R = _R;
    build(L, R, v);
  }
};



int solve(int testcase)
{
    return testcase;
}

signed main()
{
    #ifdef LOCAL
       freopen("in.txt", "r", stdin);
       freopen("out.txt", "w", stdout);
    #endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //cout.tie(NULL);

    //solve(0);
    //TESTS
    return 0;
}