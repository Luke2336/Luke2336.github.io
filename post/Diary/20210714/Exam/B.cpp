#include <bits/stdc++.h>
using namespace std;
#define maxn 100005
#define maxl 80
long long dp[maxn][maxl] = {};
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  long long n, r, b;
  cin >> n >> r >> b;
  dp[0][0] = 1;
  for (int i = 1; i < maxn; i++) {
    for (int j = 0; j < maxl; j++) {
      dp[i][j] += dp[i - 1][j] * r;
      dp[i][j + 1] += dp[i][j] / 10;
      dp[i][j] %= 10;
    }
    dp[i][0] += b;
    for (int j = 0; j < maxl; j++) {
      while (dp[i][j] < 0) {
        dp[i][j + 1]--;
        dp[i][j] += 10;
      }
    }
  }
  while (n--) {
    int x;
    cin >> x;
    string ans = "";
    bool flag = false;
    for (int i = maxl - 1; i >= 0; i--) {
      if (dp[x][i])
        flag = true;
      if (!flag)
        continue;
      ans += char(dp[x][i] + '0');
    }
    if (ans.length() == 0)
      ans = "0";
    cout << ans << "\n";
  }
  return 0;
}