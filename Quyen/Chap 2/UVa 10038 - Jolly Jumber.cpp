#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <cmath>
#include <fstream>
#include <algorithm>
//#define fin cin
//#define fout cout
using namespace std;
int main (void)
{
/*	ifstream fin;

	ofstream fout;

	fin.open("input.txt");

	fout.open("output.txt");*/
	int array [3000];
	int n;	
	while (cin>>n)
{
	for (int i = 0; i < n;i++)
			cin>>array[i];
	for (int j = 0; j < n - 1; j++)
	{
		array[j] = abs(array[j] - array [j+1]);
	}
	array[n - 1] = 0;
//	for (int x = 0; x < n;x++)
//		cout<<array[x]<<endl;
	sort(array, array + n);
	reverse(array, array +n);
	bool flag = true;		
	for (int a = 0; a < n - 1; a++)
		if (array[a] != array[a + 1] + 1)
			{
				flag = false;
				break;
			}
	if (flag)
		cout<<"Jolly"<<endl;
	else
		cout<<"Not jolly"<<endl;	
 fill_n(array,n,0);
		
}
//	fin.close();

//	fout.close();
	}
