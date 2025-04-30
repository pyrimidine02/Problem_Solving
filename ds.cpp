
#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef pair<ll, ll> llll;
typedef pair<int, int> ii;

vector<pair<pair<pair<int,int>,pair<int,int>>,int>> cut;
bool match[2501][2501];
int matches[2501];
bool dead[2501];

int product(ll x1, ll y1, ll x2, ll y2){
    ll x = x1*y2 - y1*x2;
    if(x<0)return -1;
    else if(x>0) return 1;
    else return 0;
}

bool is_meet(int a, int b){
    int v0x = cut[a].first.second.first - cut[a].first.first.first;
    int v1x = cut[b].first.first.first - cut[a].first.first.first;
    int v2x = cut[b].first.second.first - cut[a].first.first.first;
    int v0y = cut[a].first.second.second - cut[a].first.first.second;
    int v1y = cut[b].first.first.second - cut[a].first.first.second;
    int v2y = cut[b].first.second.second - cut[a].first.first.second;
    int w0x = cut[b].first.second.first - cut[b].first.first.first;
    int w1x = cut[a].first.first.first - cut[b].first.first.first;
    int w2x = cut[a].first.second.first - cut[b].first.first.first;
    int w0y = cut[b].first.second.second - cut[b].first.first.second;
    int w1y = cut[a].first.first.second - cut[b].first.first.second;
    int w2y = cut[a].first.second.second - cut[b].first.first.second;
    if(product(v0x, v0y, v1x, v1y)* product(v0x, v0y, v2x, v2y)<0 &&
       product(w0x, w0y, w1x, w1y)* product(w0x, w0y, w2x, w2y)<0){
        return true;
    }else
        return false;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int sx, sy, ex, ey, w;
        cin>>sx>>sy>>ex>>ey>>w;
        cut.push_back({{{sx, sy}, {ex, ey}}, w});
    }
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(is_meet(i, j)){
                match[i][j]=true;
                match[j][i]=true;
                matches[i]++;
                matches[j]++;
            }
        }
    }

    ll cnt =0;
    for(int i=0;i<n;i++){
        priority_queue<pair<ll, int>> pq;
        for(int j=0;j<n;j++){
            if(dead[j])continue;
            pq.push({-((ll)matches[j]+1ll)*(ll)cut[j].second, j});
        }
        int j = pq.top().second;
        dead[j]=true;
        cnt-=(ll)pq.top().first;
        for(int k=0;k<n;k++){
            if(match[j][k]){
                matches[k]--;
            }
        }
    }
    cout<<cnt;
}