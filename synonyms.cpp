// 766D

#include<bits/stdc++.h>

using namespace std;

int n;
vector<pair<int, bool> > group;

pair<int, bool> getRoot(int node){
    pair<int, bool> next = group[node];
    if(next.first == node){
	return next;
    }
    group[node] = getRoot(next.first);
    group[node].second ^= next.second;
 
    return group[node];
}

bool merge(int a, int b, bool antonym){
    auto rootA = getRoot(a);
    auto rootB = getRoot(b);
    antonym ^= rootA.second;
    antonym ^= rootB.second;
    if(rootA.first == rootB.first && antonym){
	return false;
    }
    group[rootB.first] = {rootA.first, antonym};
    return true;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int m, q;
    cin >> n >> m >> q;

    unordered_map<string, int> words;
    for(int i = 0; i < n; ++i){
	string s;
	cin >> s;
	words[s] = i;
    }

    for(int i = 0; i < n; ++i){
	group.push_back({i, false});
    }

    for(int i = 0; i < m; ++i){
	int syn;
	cin >> syn;
	string sa, sb;
	cin >> sa >> sb;
	int a, b;
	a = words[sa];
	b = words[sb];
	bool merged = merge(a,b, syn==2);
	cout<<(merged?"YES":"NO")<<"\n";
    }
    //cout<<"\n\n\n";
    
    
    
    for(int i = 0; i < q; ++i){
	string sa, sb;
	int a, b;
	cin >> sa >> sb;
	a = words[sa];
	b = words[sb];
	auto ra = getRoot(a);
	auto rb = getRoot(b);
	//print_root(ra);
	//print_root(rb);
	
	if(ra.first == rb.first){
	    bool ant = ra.second ^ rb.second;
	    cout<< (ant?2:1)<<"\n";
	}else{
	    cout<<"3\n";
	}
    }
}
