#include<bits/stdc++.h>
#define ll long long
using namespace std;



int main(){
    int n;
    cin >> n;
    string s;
    ll out = 0;
    for(int i = 0; i < n; ++i){
	cin >> s;
	switch(s[0]){
	case 'T':
	    out += 4;
	    break;
	case 'C':
	    out += 6;
	    break;
	case 'O':
	    out += 8;
	    break;
	case 'D':
	    out += 12;
	    break;
	case 'I':
	    out += 20;
	    break;
	}
	
    }
    cout<<out<<endl;
}
