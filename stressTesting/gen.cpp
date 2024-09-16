// generating a tree in a not-so-stupid way
#include <bits/stdc++.h>
using namespace std;

// int rand(int a, int b) {
//     return a + rand() % (b - a + 1);
// }


int rand(int a, int b, std::mt19937_64 rng) {
    std::uniform_int_distribution<int> dist(a, b);
    return dist(rng);
}

#define pii pair<int, int>

int main(int argc, char* argv[]) {
    std::mt19937_64 rng(std::chrono::steady_clock::now().time_since_epoch().count());
    // srand(atoi(argv[1]));
    cout << 1 << endl;
    int n = 7;


    // Shuffle the vector
    // std::shuffle(numbers.begin(), numbers.end(), rng);

    cout << n << endl;
    for(int i = 0 ; i < n ; i++)
        cout << rand(1, 20, rng) << " ";
    cout << endl;
    for(int i = 0 ; i < n ; i++)
        cout << rand(1, 20, rng) << " ";
    cout << endl;
    return 0;
}

/*
std::mt19937_64 rng(std::chrono::steady_clock::now().time_since_epoch().count());

int rand(int a, int b) {
    std::uniform_int_distribution<int> dist(a, b);
    return dist(rng);
}
*/