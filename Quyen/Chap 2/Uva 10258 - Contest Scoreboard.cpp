#include <iostream>
#include <vector>
#include <string>
#include <cstring>

#include <algorithm>


using namespace std;

int main (void)
{
	int t;
	cin >> t;
	
	while (t--)
	{
		int contestant,problem,time;
		string st;
		char stat;
		int array [101][10][1];
		memset (array,0,sizeof(array));
		
		while(cin>>contestant)
	{
		if (contestant == 0)
		break;
			cin >> problem;
			cin >> time;
			cin >> stat;
			if (stat == 'C')//Correct answer
				array[contestant-1][problem-1][0] += time;//Time for only 1 problem
			else if (stat == 'I')//Incorrect answer
				array[contestant-1][problem-1][0] += 20;//Time for only 1 problem
				
		
	//	cout << contestant<< " " << problem << " " << array[contestant - 1][problem-1][0];
		
	}

	
	int totalTime[101];
	int problemCount[101];
	for (int i = 0; i < 101; i++)//for each contestant
	{
		totalTime[i] = 0;
		problemCount[i] = 0;	
		for (int j = 0; j < 10; j++)//for each problem
		{
			totalTime[i] += array[i][j][0];
			if(array[i][j][0] != 0)
				problemCount[i]++;//counting the number of problem
		}//end for loop
		if(totalTime[i] != 0)
			{
			int j = i + 1;
			cout << j << " ";
			cout << problemCount[i]<< " ";		
			cout << totalTime[i] <<endl;
		}//end if statement
}//end for loop
	
}
	return 0;

}

