#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

int main(){
  ios_base::sync_with_stdio(false);
  int n, m;
  cin >> n >> m;
  vector<ll> h(n);
  for(int i = 0; i < n; ++i){ cin >> h[i]; }
  vector<ll> p(m);
  for(int i = 0; i < m; ++i){ cin >> p[i]; }
  ll left = 0, right = 100000000000000000ll;//ll?
  while(left < right){
    ll center = (left + right) / 2;
    int done = 0;
    for(int i = 0; i < n; ++i){
      const ll first = p[done];
      for(; done < m; ++done){
        const ll last = p[done];
        const ll cost = min(
          abs(h[i] - first), abs(h[i] - last)) + (last - first);
        if(cost > center){ break; }
      }
    }
    if(done >= m){
      right = center;
    }else{
      left = center + 1;
    }
  }
  cout << left << endl;
  return 0;
}