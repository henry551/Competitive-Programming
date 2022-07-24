#include <bits/stdc++.h>
using namespace std;

int answer = INT_MAX;
void minimumTimeRequiredHelper(vector<int>& jobs, int idx, int n, int k, vector<int>& workers) {
    if (idx == n) {
        int temp = INT_MIN;
        for (int val : workers) {
            temp = max(temp, val);
        }
        answer = min(temp, answer);
        return;
    }
    
    unordered_set<int> seen;
    for (int x = idx; x < idx+k; x++) {
        int i = x%k;
        if (seen.count(workers[i])) continue;
        if (workers[i] + jobs[idx] > answer) continue;
        seen.insert(workers[i]);
        workers[i] = workers[i] + jobs[idx];
        minimumTimeRequiredHelper(jobs, idx + 1, n, k, workers);
        workers[i] = workers[i] - jobs[idx];
    }
}

int minimumTimeRequired(vector<int>& jobs, int k) {
    int n = jobs.size();
    vector<int> workers(k, 0);
    minimumTimeRequiredHelper(jobs, 0, n, k, workers);
    return answer;
}

int main(){
    int n, k;
    cin >> n >> k;
    vector <int> jobs;
    for (int i=0; i<n; i++){
        int a;
        cin >> a;
        jobs.push_back(a);
    }
    cout << minimumTimeRequired(jobs, k) << endl;
}