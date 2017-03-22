// 770D

#include<bits/stdc++.h>
using namespace std;


string repeatChar(int n, char c){
    string out = "";
    for(int i = 0; i < n; ++i){
	out+=c;
    }
    return out;
}

int main(){
    int n;
    cin >> n;
    string s;
    cin >> s;

    vector<int> depth;
    int currentDepth = 0;
    int maxDepth = 0;

    int pos = 0;
    vector<int> barPos;
    
    char last = ']';
    for(auto c:s){
	
	if(c == '['){
	    depth.push_back(currentDepth);
	    barPos.push_back(pos);
	    maxDepth = max(currentDepth, maxDepth);
	    ++currentDepth;
	}else{ // ]
	    --currentDepth;
	    maxDepth = max(currentDepth, maxDepth);
	    if(last == '['){
		pos += 3;
	    }
	    barPos.push_back(pos);
	    depth.push_back(currentDepth);
	}
	last = c;
	++pos;
    }
    
    for(int y = 1+maxDepth; y >= -1-maxDepth; --y){
	pos = 0;
	currentDepth = maxDepth-abs(y)+1;
	for(int i = 0; i < n; ++i){
	    int posDiff = barPos[i]-pos;
	    if(depth[i]==currentDepth){
		if(s[i] == '['){
		    cout<<repeatChar(posDiff-1, ' ')<<"+-";
		    pos = barPos[i]+1;
		}else{
		    cout<<repeatChar(posDiff-2, ' ')<<"-+";
		    pos = barPos[i];
		}
	    }else if(depth[i]<currentDepth){
		cout<<repeatChar(posDiff-1, ' ')<<"|";
		pos = barPos[i];
	    }
	}
	cout<<"\n";
    }
}
