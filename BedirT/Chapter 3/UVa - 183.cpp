#include <iostream>
#include <cstring>
#include <string>
#include <cmath>
#include <fstream>
// #define debug
using namespace std;
int row, col;
string bit, s;
char ch;

bool all(int left, int top, int right, int bottom, char check){
	for(int i = left; i < right; ++i)
		for(int j = top; j < bottom; ++j)
			if(bit[j*row + i] == check) return false;
	return true;
}

void bToD(int left, int top, int right, int bottom){
	if(left == right || top == bottom)
    	return;
	if(all(left, top, right, bottom, '1')){
		cout << "0";
		return;
	}
	else if(all(left, top, right, bottom, '0')){
		cout << "1";
		return;
	}
	else{
		cout << "D";

		int midcol = (left + right + 1) / 2;
        int midrow = (top + bottom + 1) / 2;
		bToD(left, top, midcol, midrow); 		// Left top
		bToD(midcol, top, right, midrow); 		// Right top
		bToD(left, midrow, midcol, bottom); 	// Left bottom
		bToD(midcol, midrow, right, bottom); 	// Right bottom
	}
}

void dToB(int left, int top, int right, int bottom){
	if(left == right || top == bottom)
    	return;
    
    int ch = cin.get();
    if(ch == '0' || ch == '1'){
    	for(int i = left; i < right; ++i)
    		for (int j = top; j < bottom; ++j)
    			bit += ch;
    	return;
    }
    else{
		int midcol = (left + right + 1) / 2;
        int midrow = (top + bottom + 1) / 2;
		dToB(left, top, midcol, midrow); 		// Left top
		dToB(midcol, top, right, midrow); 		// Right top
		dToB(left, midrow, midcol, bottom); 	// Left bottom
		dToB(midcol, midrow, right, bottom); 	// Right bottom
	}
}

int main (){
	
	#ifdef debug
		freopen("output.txt", "w", stdout);
	#endif
	while(cin >> ch && ch != '#'){
		cin >> col >> row;
		if(ch == 'B'){
			while(row*col > bit.size()){
				getline(cin , s);
				bit += s;
			}
			printf("D    %d    %d\n", col, row);
			bToD(0, 0, row, col);
			cout << endl;
		}
		else if(ch == 'D'){
			bit = "";
			printf("B    %d    %d\n", col, row);
			dToB(0, 0, row, col);
			int bg = 0;
			while(bg < bit.size()){
				cout << bit.substr(bg,bg+50) << endl;
				bg += 50;
			}
		}
	}	
	#ifdef debug
		fclose(stdout);
	#endif
}
