#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
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
	int n;
	vector<int> numbers;
		int qCase = 0;
	while(1)
	{
	
		cin>>n;
		if (n == 0)
			break;
		for (int i = 0; i < n;i++)
		{	
		int a;
		cin>>a;
			numbers.push_back(a);
		}
		
				
		int m;//number of queries
	

		
			cin>>m;
			qCase++;
			cout<<"Case "<<qCase<<":"<<endl;

			
			while(m--)
			{
				int q;//each query
				cin>>q;
				int ans = numbers[0] + numbers[1];
				int current;
				cout<<"Closest sum to "<<q;
				//cout<<numbers[0]<<" "<<numbers[1]<<endl;
				for(int i = 0; i < n; i++ ){
          		  for( int j = i+1; j < n; j++ ){
                	current =  numbers[i] + numbers[j];
                if( abs(ans - q) > abs(current - q))
					{
				//	cout<<"\n"<<abs(ans -q) <<" "<<abs(current-q)<<endl;
				//cout<<endl<<ans<<endl;
				  ans = current;
					}
           		 }	
        	}
			cout<<" is "<<ans<<"."<<endl;
		}
			
		}
		
//		fin.close();
//	fout.close();
		return 0;
	}
	
