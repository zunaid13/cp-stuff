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
#ifdef LOCAL
 #include "Dbug.h"
#else
 #define dbg(...)
#endif

using namespace std;

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
const LL MAX = 2005;
const LL MOD = (1e9) + 7;
const LL INF = (1e15) + 5;

int n;
vector <int> board[3];

/*
  complexity = O(n)
  computes satisfiability for clauses (a OR b)
  1st and 3rd parameter = a, b
  2nd and 4th parameter = not A, not B (false for not)
  0 based indexing so pass n+1 for ts
*/

namespace atcoder 
{
  namespace internal 
  {
 
    template <class E> struct csr {
        std::vector<int> start;
        std::vector<E> elist;
        csr(int n, const std::vector<std::pair<int, E>>& edges)
            : start(n + 1), elist(edges.size()) {
            for (auto e : edges) {
                start[e.first + 1]++;
            }
            for (int i = 1; i <= n; i++) {
                start[i] += start[i - 1];
            }
            auto counter = start;
            for (auto e : edges) {
                elist[counter[e.first]++] = e.second;
            }
        }
    };

    // Reference:
    // R. Tarjan,
    // Depth-First Search and Linear Graph Algorithms
    struct scc_graph {
      public:
        scc_graph(int n) : _n(n) {}

        int num_vertices() { return _n; }

        void add_edge(int from, int to) { edges.push_back({from, {to}}); }

        // @return pair of (# of scc, scc id)
        std::pair<int, std::vector<int>> scc_ids() {
            auto g = csr<edge>(_n, edges);
            int now_ord = 0, group_num = 0;
            std::vector<int> visited, low(_n), ord(_n, -1), ids(_n);
            visited.reserve(_n);
            auto dfs = [&](auto self, int v) -> void {
                low[v] = ord[v] = now_ord++;
                visited.push_back(v);
                for (int i = g.start[v]; i < g.start[v + 1]; i++) {
                    auto to = g.elist[i].to;
                    if (ord[to] == -1) {
                        self(self, to);
                        low[v] = std::min(low[v], low[to]);
                    } else {
                        low[v] = std::min(low[v], ord[to]);
                    }
                }
                if (low[v] == ord[v]) {
                    while (true) {
                        int u = visited.back();
                        visited.pop_back();
                        ord[u] = _n;
                        ids[u] = group_num;
                        if (u == v) break;
                    }
                    group_num++;
                }
            };
            for (int i = 0; i < _n; i++) {
                if (ord[i] == -1) dfs(dfs, i);
            }
            for (auto& x : ids) {
                x = group_num - 1 - x;
            }
            return {group_num, ids};
        }

        std::vector<std::vector<int>> scc() {
            auto ids = scc_ids();
            int group_num = ids.first;
            std::vector<int> counts(group_num);
            for (auto x : ids.second) counts[x]++;
            std::vector<std::vector<int>> groups(ids.first);
            for (int i = 0; i < group_num; i++) {
                groups[i].reserve(counts[i]);
            }
            for (int i = 0; i < _n; i++) {
                groups[ids.second[i]].push_back(i);
            }
            return groups;
        }

      private:
        int _n;
        struct edge {
            int to;
        };
        std::vector<std::pair<int, edge>> edges;
    };
  }  // namespace internal
}  // namespace atcoder
 
namespace atcoder {
 
  // Reference:
  // B. Aspvall, M. Plass, and R. Tarjan,
  // A Linear-Time Algorithm for Testing the Truth of Certain Quantified Boolean
  // Formulas
  struct two_sat {
    public:
      two_sat() : _n(0), scc(0) {}
      two_sat(int n) : _n(n), _answer(n), scc(2 * n) {}
  
      void add_clause(int i, bool f, int j, bool g) {
          assert(0 <= i && i < _n);
          assert(0 <= j && j < _n);
          scc.add_edge(2 * i + (f ? 0 : 1), 2 * j + (g ? 1 : 0));
          scc.add_edge(2 * j + (g ? 0 : 1), 2 * i + (f ? 1 : 0));
      }
      bool satisfiable() {
          auto id = scc.scc_ids().second;
          for (int i = 0; i < _n; i++) {
              if (id[2 * i] == id[2 * i + 1]) return false;
              _answer[i] = id[2 * i] < id[2 * i + 1];
          }
          return true;
      }
      std::vector<bool> answer() { return _answer; }
  
    private:
      int _n;
      std::vector<bool> _answer;
      internal::scc_graph scc;
  };
}
 

int solve(int testcase)
{
    cin >> n;
    for(int i = 0 ; i < 3 ; i++)
    {
        board[i].clear();
        for(int j = 0 ; j < n ; j++)
        {
            int inp;
            cin >> inp;
            board[i].push_back(inp);
        }
    }
    atcoder::two_sat ts(n+1);
    for(int i = 0 ; i < n ; i++)
    {
      ts.add_clause(abs(board[0][i]), board[0][i] > 0, abs(board[1][i]), board[1][i] > 0);
      ts.add_clause(abs(board[1][i]), board[1][i] > 0, abs(board[2][i]), board[2][i] > 0);
      ts.add_clause(abs(board[2][i]), board[2][i] > 0, abs(board[0][i]), board[0][i] > 0);
    }
    if(ts.satisfiable()) cout << "YES" << endl;
    else cout << "NO" << endl;
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
    TESTS
    return 0;
}