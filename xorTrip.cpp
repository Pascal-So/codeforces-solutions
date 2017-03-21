// 766E

#include<bits/stdc++.h>
#define ui uint32_t
#define ull unsigned long long

using namespace std;

int BITS = 25;
int n;
vector<vector<int> > edges;
vector<ui> cityVal;
vector<bool> visited;


// is a collection of n numbers, where the vector counts
// the amount of those that have the ith bit set. Little endian.
#define collection pair<ull, vector<ull> > 


void print_collection(collection a){
    cout<<a.first << " - ";
    for(auto e:a.second){
	cout << e << " ";
    }
    cout <<"\n";
}

template<typename T>
pair<vector<T>, vector<T> > splitAt (vector<T> v, int x){ // [a] -> Int -> ([a], [a])
    int n = v.size();
    vector<T> va, vb;
    for(int i = 0; i < n; ++i){
	if(i < x){
	    va.push_back(v[i]);
	}else{
	    vb.push_back(v[i]);
	}
    }

    return {va, vb};
}


ull getSum(collection a){
    ull sum = 0;
    ui fac = 1;
    for(int i = 0; i < BITS; ++i){
	sum += fac * a.second[i];
	fac *= 2;
    }
    return sum;
}

collection xorVal(ui x, collection a){
    ui fac = 1;
    ull n = a.first;
    for(int i = 0; i < BITS; ++i){
	if(x & fac){
	    a.second[i] = n - a.second[i];
	}
	fac *= 2;
    }
    return a;
}

ull xorCollSum(collection a, collection b){
    // given two collections, we can xor one of them by a single number multiple times

    //  we split the second collection up like this, which results in
    //  O(bits) numbers (pigeonhole)
    //  
    //     4
    //    (3)        ( 1 1 | 1 | 0 )
    //    (0)        ( 0 0 | 0 | 0 )
    //    (2)   ->   ( 1 1 | 0 | 0 )
    //    (3)        ( 1 1 | 1 | 0 )
    //    (2)        ( 1 1 | 0 | 0 )
    //                 *2   *1  *1

    // we then xor them over the first collection, multiply the sum by their
    // respective factors and add them together

    // find unique values present in collection b, sorted, which is the lengths
    // of the segments into which we split b
    vector<ull> sorted = b.second;
    sort(sorted.begin(), sorted.end());
    sorted.push_back(b.first); // need this in order to catch the zeros at the end
    vector<ull> uniq;
    ull last = sorted[0];
    uniq.push_back(last);
    for(auto e:sorted){
	if(e != last){
	    uniq.push_back(e);
	    last = e;
	}
    }
    
    vector<pair<ui, ull> > extracted; // number, factor

    int un = uniq.size();
    for(int i = 0; i < un; ++i){
	ull diff = uniq[i]; // the length of the segment
	if(i > 0){
	    diff -= uniq[i-1];
	}
	
	ui fac = 1;
	ui num = 0;
	for(int j = 0; j < BITS; ++j){
	    num += fac * (b.second[j] >= uniq[i]);
	    fac *= 2;
	}
	extracted.push_back({num, diff});
    }
    
    ull sum = 0;
    for(auto p:extracted){
	sum += getSum(xorVal(p.first, a)) * p.second; // xor the segments, O(bits^2)
    }

    
    
    return sum;
}

collection toCollection(ui x){
    vector<ull> coll;
    ui fac = 1;
    for(int i = 0; i < BITS; ++i){
	bool isSet = (fac & x) != 0;
	coll.push_back(isSet);
	fac *= 2;
    }
    return {1, coll};
}

// union
collection uni(collection a, collection b){
    vector<ull> coll;
    for(int i = 0; i < BITS; ++i){
	coll.push_back(a.second[i] + b.second[i]);
    }
    return {a.first + b.first, coll};
}

collection emptyCollection(){
    auto c = toCollection(0);
    return {0, c.second};
}

collection insert(ui x, collection a){
    return uni(a, toCollection(x));
}

pair<collection, ull> joinGroups(vector<pair<collection, ull> > groups, ui x){
    if(groups.empty()){
	return {emptyCollection(), 0};
    }
    if(groups.size() == 1){
	return groups[0];
    }
    
    // xor the children together. O(n) children,
    // of which O(n^2) combinations exist, which would break
    // the limits. therefore we need to combine them
    // recursively (1x1, 2x2, 4x4.. ), which is possible because
    // of the collection data structure. Merging therefore takes only
    // O(n * bits^2)

    int n = groups.size();
    auto parts = splitAt(groups, n/2);
    
    auto subLeft = joinGroups(parts.first, x);
    auto subRight = joinGroups(parts.second, x);

    ull sum = subLeft.second + subRight.second;

    auto subLeftWithX = xorVal(x, subLeft.first);
    sum += xorCollSum(subLeftWithX, subRight.first);

    auto u = uni(subLeft.first, subRight.first);

    return {u, sum};
}


// returns the collection of paths going up to the next node, as well
// as the sum of paths that are contained entirely in the subtree
pair<collection, ull> dfs(int node){
    if(visited[node]){
	assert(false);
    }
    visited[node] = true;
    vector<pair<collection, ull> > subCalls;
    for(auto next:edges[node]){
	if(!visited[next]){
	    subCalls.push_back(dfs(next));
	}
    }

    auto joined = joinGroups(subCalls, cityVal[node]);
    joined.first = xorVal(cityVal[node], joined.first);
    joined.first = insert(cityVal[node], joined.first);
    joined.second += getSum(joined.first);

    return joined;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    
    for(int i = 0; i < n; ++i){
	ui tmp;
	cin >> tmp;
	cityVal.push_back(tmp);
    }
    
    visited.resize(n, false);
    edges.resize(n);
    for(int i = 0; i < n-1; ++i){
	int a, b;
	cin >> a >> b;
	--a;
	--b;
	edges[a].push_back(b);
	edges[b].push_back(a);
    }

    cout<<dfs(0).second<<endl;
}
