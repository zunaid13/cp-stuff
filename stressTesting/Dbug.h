#include <bits/stdc++.h>
#include "ext/pb_ds/assoc_container.hpp"
#include "ext/pb_ds/tree_policy.hpp"

using namespace __gnu_pbds;
using namespace std;
using ll = long long;

#define debug_header

#ifdef _WIN32
#include <windows.h> // for win32 API functions
enum Color
{
    BLACK, RESET = 7, GREY = 8, BLUE, GREEN, CYAN, RED, PURPLE, LIGHT_YELLOW, WHITE
};
void setTextColor(Color color)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}
#else // For Linux
enum Color
{
    RED = 31, GREEN, BLUE = 34, RESET = 37, CYAN= 96, WHITE = 97
};
void setTextColor(Color color)
{
    string s = "\033[0;" + to_string(color) + "m";
    cerr << s;
}
#endif

void show_val(string s) { cerr << "\"" << s << "\""; }
void show_val(char c) { cerr << "\'" << c << "\'"; }
void show_val(unsigned char c) { cerr << "\'" << c << "\'"; }
void show_val(int i) { cerr << i; }
void show_val(bool i) { cerr << i; }
void show_val(unsigned int i) { cerr << i; }
void show_val(double i) { cerr << i; }
void show_val(float i) { cerr << i; }
void show_val(long double i) { cerr << i; }
void show_val(long long i) { cerr << i; }
void show_val(unsigned long long i) { cerr << i; }
void show_val(const char *p) { cerr << "\"" << p << "\""; }
void show_val(char *p) { cerr << "\"" << p << "\""; }
template <typename T, typename V>
void show_val(pair<T, V> p);
template <typename T>
void show_val(stack<T> q);
template <typename T>
void show_val(queue<T> q);
template <typename T, size_t N>
void show_val(const T (&t)[N]);
template <typename T>
void show_val(T t);
template <typename... Args>
void show_val(const std::tuple<Args...> &t);
template <typename T>
void show_val(complex<T> c);
template <typename T>
void show_val(priority_queue<T> q);
template <typename T>
void show_val(set<T> t);
template <typename T>
void show_val(unordered_set<T> t);
template <typename T>
void show_val(multiset<T> t);
template <typename K, typename V>
void show_val(map<K, V> t);
template <typename K, typename V>
void show_val(multimap<K, V> t);
template <typename K, typename V>
void show_val(unordered_map<K, V> t);
template <typename T>
void show_val(deque<T> t);
template <typename T>
void show_val(vector<T> t);
template <typename T, size_t N>
void show_val(array<T,N> t);
template <typename T>
void show_val(valarray<T> t);
template<class T>
void show_val(tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update> t);

//! Complex
template <typename T>
void show_val(complex<T> c)
{
    cerr << "{";
    show_val(c.real());
    cerr << ", ";
    show_val(c.imag());
    cerr << "}";
}

//! Tuple
template <typename Tuple, std::size_t N>
struct TuplePrinter
{
    static void print(Tuple t)
    {
        TuplePrinter<Tuple, N - 1>::print(t);
        std::cout << ", ";
        show_val(get<N - 1>(t));
    }
};
template <typename Tuple>
struct TuplePrinter<Tuple, 1>
{
    static void print(const Tuple &t) { show_val(get<0>(t)); }
};
template <typename... Args>
void show_val(const std::tuple<Args...> &t)
{
    cerr << "{";
    TuplePrinter<decltype(t), sizeof...(Args)>::print(t);
    cerr << "}";
}

