// 770B

#include<bits/stdc++.h>
#define ull unsigned long long
using namespace std;

vector<int> toDigits (ull n){
    vector<int> out;

    while(n){
	out.push_back(n%10);
	n/=10;
    }

    reverse(out.begin(), out.end());
    return out;
}

template<typename T>
void show(vector<T> v){
    cout<<"{ ";
    for(auto e:v){
	cout<<e<<" ";
    }
    cout<<"}\n";
}

ull toNumber(vector<int> x){
    int n = x.size();
    ull factor = 1;

    ull out = 0;
    for(int i = n-1; i >= 0; --i){
	out+= factor * x[i];
	factor *= 10;
    }
    return out;
}

int sum(vector<int> x){
    int out = 0;
    for(auto d:x){
	out+=d;
    }
    return out;
}

vector<int> lowerAt(int pos, vector<int> x){
    int n = x.size();
    x[pos]--;
    for(int i = pos+1; i < n; ++i){
	x[i] = 9;
    }
    return x;
}

int main(){
    ull x;
    cin >> x;
    auto digits = toDigits(x);

    int len = digits.size();
    ull maxNum = 0;
    int maxSum = 0;

    for(int i = 0; i < len; ++i){
	if(digits[i] != 0){
	    auto lowered = lowerAt(i, digits);
	    int s = sum(lowered);
	    if(s >= maxSum){
		maxSum = s;
		maxNum = toNumber(lowered);
	    }
	}
    }

    if(sum(digits) >= maxSum){
	maxNum = x;
    }

    cout<<maxNum << endl;
}
