#include <iostream>
#include <queue>
#include <vector>
using namespace std;

#define MAX 100

int V, E;
vector<bool> visited;
vector<int> path;
vector<int> graph[MAX];

void BFS(int s) {
	for (int i = 0; i < V; ++i) {
		visited.push_back(false);
		path.push_back(-1);
	}

	queue<int> q;
	visited[s] = true;
	q.push(s);

	while (!q.empty())
	{
		int u = q.front();
		q.pop();
		for (int i = 0; i < graph[u].size(); ++i) {
			int v = graph[u][i];
			if (!visited[v]) {
				visited[v] = true;
				path[v] = u;
				q.push(v);
			}
		}
	}
}

void printPath(int s, int f) {
#if 1 // ko dung de quy
	vector<int> b(MAX);
	int m = 0;
	if (f == s) {
		cout << s;
		return;
	}

	if (path[f] == -1) {
		cout << "no path\n";
		return;
	}

	while (true) {
		b[m++] = f;
		f = path[f];
		if (f == s) {
			b[m++] = s;
			break;
		}
	}

	for (int i = m - 1; i >= 0; --i) {
		cout << b[i] << endl;
	}

#else
	// dung de quy
	if (f == s) {
		cout << s << endl;
	} else {
		if (path[f] == -1) {
			cout << "no path\n";
		} else {
			printPath(s, path[f]);
			cout << f << endl;
		}
	}

#endif

}

int main() {
	int u, v;
	cin >> V >> E;
	for (int i = 0; i < E; ++i) {
		cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	int s = 0; // start
	int f = 5; // finish

	BFS(s);
	printPath(s, f);

	return 0;
}