// 766C

#include<bits/stdc++.h>
#define ll long long

using namespace std;

int main(){
    int n;
    cin >> n;
    string s;
    cin >> s;

    vector<int> limits (26);
    for(int i = 0; i < 26; ++i){
	cin >> limits[i];
    }

    vector<int> a;
    for(auto c:s){
	a.push_back(limits[c-'a']);
    }


    ll mod = 1000000007;
    vector<int> furthestBack (n, 0);
    vector<ll> possibilities (n, 0);

    for(int i = 0; i < n; ++i){
	int maxLen = n;
	for(int j = i; j >= 0; --j){
	    maxLen = min(min(a[j], maxLen), i+1);
	    
	    if(j <= i-maxLen){
		break;
	    }
	    furthestBack[i]= (i-j+1);
	    if(j>0){
		possibilities[i] += possibilities[j-1];
	    }else{
		possibilities[i] += 1;
	    }
	    possibilities[i] %= mod;
	}
    }
    cout<<possibilities[n-1]<<endl;

    int maxSubstring = 0;
    for(auto e:furthestBack){
	maxSubstring = max(maxSubstring, e);
    }
    cout<<maxSubstring<<endl;

    /*
    for(auto i:a){
	cout<<i<<" ";
    }
    cout<<endl;
    
    for(auto i:possibilities){
	cout<<i<<" ";
    }
    cout<<endl;
    
    for(auto i:furthestBack){
	cout<<i<<" ";
    }
    cout<<endl;
    */

    int pos = n-1;
    int steps = 0;
    while(pos>=0){
	pos -= furthestBack[pos];
	++steps;
    }
    cout<<steps<<endl;
}
