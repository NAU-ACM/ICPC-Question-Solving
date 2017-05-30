#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main (void)
{
	int n;
	while(1){
		cin >> n;
		if(n == 0) 
			break;

		map<vector<int>, int> students;
		for (int i = 0; i < n;i++)
			{
				vector<int> courses(5);
				for (int j = 0; j < 5;j++)
					cin >> courses[j];
				sort(courses.begin(), courses.end());
				students[courses]++; //If the there are same combination the second value update					
			}
			int max = 1;
			int count = 0;
		for (map<vector<int>,int> :: iterator x = students.begin() ;x!= students.end();x++ )	
				{
					
					if (x->second == max)
					
						count+= x->second;	
					if (x->second > max)
					{
						max = x->second;
						count = max;
					}
				}
		cout<<count<<endl;		
	
}
	return 0;

}
