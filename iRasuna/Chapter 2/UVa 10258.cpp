#include <bits/stdc++.h>

using namespace std;

struct Teams {
	int ID;
	int qSolved;
	int penalty;
	int qMap[10];
	bool submit;
};

bool team_cmp(Teams const& lhs, Teams const& rhs) {
    if (lhs.qSolved != rhs.qSolved)
        return lhs.qSolved > rhs.qSolved;
    if (lhs.penalty != rhs.penalty)
    	return lhs.penalty < rhs.penalty;
    return lhs.ID < rhs.ID;
}

int main() {
	int t, teamID, questionID, time;
	char verdict;
	string s;
	
	cin >> t;
	getline(cin, s); getline(cin, s);
	
	while(t--){
		Teams team[101] = { 0 };
		
		while(getline(cin, s), s != "") {
			istringstream strin(s);
			
			strin >> teamID >> questionID >> time >> verdict;
			
			team[teamID].ID = teamID;
			team[teamID].submit = true;
			
			if (team[teamID].qMap[questionID] != -1) {
				if (verdict == 'I') {
					team[teamID].qMap[questionID]++;
				}
				else if (verdict == 'C') {
					team[teamID].penalty += (team[teamID].qMap[questionID] * 20) + time;
					team[teamID].qSolved++;
					team[teamID].qMap[questionID] = -1;
				}
			}
		}
		
		sort(team, team+101, &team_cmp);
		
		for(int i = 0; i < 101; ++i){
			if (team[i].submit){
				cout << team[i].ID << " " << team[i].qSolved << " " << team[i].penalty << endl;
			}
		}
		
		if (t) cout << endl;
	}
	
	return 0;
}
