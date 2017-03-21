// 768B

#include<bits/stdc++.h>
#define ll unsigned long long

using namespace std;

ll getRangeLength(ll bits){
    ll start = 1;
    return (start<<bits) - 1;
}

vector<bool> toBinary(ll n){
    vector<bool> out;

    while(n){
	out.push_back(n%2);
	n /= 2;
    }

    reverse(out.begin(), out.end());
    return out;
}

ll toNumber(vector<bool> binary){
    reverse(binary.begin(), binary.end());

    ll out = 0;
    while(! binary.empty()){
	out*=2;
	out+= binary.back();
	binary.pop_back();
    }
    return out;
}

void print_binary(vector<bool> bin){
    for(auto d:bin){
	cout<<(d?1:0);
    }
    cout<<endl;
}

ll countRange(vector<bool> bin, ll l, ll r){
    /*cout<<"count -------------------\n";
    print_binary(bin);
    cout<<l << " " << r <<endl;*/
    if(bin.empty()){
	return 0;
    }
    ll rangeLen = getRangeLength(bin.size());
    /*cout<<"rangeLen " << rangeLen<<endl;
    cout<<endl;
    */
    if(l >= rangeLen || r <= 0 || r<=l){
	return 0;
    }
    if(l <= 0 && r >= rangeLen){
	return toNumber(bin);
    }

    ll out = 0;

    ll middle = rangeLen/2;
    if(l <= middle && r > middle){
	out+=bin.back();
    }

    bin.pop_back();

    out+= countRange(bin, l, r);

    ll newLeft, newRight;
    if(l > middle+1){
	newLeft = l - middle - 1;
    }else{
	newLeft = 0;
    }
    if(r > middle+1){
	newRight = r - middle - 1;
    }else{
	newRight = 0;
    }
    
    out+= countRange(bin, newLeft, newRight);
    return out;
}



int main(){
    ll n, l, r;
    cin >> n >> l >> r;
    --l;

    auto binary = toBinary(n);
    /*for(auto d:binary){
	cout<<(d?1:0);
    }
    cout<<endl;*/
    
    cout<<countRange(binary, l, r)<<endl;

}
