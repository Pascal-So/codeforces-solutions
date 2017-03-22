// 762B

#include<bits/stdc++.h>
#define ull unsigned long long
using namespace std;

int main(){
    int usb, ps, both;
    cin >> usb >> ps >> both;

    int m;
    cin >> m;

    vector<pair<ull, bool> > mouses; // price, is usb
    
    for(int i = 0; i < m; ++i){
	int price;
	string type;
	cin >> price >> type;
	mouses.push_back({price, type=="USB"});
    }

    sort(mouses.begin(), mouses.end());

    int fusb = 0, fps = 0, fboth = 0;
    ull sum = 0;
    for(auto mouse:mouses){
	bool bought = false;
	if(mouse.second){
	    if(fusb < usb){ // still need usb mouses
		++fusb;
		bought = true;
	    }
	}else{
	    if(fps < ps){
		++fps;
		bought = true;
	    }
	}
	if(!bought){
	    if(fboth < both){
		++fboth;
		bought = true;
	    }
	}
	if(bought){
	    sum += mouse.first;
	}
    }

    cout<< fusb + fps + fboth << " " << sum <<endl;
}
