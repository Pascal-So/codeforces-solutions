// 770A

#include<bits/stdc++.h>

using namespace std;

int main(){
    int n, k;
    cin >> n >> k;
    string out;
    for(int i = 0; i < n; ++i){
	out+= 'a' + i%k;
    }
    cout<<out<<endl;
}
