#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n), c(n);
  int sum = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i] >> c[i];
    sum += a[i];
  }
  vector<int> dp(sum + 1, n * 1000);
  dp[0] = 0;
  for (int i = 0; i < n; i++) {
    for (int j = sum; j >= a[i]; j--)
      dp[j] = min(dp[j], dp[j - a[i]] + c[i]);
  }
  for (int j = sum - 1; j >= 0; j--)
    dp[j] = min(dp[j + 1], dp[j]);
  // cout << "sum = " << sum << "\n";
  int T;
  cin >> T;
  while (T--) {
    long long P;
    cin >> P;
    if (P > sum) {
      cout << 0 << "\n";
    } else {
      cout << dp[P] << "\n";
    }
  }
  return 0;
}