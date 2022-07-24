#include <vector>
#include <iostream>
#include <random>
#include <stack>
#include <algorithm>
#include <unordered_map>
 
using namespace std;
int T, N;
int tower[800005];
vector <int> edges[800005];
unordered_map <int, int> freq;
int ans = 0;

void dfs(int v, int p, unordered_map <int,int> &cur){
	unordered_map <int,int> temp;
	for (int e: edges[v]){
		if (e == p) continue;
		temp.clear();
		dfs(e, v, temp);
		if (temp.size() == 0) ans++;
		for (auto it: temp) {
			cur[it.first] += it.second;
			if (cur[it.first] == freq[it.first]) cur.erase(it.first);
		}
	}
	cur[tower[v]]++;
	if (cur[tower[v]] == freq[tower[v]]) cur.erase(tower[v]);
}

int main(){
	cin >> T;
	for (int tt = 1; tt <= T; tt++){
		cin >> N;
		for (int i=1; i<=N; i++){
			edges[i].clear();
		}
		freq.clear();
		ans = 0;
		for (int i=1; i<N; i++){
			int a, b;
			scanf("%d %d", &a, &b);
			edges[a].push_back(b);
			edges[b].push_back(a);
		}
		for (int i=1; i<=N; i++){
			scanf("%d", &tower[i]);
			freq[tower[i]]++;
		}
		unordered_map <int, int> cur;
		dfs(1, -1, cur);
		printf("Case #%d: %d\n", tt, ans);
	}
	return 0;
}