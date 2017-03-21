#include<bits/stdc++.h>
#define ll long long

using namespace std;

int main(){
    int n, m;
    ll maxStartChess, minEndChess;
    ll maxStartCS, minEndCS;
    
    cin >> n;
    cin >> maxStartChess >> minEndChess;
    for(int i = 1; i < n; ++i){
	ll start, end;
	cin >> start >> end;
	maxStartChess = max(start, maxStartChess);
	minEndChess = min(end, minEndChess);
    }
    
    cin >> m;
    cin >> maxStartCS >> minEndCS;
    for(int i = 1; i < m; ++i){
	ll start, end;
	cin >> start >> end;
	maxStartCS = max(start, maxStartCS);
	minEndCS = min(end, minEndCS);
    }

    cout<< max(max(maxStartCS-minEndChess, maxStartChess-minEndCS), 0ll) << endl;
    
}
