// generating a tree in a simple way
#include <bits/stdc++.h>
using namespace std;

int rand(int a, int b) {
    return a + rand() % (b - a + 1);
}

int main(int argc, char* argv[]) {
    srand(atoi(argv[1]));
    // cout << 1 << endl;
    int n = rand(10, 15), q = rand(2, 5);
    // cout << n << " " << q << endl;
    // for(int i = 0 ; i < n ; i++)
    // {
    //     cout << rand(0, 1) << " ";
    // }
    // cout << endl;
    cout << n << endl;
    for(int i = 2; i <= n; ++i) {
        printf("%d %d\n", rand(1, i - 1), i);
    }
    // for(int i = 0 ; i < q ; i++)
    // {
    //     cout << rand(1, n) << endl;
    // }
}