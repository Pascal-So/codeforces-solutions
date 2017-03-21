// 766B

#include<bits/stdc++.h>
#define ll long long

using namespace std;

bool possible(int n, vector<ll> a){
    if(n < 3){
	return false;
    }

    for(int i = 2; i < n; ++i){
	if(a[i-2] + a[i-1] > a[i]){
	    return true;
	}
    }
    return false;
}

int main(){
    int n;
    cin >> n;
    vector<ll> a;
    for(int i = 0; i < n; ++i){
	ll tmp;
	cin >> tmp;
	a.push_back(tmp);
    }

    sort(a.begin(), a.end());
    cout<<(possible(n, a)?"YES":"NO")<<endl;
}

