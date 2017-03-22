// 762C

#include<bits/stdc++.h>

using namespace std;

int main(){
    string a, b;
    cin >> a >> b;

    int na, nb;
    na = a.length();
    nb = b.length();
    vector<int> prefixSubsequence;
    int pos = 0;

    prefixSubsequence.push_back(0);
    for(int i = 0; i < nb; ++i){
	while(pos < na && a[pos] != b[i]){
	    ++pos;
	}
	++pos;
	prefixSubsequence.push_back(pos);
    }


    vector<int> suffixSubsequence;
    pos = 0;
    suffixSubsequence.push_back(0);
    for(int i = nb-1; i >=0; --i){
	while(pos < na && a[na-1-pos] != b[i]){
	    ++pos;
	}
	++pos;
	suffixSubsequence.push_back(pos);
    }

    int minDelete = nb;
    int minTake = 0;
    int takeSuffix = nb;
    for(int i = 0; i <= nb; ++i){
	while(takeSuffix + i > nb){
	    --takeSuffix;
	}
	while(takeSuffix >0 && suffixSubsequence[takeSuffix] + prefixSubsequence[i] > na){
	    --takeSuffix;
	}
	if(suffixSubsequence[takeSuffix] + prefixSubsequence[i] <= na){
	    int del = nb-i-takeSuffix;
	    if(del < minDelete){
		minDelete = del;
		minTake = i;
	    }
	}
    }


    string out = "";
    for(int i = 0; i < minTake; ++i){
	out += b[i];
    }
    for(int i = minTake + minDelete; i < nb; ++i){
	out += b[i];
    }
    if(out == ""){
	out = "-";
    }
    cout << out << endl;
}
