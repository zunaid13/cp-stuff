#include <bits/stdc++.h>
using namespace std;

std::mt19937_64 rng(std::chrono::steady_clock::now().time_since_epoch().count());

int rand(int a, int b, std::mt19937_64* param_rng = nullptr) {
    if (param_rng == nullptr) {
        param_rng = &rng;
    }
    std::uniform_int_distribution<int> dist(a, b);
    return dist(*param_rng);
}

vector <int> generateVector(int size, int lowerLimit, int upperLimit)
{
    vector <int> ret(size);
    for(auto &x : ret)
        x = rand(lowerLimit, upperLimit);
    return ret;
}

vector <int> generatePermutation(int size)
{
    vector <int> ret(size);
    for(int i = 0 ; i < size ; i++)
        ret[i] = i+1;
    // Shuffle the vector
    shuffle(ret.begin(), ret.end(), rng);
    return ret;
}

vector<int> generateUniqueVector(int size, int lowerLimit, int upperLimit)
{
    // Validate the requested size
    if (size > (upperLimit - lowerLimit + 1)) {
        throw invalid_argument("Size is larger than the range of unique values.");
    }

    // Generate a permutation of the range [lowerLimit, upperLimit]
    vector<int> perm = generatePermutation(upperLimit - lowerLimit + 1);
    
    // Extract the first 'size' elements
    vector<int> uniqueVector(perm.begin(), perm.begin() + size);
    
    // Adjust values to fit within [lowerLimit, upperLimit]
    for (auto &val : uniqueVector) {
        val += lowerLimit - 1;
    }

    return uniqueVector;
}

vector <pair<int, int>> generateTree(int size)
{
    int n = size;
    vector<pair<int,int>> edges;
    for(int i = 2; i <= n; ++i) {
        edges.emplace_back(rand(1, i - 1), i);
    }
    
    vector<int> perm(n + 1); // re-naming vertices
    for(int i = 1; i <= n; ++i) {
        perm[i] = i;
    }
    random_shuffle(perm.begin() + 1, perm.end());
    
    random_shuffle(edges.begin(), edges.end()); // random order of edges
    
    vector <pair<int, int>> ret;

    for(pair<int, int> edge : edges) {
        int a = edge.first, b = edge.second;
        if(rand() % 2) {
            swap(a, b); // random order of two vertices
        }
        ret.emplace_back(perm[a], perm[b]);
    }
    return ret;
}

vector <int> generateOneRootedTree(int size)
{
    int n = size;
    vector <pair<int, int>> edges = generateTree(size);
    vector <int> ret(size-1);
    vector <vector<int>> adj(size+1);
    for(auto [x, y] : edges)
    {
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    auto dfs = [&](int node, int parent = 0) -> void
    {
        stack <pair<int, int>> recursion;
        recursion.push({node, parent});
        while(recursion.size())
        {
            auto [n, p] = recursion.top();
            recursion.pop();
            if(n != 1)
                ret[n-2] = p;
            for(auto child : adj[n])
            {
                if(child == p) continue;
                recursion.push({child, n});
            }
        }
    };
    dfs(1, 0);
    return ret;
}