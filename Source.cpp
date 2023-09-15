#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;
bool check(pair<int, int> x, pair<int, int> y) {
    if (x.second != y.second) {
        return x.second > y.second;
    }
    else return x.first < y.first;
}
bool check1(pair<int, int> x, pair<int, int> y) {
    if (x.second != y.second) {
        return x.second > y.second;
    }
    else return false;
}

int main() {
    int n; cin >> n;
    map<int, int> k;
    vector<pair<int, int>> m;
    int a[n];
    for (int i = 0; i < n; i++) {
        int u; cin >> u;
        k[u]++;
        a[i] = u;
    }
    for (auto x : k)
        m.push_back({ x.first,x.second });
    sort(m.begin(), m.end(), check);
    for (auto x : m) {
        for (int i = 0; i < x.second; i++) {
            cout << x.first << " ";
        }
    }
    cout << endl;
    m.clear();
    for (int x : a) {
        if (k[x] != 0) {
            m.push_back({ x,k[x] });
            k[x] = 0;
        }
    }
    stable_sort(m.begin(), m.end(), check1);
    for (auto x : m) {
        for (int i = 0; i < x.second; i++) {
            cout << x.first << " ";
        }
    }

    return 0;
}
