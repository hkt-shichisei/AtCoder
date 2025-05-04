//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define all(a) (a).begin(), (a).end()
using ll = long long;
const ll INF32 = 2e9;
const ll INF64 = 4e18;

void printYN(bool ok){
    if(ok)cout << "Yes" << endl;
    else cout << "No" << endl;
    return;
}

int main() {
    int N, M;
    cin >> N >> M;
    if(N!=M){
        printYN(0);return 0;
    }
    vector<vector<int>> graph(N);
    rep(i, M){
        int a, b;
        cin >> a >> b;
        a--; b--;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    rep(i, N){
        if(graph[i].size()!=2){
            printYN(0);
            return 0;
        }
    }
    vector<bool> seen(N);
    int cur = 0, nxt = graph[cur][0];
    seen[cur] = true;
    while(!seen[nxt]){
        seen[nxt] = true;
        if(graph[nxt][0]!=cur){
            cur = nxt;
            nxt = graph[nxt][0];
        }
        else {
            cur = nxt;
            nxt = graph[nxt][1];
        }
        
    }
    bool ok = true;
    rep(i, N)ok = (ok && seen[i]);
    printYN(ok);
    return 0;
}