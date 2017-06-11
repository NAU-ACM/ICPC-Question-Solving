/*	Getting all right answer from every testcases that I found... 
	Still not able to get AC */
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;
int matrix[1001][1001], space, m, n;
bool flag = false;
void dfsRemove(int x, int y){
	if (matrix[x][y] != 0) return;
	matrix[x][y] = -1;
	if(x != 0) dfsRemove(x-1, y); // left
	if(y != 0) dfsRemove(x, y-1); // up
	if(y < n) dfsRemove(x, y+1); // down
	if(x < m) dfsRemove(x+1, y); // right
	if(x == m || y == n) flag = true;
}

void dfsFill(int x, int y){
	if (matrix[x][y] != 1){
		if(matrix[x][y] == 0){
			cout << "IN\n";
			dfsRemove(x, y);
			space++;
		}
		return;
	}
	matrix[x][y] = 2;
	if(x != 0) dfsFill(x-1, y); // left
	if(y != 0) dfsFill(x, y-1); // up
	if(x < m) dfsFill(x+1, y); // right
	if(y < n) dfsFill(x, y+1); // down
}

string hexaToBin(string s){
	string news = "";
	for(int i = 0; i < s.size(); ++i){
		switch(s[i]){
			case '0': news += "0000"; break;
			case '1': news += "0001"; break;
			case '2': news += "0010"; break;
			case '3': news += "0011"; break;
			case '4': news += "0100"; break;
			case '5': news += "0101"; break;
			case '6': news += "0110"; break;
			case '7': news += "0111"; break;
			case '8': news += "1000"; break;
			case '9': news += "1001"; break;
			case 'a': news += "1010"; break;
			case 'b': news += "1011"; break;
			case 'c': news += "1100"; break;
			case 'd': news += "1101"; break;
			case 'e': news += "1110"; break;
			case 'f': news += "1111"; break;
		}
	}
	return news;
}

string getLetter(int k){
	switch(k){
		case 0: return "W"; break; 
		case 1: return "A"; break;
		case 2: return "K"; break;
		case 3: return "J"; break;
		case 4: return "S"; break;
		case 5: return "D"; break;
	}
}

void printMatrix(){
	cout << endl << endl;
	for(int i = 0; i < m; ++i){
		for(int j = 0; j < n; ++j)
			cout << matrix[i][j];
		cout << endl;
	}
}

int main () {

	// freopen("output.txt", "w", stdout);

	int ct = 1;
	while(cin >> m >> n && m != 0){
		for(int i = 0; i < m; ++i){
			string s, str; cin >> str;
			s = hexaToBin(str);
			for(int j = 0; j < s.size() ; ++j)
				matrix[i][j] = s[j] - '0';
		}
		n *= 4;
		// printMatrix();
		
		int i , j; flag = false;
		for(i = 0; i < m; ++i){
			for(j = 0; j < n; ++j)
				if(matrix[i][j] == 0) break;
			if(matrix[i][j] == 0){
				dfsRemove(i, j);
				if(flag) break; 
				i--;
			}
		}  	// bg removed
				// simply starting from 0,0 will fail
				// need to find all bg pieces

		// printMatrix();

		string res = "";
		for(int i = 0; i < m; ++i)
			for(int j = 0; j < n; ++j)
				if(matrix[i][j] == 1){
					space = 0;
					dfsFill(i, j);
					res += getLetter(space);
				}
		sort(res.begin(), res.end());
		cout << "Case " << ct++ << ": " << res << endl;
		memset(matrix, 0, sizeof matrix);
	}

	// fclose(stdout);
}