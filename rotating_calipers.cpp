#include <iostream>
#include <vector>
#include <cstdio>
#include <bits/stdc++.h>
typedef long long i64;
using namespace std;

// FIND THE LARGEST DISTANCE BETWEEN ANY 2 POINTS IN 2D PLANE

i64 cross(pair<i64, i64> P, pair<i64, i64> Q, pair<i64, i64> R) // if return >0 then point R is upper of lineseg PQ else down
{
    return (Q.first - P.first) * (R.second - P.second) - (R.first - P.first) * (Q.second - P.second);
}
void hull(vector<pair<i64, i64>> &P, vector<pair<i64, i64>> &L, vector<pair<i64, i64>> &U)
{
    int j = 0, k = 0, n = P.size();
    sort(P.begin(), P.end());
    U.resize(2 * n);
    L.resize(2 * n);
    for (int i = 0; i < n; i++)
    {
        while (j >= 2 && cross(L[j - 2], L[j - 1], P[i]) <= 0) // p[i] is making right turn we need left turn
            j--;
        while (k >= 2 && cross(U[k - 2], U[k - 1], P[i]) >= 0) // p[i] is making left turn we need right
            k--;
        L[j++] = P[i];
        U[k++] = P[i];
    }
    U.resize(k);
    L.resize(j);
}
i64 fun(pair<i64, i64> P, pair<i64, i64> Q)
{
    return (P.first - Q.first) * (P.first - Q.first) + (P.second - Q.second) * (P.second - Q.second);
}

int main()
{
    i64 t, n, k1, k2;
    vector<pair<i64, i64>> v, U, L;
    // cin >> t;
    t = 1;
    while (t--)
    {
        v.clear();
        U.clear();
        L.clear();
        cin >> n;
        for (int i = 0; i < n; i++)
            cin >> k1 >> k2, v.push_back(make_pair(k1, k2));
        if (n == 1)
        {
            cout << "0\n";
            continue;
        }
        hull(v, L, U);

        /*cout<<"lower hull\n";
        for(int i=0;i<L.size();i++)
            cout<<L[i].first<<" "<<L[i].second<<endl;
        cout<<"upper hull"<<endl;
        for(int i=0;i<U.size();i++)
            cout<<U[i].first<<" "<<U[i].second<<endl;*/
        int i = 0, j, m;
        j = L.size() - 1;
        m = U.size() - 1;
        i64 dist = -1;
        while (i < m || j > 0)
        {
            dist = max(dist, fun(U[i], L[j]));
            if (i == m)
                j--;
            else if (j == 0)
                i++;
            else
            {
                if ((U[i + 1].second - U[i].second) * (L[j].first - L[j - 1].first) > (L[j].second - L[j - 1].second) * (U[i + 1].first - U[i].first))
                    i++;
                else
                    j--;
            }
        }
        cout << fixed << setprecision(7) <<  sqrt(dist) << endl;
    }
}