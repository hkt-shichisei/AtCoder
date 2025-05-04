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
    int N;
    cin >> N;
    vector<string> S(N), T(N);
    rep(i, N)cin >> S[i];
    rep(i, N)cin >> T[i];
    int ans = INF32;
    for(int i = 0; i < 4; i++){
        int cnt = i;
        rep(i, N)rep(j, N)if(S[i][j]!=T[i][j])cnt++;
        ans = min(cnt, ans);
        vector<string> nxt(N, "");
        rep(i, N)rep(j, N){
            nxt[i].push_back(S[N-j-1][i]);
        }
        S = nxt;
    }
    cout << ans << endl;
    return 0;
}