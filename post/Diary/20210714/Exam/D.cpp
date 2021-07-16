#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int N, M, P;
  cin >> N >> M >> P;
  queue<int> qx, qy;
  vector<vector<int>> dis(N, vector<int>(M, -1));
  for (int i = 0; i < P; i++) {
    int x, y;
    cin >> x >> y;
    qx.push(x);
    qy.push(y);
    dis[x][y] = 0;
  }
  int ans = 0;
  int dx[4] = {1, -1, 0, 0};
  int dy[4] = {0, 0, 1, -1};
  while (!qx.empty()) {
    int x = qx.front();
    qx.pop();
    int y = qy.front();
    qy.pop();
    for (int di = 0; di < 4; di++) {
      int xx = x + dx[di];
      int yy = y + dy[di];
      if (xx < 0 || xx >= N || yy < 0 || yy >= M)
        continue;
      if (dis[xx][yy] != -1) continue;
      dis[xx][yy] = dis[x][y] + 1;
      qx.push(xx), qy.push(yy);
      ans = max(ans, dis[xx][yy]);
    }
  }
  cout << ans << "\n";
  return 0;
}