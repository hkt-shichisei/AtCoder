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
    string S;
    cin >> S;
    set<char> st;
    rep(i, S.size()){
        st.insert(S[i]);
    }
    rep(i, 26){
        if(!st.count('a'+i)){
            cout << (char)('a'+i) << endl;
            return 0;
        }
    }
    return 0;
}