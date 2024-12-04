#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> bfs(int n, int m, vector<vector<int>> edges, int s) {
    vector<bool> visited(n + 1);
    vector<int> path(n + 1);
    queue<int> q;

    for (int i = 1; i <= n; ++i) {
        visited[i] = false;
        path[i] = -1;
    }

    q.push(s);
    path[s] = 0;
    visited[s] = true;

    while (!q.empty()) {
        int u = q.back();
        q.pop();
        
        for (int i = 0; i < edges[u].size(); ++i) {
            int v = edges[u][i];
            if (!visited[v]) {
                visited[v] = true;
                q.push(v);
                path[v] = path[u] + 6;
            }
        }
    }

    vector<int> result;
    for (int i = 1; i <= n; ++i) {
        if (i == s) continue;
        result.push_back(path[i]);
    }

    return result;
}

int main()
{
    int Q;
    cin >> Q;
    for (int i = 0; i < Q; ++i)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges(n + 1);
        for (int i = 0; i < m; ++i) {
            int u, v;
            cin >> u >> v;
            edges[u].push_back(v);
            edges[v].push_back(u);
        }
        int s;
        cin >> s;
        vector<int> result = bfs(n, m, edges, s);

        for (size_t i = 0; i < result.size(); i++) {
            cout << result[i];

            if (i != result.size() - 1) {
                cout << " ";
            }
        }

        cout << "\n";
    }

    return 0;
}
