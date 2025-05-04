//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define all(a) (a).begin(), (a).end()
using ll = long long;
const ll INF32 = 2e9;
const ll INF64 = 4e18;

#define int long long

void printYN(bool ok){
    if(ok)cout << "Yes" << endl;
    else cout << "No" << endl;
    return;
}

ll power3(int N){
    ll res = 1;
    rep(i, N)res *= 3;
    return res;
}

signed main() {
    ll N, M;
    cin >> N >> M;
    ll ans = INF64;
    vector<ll> C(N);
    rep(i, N)cin >> C[i];
    vector<vector<int>> A(N, vector<int>(M));
    for(int i = 0; i < M; i++){
        int k;
        cin >> k;
        for(int j = 0; j < k; j++){
            int a;
            cin >> a;
            a--;
            A[a][i] = true;
        }
    }
    ll loop = power3(N);
    for(int b = 0; b < loop; b++) {
        vector<int> cnt(M);
        ll fare = 0;
        for(int i = 0; i < N; i++){
            rep(k, M){
                cnt[k] += A[i][k]*(b/power3(i)%3);
            }
            fare += C[i]*(b/power3(i)%3);
        }
        bool ok = true;
        rep(i, M){
            if(cnt[i]<2)ok = false;
        }
        if(ok) ans = min(ans, fare);
    }
    cout << ans << endl;
    return 0;
}