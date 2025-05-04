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

signed main() {
    int N;
    cin >> N;
    vector<int> C(N+1), A(0),dp(N+1, INF32), pf(N+1);
    rep(i, N-1)cin >> C[i+1];
    rep(i, N-1){
        int ai;
        cin >> ai;
        if(ai)A.push_back(i+1);
    }
    reverse(all(A));
    A.push_back(0);
    dp[A[0]] = 0;
    for(int i = 0; i+1 < A.size(); i++){
        int now = A[i];
        while(now>=A[i+1]){
            for(int j = 1; j <= C[now] && now-j>=A[i+1]; j++){


                dp[now-j] = min(dp[now-j], dp[now]+1);
            }
            now--;
        }
    }
    cout << dp[0] << endl;
    return 0;
}