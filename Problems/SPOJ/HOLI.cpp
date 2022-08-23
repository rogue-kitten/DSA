#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define ull unsigned long long
#define mod 1000000007
#define vi vector<int>
#define vll vector<long long>
#define vull vector<unsigned long long>
#define vvi vector<vector<int>>
#define umii unordered_map<int, int>
#define umivi unordered_map<int, vector<int>>
#define printall(a) for(auto i : a) cout << i << " "
#define print(a) cout << a << endl
#define pb push_back
#define maxHeap  priority_queue<int>
#define minHeap  priority_queue<int, vector<int>, greater<int> >


class graph{

public:
	int V;
	vector<pair<int, int>> *adjList;
	graph(int v){
		V = v;
		adjList = new vector<pair<int, int>> [V + 1];
	}

	void addEdge(int u, int v, int wt){
		adjList[u].push_back({v, wt});
		adjList[v].push_back({u, wt});
	}

	int dfs(){
		vector<bool> visited(V + 1, false);
		vector<int> count(V + 1, 0);

		int ans = 0;
		dfs_helper(1,visited, count, ans);
		return ans;
	}

	int dfs_helper(int node, vector<bool> &visited, vector<int> &count, int &ans){
		visited[node] = true;
		count[node] = 1;

		for(auto it : adjList[node]){
			if(!visited[it.first]){
				count[node] += dfs_helper(it.first, visited, count, ans);
				int nx = count[it.first];
				int ny = V - nx;
				ans += 2 * min(nx,ny)*it.second;
			}
		}
		return count[node];
	}
};

int main(){
	int t;
	cin >> t;
	for(int i = 1; i <= t; i++){
		int n;
		cin >> n;
		graph g(n);

		for(int i = 0; i < n - 1; i++){
			int x, y, z;
			cin >> x >> y >> z;
			g.addEdge(x,y,z);
		}

		cout << "Case #" << t << ": " << g.dfs() << endl;

	}
}
