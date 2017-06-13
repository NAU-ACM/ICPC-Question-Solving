#include <iostream>
#include <map>
using namespace std;

int main (){

	string s1, s2;
	int n, m, ct = 0;
	while(cin >> n >> m && n != 0){
		
		if(ct) cout << endl;

		map<string, int> names;
		string holder[26];
		int vc[26][26];
		bool visited[26];

		int pos = 0;
		for(int i = 0; i < m ; ++i){
			cin >> s1 >> s2;
			if(!names[s1]) names[s1] = ++pos, holder[pos] = s1;
			if(!names[s2]) names[s2] = ++pos, holder[pos] = s2;
			vc[names[s1]][names[s2]] = 1;
		}

		printf("Calling circles for data set %d:\n", ++ct);

		for(int i = 1; i <= pos; i++)
            vc[i][i] = 1;
		for(int i = 1; i <= pos; ++i)
            for(int j = 1; j <= pos; ++j)
                for(int k = 1; k <= pos; ++k)
                    if(vc[j][i] && vc[i][k])
                        vc[j][k] = 1;

		for(int i = 1; i <= pos; ++i){
			if(!visited[i]){
				int tot = 0;
				for(int j = 1; j <= pos; ++j){
					if(!visited[j] && vc[i][j] && vc[j][i]){
						visited[j] = visited[i] = true;
						cout << (!tot++ ? "" : ", ") << holder[j];
					}
				}
				cout << endl;
			}
		}

	}
}