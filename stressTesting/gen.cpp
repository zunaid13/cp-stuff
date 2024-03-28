// generating a tree in a not-so-stupid way
#include <bits/stdc++.h>
using namespace std;

int rand(int a, int b) {
    return a + rand() % (b - a + 1);
}

int main(int argc, char* argv[]) {
    srand(atoi(argv[1]));
    cout << 1 << endl;
    int n = rand(3, 7), d = rand(3, 10);
    cout << n << " " << d << endl;
    for(int i = 0 ; i < n ; i++)
    {
        cout << rand(1, 5) << " " << rand(1, 5) << endl;
    }
}