//! Range based
template <typename T, size_t N>
void show_val(const T (&t)[N])
{
    cerr << "{";
    for (size_t i = 0; i < N; i++)
    {
        show_val(t[i]);
        if (i + 1 < N)
            cerr << ", ";
    }
    cerr << "}";
}
//! "foreach" loop
template <typename T>
void show_val(set<T> t)
{
    cerr << "{";
    bool f = false;
    for (auto &x : t)
    {
        if (f)
            cerr << ", ";
        f = true;
        show_val(x);
    }
    cerr << "}";
}
template <typename T>
void show_val(unordered_set<T> t)
{
    cerr << "{";
    bool f = false;
    for (auto &x : t)
    {
        if (f)
            cerr << ", ";
        f = true;
        show_val(x);
    }
    cerr << "}";
}
template <typename T>
void show_val(multiset<T> t)
{
    cerr << "{";
    bool f = false;
    for (auto &x : t)
    {
        if (f)
            cerr << ", ";
        f = true;
        show_val(x);
    }
    cerr << "}";
}
template <typename K, typename V>
void show_val(map<K, V> t)
{
    cerr << "{";
    bool f = false;
    for (auto &x : t)
    {
        if (f)
            cerr << ", ";
        f = true;
        show_val(x);
    }
    cerr << "}";
}
template <typename K, typename V>
void show_val(multimap<K, V> t)
{
    cerr << "{";
    bool f = false;
    for (auto &x : t)
    {
        if (f)
            cerr << ", ";
        f = true;
        show_val(x);
    }
    cerr << "}";
}
template <typename K, typename V>
void show_val(unordered_map<K, V> t)
{
    cerr << "{";
    bool f = false;
    for (auto &x : t)
    {
        if (f)
            cerr << ", ";
        f = true;
        show_val(x);
    }
    cerr << "}";
}
template <typename T>
void show_val(deque<T> t)
{
    cerr << "{";
    bool f = false;
    for (auto &x : t)
    {
        if (f)
            cerr << ", ";
        f = true;
        show_val(x);
    }
    cerr << "}";
}
template <typename T>
void show_val(vector<T> t)
{
    cerr << "{";
    bool f = false;
    for (auto &x : t)
    {
        if (f)
            cerr << ", ";
        f = true;
        show_val(x);
    }
    cerr << "}";
}
template <typename T, size_t N>
void show_val(array<T,N> t)
{
    cerr << "{";
    bool f = false;
    for (auto &x : t)
    {
        if (f)
            cerr << ", ";
        f = true;
        show_val(x);
    }
    cerr << "}";
}
template <typename T>
void show_val(valarray<T> t)
{
    cerr << "{";
    bool f = false;
    for (auto &x : t)
    {
        if (f)
            cerr << ", ";
        f = true;
        show_val(x);
    }
    cerr << "}";
}
template<class T>
void show_val(tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update> t)
{
    cerr << "{";
    bool f = false;
    for (auto &x : t)
    {
        if (f)
            cerr << ", ";
        f = true;
        show_val(x);
    }
    cerr << "}";
}

//! Pair
template <typename T, typename V>
void show_val(pair<T, V> p)
{
    cerr << "{";
    show_val(p.first);
    cerr << ", ";
    show_val(p.second);
    cerr << "}";
}

//! queue
template <typename T>
void show_val(queue<T> q)
{
    cerr << "{";
    for (; q.size();)
    {
        show_val(q.front());
        q.pop();
        if (q.size())
            cerr << ", ";
    }
    cout << "}";
}

//! stack
template <typename T>
void show_val(stack<T> q)
{
    cerr << "{";
    for (; q.size();)
    {
        show_val(q.top());
        q.pop();
        if (q.size())
            cerr << ", ";
    }
    cout << "}";
}
//! Priority Queue
template <typename T>
void show_val(priority_queue<T> q)
{
    cerr << "{";
    for (; q.size();)
    {
        show_val(q.top());
        q.pop();
        if (q.size())
            cerr << ", ";
    }
    cout << "}";
}

//! Other types
template<typename T>
void show_val(T t)
{
    t = t;
    setTextColor(RED);
    cerr << "Unsupported-type";
    setTextColor(WHITE);
}

int extract_comma_after_first_variable(string s)
{
    stack<char> stk;
    int i = 0;
    while(i < (int)s.size())
    {
        if(stk.empty() and s[i] == ',') return i;
        if(s[i] == '(' or s[i] == '{' or s[i] == '[') stk.push(s[i]);
        if(s[i] == ')' or s[i] == '}' or s[i] == ']') stk.pop();
        i++;
    }
    return i;
}

//! dbg
void dbo(string s) {s = s;/* Getting rid of warnings*/}
template <typename T, typename... Args>
void dbo(string s, T &t, Args &...args)
{
    auto it = remove(s.begin(), s.end(), ' ');
    s.erase(it, s.end());
    int c_pos = extract_comma_after_first_variable(s);
    setTextColor(CYAN);
    cerr << "\t" << s.substr(0, c_pos);
    setTextColor(WHITE);
    cerr << " = ";
    s = s.substr(c_pos + (c_pos < (int)s.size()));
    show_val(t);
    cerr << endl;
    if (sizeof...(args))
        dbo(s, args...);
}
template <typename T, typename... Args>
void dbo(string s, T &&t, Args &&...args)
{
    auto it = remove(s.begin(), s.end(), ' ');
    s.erase(it, s.end());
    int c_pos = extract_comma_after_first_variable(s);
    setTextColor(CYAN);
    cerr << "\t" << s.substr(0, c_pos);
    setTextColor(WHITE);
    cerr << " = ";
    s = s.substr(c_pos + (c_pos < (int)s.size()));
    show_val(t);
    cerr << endl;
    if (sizeof...(args))
        dbo(s, args...);
}

#ifdef debug_header
#define dbg(_param...)                               \
    {setTextColor(GREEN);                        \
    cerr << "Line " << __LINE__ << ":" << endl; \
    setTextColor(WHITE);                        \
    dbo(#_param, _param);                                 \
    setTextColor(RESET);}
#else
#define dbg(_param...)
#endif