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
#include <ext/pb_ds/assoc_container.hpp> // this is for the gp_hash_table
 
using namespace std;
 
typedef long long LL;
typedef long double LD;
#define MAX (5002)
// #define MAX 10
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
 

namespace Hashing {
    #define ff first
    #define ss second

    const pii M = {1e9+7, 1e9+9};        ///Should be large primes
    const LL base = 1259;                ///Should be larger than alphabet size
    const int N = 1e6 + 2;                 ///Highest length of string

    pii operator+ (const pii& a, LL x)     {return {a.ff + x, a.ss + x};}
    pii operator- (const pii& a, LL x)     {return {a.ff - x, a.ss - x};}
    pii operator* (const pii& a, LL x)     {return {a.ff * x, a.ss * x};}
    pii operator+ (const pii& a, pii x)    {return {a.ff + x.ff, a.ss + x.ss};}
    pii operator- (const pii& a, pii x)    {return {a.ff - x.ff, a.ss - x.ss};}
    pii operator* (const pii& a, pii x)    {return {a.ff * x.ff, a.ss * x.ss};}
    pii operator% (const pii& a, pii m)    {return {a.ff % m.ff, a.ss % m.ss};}
    ostream& operator<<(ostream& os, pii hash) {
        return os<<"("<<hash.ff<<", "<<hash.ss<<")";
    }
    pii pb[N];      ///powers of base mod M

    ///Call pre before everything
    void hashPre() {
        pb[0] = {1,1};
        for (int i=1; i<N; i++)     pb[i] = (pb[i-1] * base)%M;
    }

    ///Calculates hashes of all prefixes of s including empty prefix
    vector<pii> hashList(string s) {
        int n = s.size();
        vector<pii> ans(n+1);
        ans[0] = {0,0};
        for (int i=1; i<=n; i++)    ans[i] = (ans[i-1] * base + s[i-1])%M;
        return ans;
    }

    ///Calculates hash of substring s[l..r] (1 indexed)
    pii substringHash(const vector<pii> &hashlist, int l, int r) {
        return (hashlist[r]+(M-hashlist[l-1])*pb[r-l+1])%M;
    }

    ///Calculates Hash of a string
    pii Hash (string s) {
        pii ans = {0,0};
        for (int i=0; i<s.size(); i++)  ans=(ans*base + s[i])%M;
        return ans;
    }

    ///Tested on https://toph.co/p/palindromist
    ///appends c to string
    pii append(pii cur, char c) {
        return (cur*base + c)%M;
    }

    ///Tested on https://toph.co/p/palindromist
    ///prepends c to string with size k
    pii prepend(pii cur, int k, char c) {
        return (pb[k]*c + cur)%M;
    }

    ///Tested on https://toph.co/p/chikongunia
    ///replaces the i-th (0-indexed) character from right from a to b;
    pii replace(pii cur, int i, char a, char b) {
        return cur + pb[i] * (M+b-a)%M;
    }

    ///Erases c from front of the string with size len
    pii pop_front(pii hash, int len, char c) {
        return (hash + pb[len-1]*(M-c))%M;
    }

    ///Tested on https://toph.co/p/palindromist
    ///concatenates two strings where length of the right is k
    pii concat(pii left, pii right, int k) {
        return (left*pb[k] + right)%M;
    }

    pii power (const pii& a, LL p) {
        if (p==0)   return {1,1};
        pii ans = power(a, p/2);
        ans = (ans * ans)%M;
        if (p%2)    ans = (ans*a)%M;
        return ans;
    }

    pii inverse(pii a)  {
        if (M.ss == 1)  return power(a, M.ff-2);
        return power(a, (M.ff-1)*(M.ss-1)-1);
    }

    ///Erases c from the back of the string
    pii invb = inverse({base, base});
    pii pop_back(pii hash, char c) {
        return ((hash-c+M)*invb)%M;
    }

    ///Tested on https://toph.co/p/palindromist
    ///Calculates hash of string with size len repeated cnt times
    ///This is O(log n). For O(1), pre-calculate inverses
    pii repeat(pii hash, int len, LL cnt) {
        pii mul = ((pb[len*cnt]-1+M) * inverse(pb[len]-1+M))%M;
        pii ans = (hash*mul);
        if (pb[len].ff == 1)    ans.ff = hash.ff*cnt;
        if (pb[len].ss == 1)    ans.ss = hash.ss*cnt;
        return ans%M;
    }
}


using namespace Hashing;

// this following lines of code is for gp-hashtable that is faster than unordered map
// remember to include the file first (at the top)
using namespace __gnu_pbds;
gp_hash_table<int, int> table_for_int_to_int; // use similar to unordered map
// for storing pairs of int, use following hash and declaration
struct chash {
    int operator()(pii x) const { return x.first* 31 + x.second; }
};
gp_hash_table<pii, int, chash> table_for_pair_to_int;
////////////////////////////////////////////

string inp;
vector <pii> myHashList;
int position_of_ans;
int ans = 0;

bool check(int len)
{
    gp_hash_table <pii, bool, chash> exists;
    // unordered_map <pii, int, chash> exists;
    // map <pii, int> exists;
    pii hashV;
    for(int i = 0 ; i + len - 1 < inp.size() ; i++)
    {
        hashV = substringHash(myHashList, i+1, i+len);
        if(exists[hashV] != false)
        {
            position_of_ans = i;
            ans = len;
            return true;
        }
        exists[hashV] = true;
    }
    return false;
}

int solve(int testcase)
{
    hashPre();
    cin >> inp;
    myHashList = hashList(inp);
    int l = 0, h = inp.size()-1;
    while(l <= h)
    {
        int mid = (h + l) / 2;
        if(check(mid))
            l = mid+1;
        else
            h = mid-1;
    }
    if(ans == 0)
    {
        cout << -1 << endl;
        return 0;
    }
    for(int i = position_of_ans ; i < position_of_ans + ans ; i++)
        cout << inp[i];
    cout << endl;
    return 0;
}
 
signed main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // cout.tie(NULL);
 
    solve(0);
    //TESTS
    return 0;
}