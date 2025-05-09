// 配点: 400

//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define all(a) (a).begin(), (a).end()
#define int long long
using ll = long long;
const ll INF32 = 2e9;
const ll INF64 = 4e18;



void printYN(bool ok){
    if(ok)cout << "Yes" << endl;
    else cout << "No" << endl;
    return;
}

void solve() {
    int H, W; string S;
    cin >> H >> W >> S;
    ll cntD = 0, cntR = 0; 
    ll ans = H*W, cnt = 0;
    rep(i, S.size()){
        if(S[i]=='D')cntD++;
        else if(S[i]=='R')cntR++;
    }
    pair<int, int> RU = {0, 0}, LD = {0, 0};
    rep(i, S.size()){
        if(S[i]=='D'){
            cntD--;
            RU.first++;
            LD.first++;
            ans-=W-RU.second-1;
        }
        else if(S[i]=='R'){
            cntR--;
            RU.second++;
            LD.second++;
            ans-=H-LD.first-1;
        }
        else if(S[i]=='?'){
            if(LD.first < H-cntD-1){
                LD.first++;
            }
            else {
                LD.second++;
                ans-=H-LD.first-1;
            }
            if(RU.second < W-cntR-1){
                RU.second++;
            }
            else {
                RU.first++;
                ans-=W-RU.second-1;
            }
        }
    }
    cout << ans << endl;
    return;
}

signed main() {
    int t;
    cin >> t;
    rep(i, t)solve();
    return 0;
}