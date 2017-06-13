/*
    Name: 481 - What Goes Up
    Link: https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=422
    Topic: Dynamic
    Algo Used: Longest Increasing Subsequence, Binary Search
*/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int BinarySearch(vector<int> vc,int * small ,int high, int key) {
   int low = 0, mid;
   while (low < high){
       mid = low + ((high - low) / 2);
       if (vc[small[mid]] >= key) high = mid;
       else low = mid + 1;
   }
   return low;
}

int main () {

	int a;
	vector<int> vc;
	while(cin >> a) vc.push_back(a);

    int small[vc.size()+1], parent[vc.size()+1];

    int size = 0; small[0] = 0; parent[0] = -1;

    for(int i = 1 ; i < vc.size() ; i++){
        if(vc[i] <= vc[small[size]]){
            int pos = BinarySearch(vc,small,size,vc[i]);
            small[pos] = i;
            if(pos != 0) parent[i] = small[pos-1];
        }
        else{
            small[++size] = i;
            parent[i] = small[size-1];
        }
    }

    int pos = small[size];
    vector<int> st;
    while(size--){
        st.push_back(vc[pos]);
        pos = parent[pos];
    }

    cout << st.size() << endl << "-" << endl;
    for (int i = st.size()-1; i >= 0; --i)
        cout << st[i] << endl;

}