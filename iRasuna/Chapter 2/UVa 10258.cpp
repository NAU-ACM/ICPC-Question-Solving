#include <bits/stdc++.h>

using namespace std;

struct Teams {
	int ID;
	int qSolved;
	int penalty;
	bool qMap[10];
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
			//cout << teamID << " " << questionID << " " << time << " " << verdict << endl;
			
			if (!team[teamID].qMap[questionID]) {
				if (verdict == 'I') {
					team[teamID].ID = teamID;
					
					team[teamID].penalty += 20;
				}
				else if (verdict == 'C') {
					team[teamID].ID = teamID;
					
					team[teamID].penalty += time;
					team[teamID].qSolved++;
					team[teamID].qMap[questionID] = true;
				}
			}
		}
		
		sort(team, team+101, &team_cmp);
		
		for(int i = 0; i < 101; ++i){
			if (team[i].qSolved > 0){
				cout << team[i].ID << " " << team[i].qSolved << " " << team[i].penalty << endl;
			}
		}
	}
	
	return 0;
}
