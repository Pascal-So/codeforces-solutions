// 770C

#include<bits/stdc++.h>

using namespace std;

bool failed = false;
vector<bool> visited;
vector<bool> active;

vector<int> topoSort;


vector<vector<int> > edges;


void dfs(int node){
    if(active[node]){
	failed = true;
	return;
    }
    active[node] = true;
    for(auto d:edges[node]){
	if(!visited[d]){
	    dfs(d);
	}
    }
    active[node]= false;
    visited[node] = true;
    topoSort.push_back(node);
}

int main(){
    int n, k;
    cin >> n >> k;

    visited.resize(n, false);
    active.resize(n, false);

    vector<int> a;
    for(int i = 0; i < k; ++i){
	int tmp;
	cin >> tmp;
	--tmp;
	a.push_back(tmp);
    }

    edges.resize(n);
    for(int i = 0; i < n; ++i){
	int d;
	cin >> d;
	for(int j = 0; j < d; ++j){
	    int dep;
	    cin >> dep;
	    --dep;
	    edges[i].push_back(dep);
	}
    }

    for(auto c:a){
	if(!visited[c]){
	    dfs(c);
	    if(failed){
		break;
	    }
	}
    }

    if(failed){
	cout<<"-1\n";
    }else{
	cout<< topoSort.size() <<"\n";
	for(auto c:topoSort){
	    cout<<c+1 <<" ";
	}
	cout<<endl;
    }
}
