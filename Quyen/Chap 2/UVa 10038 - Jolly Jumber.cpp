#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <cmath>
using namespace std;
int main (void)
{
	int n;
	
	while (cin>>n)
{

	int array[n];
	int diff[n-1];
	for (int i = 0; i < n;i++)
			cin>>array[i];
	for (int j = 0; j < n-1 ; j++)
		diff[j] = abs(array[j] - array [j+1]);
	for (int a = 0; a < n -1; a++)
		if (diff[a] != diff[a + 1] + 1)
			{
				cout<<"Not Jolly"<<endl;	
				break;
			}
		else if(a == n - 2)
			cout<<"Jolly"<<endl;
		
}
	}
