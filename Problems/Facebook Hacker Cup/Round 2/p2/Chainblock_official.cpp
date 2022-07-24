#include <iostream>
#include <vector>

using namespace std;

const int LIM = 800008;
const int LIM2 = 21; // ceil(log2(LIM)) + 1

int N;
int D[LIM], A[LIM];
vector<int> adj[LIM], F[LIM], P[LIM];
vector<int> O;

void rec(int i) {
  O.push_back(i);
  for (int j = 0; j < LIM2; j++) {
    int p = P[i][j];
    if (p < 0) {
      break;
    }
    P[i][j + 1] = P[p][j];
  }
  for (int j : adj[i]) {
    if (j != P[i][0]) {
      P[j][0] = i;
      D[j] = D[i] + 1;
      rec(j);
    }
  }
}

int lca(int a, int b) {
  if (D[a] < D[b]) {
    swap(a, b);
  }
  for (int i = LIM2 - 1; i >= 0; i--) {
    int p = P[a][i];
    if (p >= 0 && D[p] >= D[b]) {
      a = p;
    }
  }
  for (int i = LIM2 - 1; i >= 0; i--) {
    if (P[a][i] != P[b][i]) {
      a = P[a][i];
      b = P[b][i];
    }
  }
  return a == b ? a : P[a][0];
}

int solve() {
  O.clear();
  for (int i = 0; i < LIM; i++) {
    adj[i].clear();
    P[i].assign(LIM2, -1);
    F[i].clear();
  }
  // Input.
  cin >> N;
  for (int i = 0, a, b; i < N - 1; i++) {
    cin >> a >> b;
    a--;
    b--;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  for (int i = 0, f; i < N; i++) {
    cin >> f;
    F[f - 1].push_back(i);
  }
  // DFS through tree, computing depths, ancestors, and pre-order.
  rec(0);
  // Compute LCA requirements for each frequency.
  for (int i = 0; i < N; i++) {
    if (F[i].empty()) {
      continue;
    }
    int a = F[i][0];
    for (int j = 1; j < (int)F[i].size(); j++) {
      a = lca(a, F[i][j]);
    }
    for (int k : F[i]) {
      A[k] = D[a];
    }
  }
  // Iterate upwards through tree, computing answer.
  int ans = 0;
  for (int j = N - 1; j > 0; j--) {
    int i = O[j];
    if (A[i] == D[i]) {
      ans++;
    } else {
      A[P[i][0]] = min(A[P[i][0]], A[i]);
    }
  }
  return ans;
}

int main() {
  int T;
  cin >> T;
  for (int t = 1; t <= T; t++) {
    cout << "Case #" << t << ": " << solve() << endl;
  }
  return 0;
}
