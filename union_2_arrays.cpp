#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int union_array(int *, int *, int, int);

int main() {
	int t;
	
	cin >> t;
	
	while(t--){
	    int n, m;
	    cin >> n >> m;
	    int a[n], b[m];
	
	    for(auto i=0; i<n; i++) cin >> a[i];
	    for(auto i=0; i<m; i++) cin >> b[i];
	// vector<int> c;
        int total_size=0;
	    total_size = union_array(a, b, n, m);
	
	    cout << total_size << endl;
	}

	// for(auto i=0; i<c.size(); i++) cout << c[i] << " ";
	return 0;
}

int union_array(int a[], int b[], int n, int m){
    unordered_map<int, int> umap;
    
    int c = 0;
	for(auto i=0; i<n; i++){
	    if(umap.find(a[i]) == umap.end()){
	        c++;
	        umap.insert(pair<int,int>(a[i], 1));
	    }   
	}
	
	for(auto i=0; i<m; i++){
	    if(umap.find(b[i]) == umap.end()){
	        c++;
	        umap.insert(pair<int,int>(b[i], 1));
	    }   
	    
	}
	
	return c;

    
    
}