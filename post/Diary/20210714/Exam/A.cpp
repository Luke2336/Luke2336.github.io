#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int N, M, P;
  cin >> N >> M >> P;
  vector<int> v(P);
  for (int i = 0; i < P; i++) {
    int x, y;
    cin >> x >> y;
    v[i] = x;
  }
  sort(v.begin(), v.end());
  int ans = max(v[0], N - 2 - v.back());
  for (int i = 1; i < P; i++) {
    ans = max(ans, (v[i] - v[i - 1]) / 2);
  }
  cout << ans << "\n";
  return 0;
}