// 1 small problem: the output is not separate for each alive warrior.
#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;
int main (void)
{
	int n;
	cin>>n;
	while (n--)
	{
		int b;//number of battle field
		cin>>b;
		int sg;//number of green armies
		cin>>sg;
		int sb;//number of blue armies
		cin>>sb;
		vector <int> Green;
		vector <int> Blue;
		int a = 0;
		for (int i = 0; i < sg; i++)
			{
				cin>>a;
				Green.push_back(a);
			}
		for (int j = 0; j <sb; j++)
		{
			cin>>a;
			Blue.push_back(a);
		}

		sort (Green.begin(),Green.end(),greater<int>());// Strongest warrior go first
		sort (Blue.begin(),Blue.end(), greater<int>());// Strongest warrior go first
		
		while(1)
		{
			
			for (int x= 0 ; x < b;x++)
			{
				//	cout<<Green[x]<<" ";
				//	cout<<Blue[x]<<endl;
				if (Green[x] > Blue[x])
					{
						Green[x] = Green[x] - Blue[x];
						Blue[x] = 0;
					}
				else if (Green[x] < Blue[x])
				{
					Blue[x] = Blue[x] - Green[x];
					Green[x] = 0; 
				}
				else
				{
						Green[x] = 0;
						Blue[x] = 0;
				}
				//	cout<<Green[x]<<" ";
			//		cout<<Blue[x]<<endl;
			}//end of one round
				
				
		for (int z = 0; z <sg; z++)
			if (Green[z] == 0)
				{
					Green.erase(Green.begin() + z);
					z = 0;
					sg--;
			}
			
		for (int z = 0; z < sb; z++)
			if(Blue[z] == 0)
				{
					Blue.erase(Blue.begin() + z);
					z = 0;
					sb--;
				}
		
//		cout << Green[0] << Green[1] << " ";		
//		cout << Blue[0]<< Blue[1] << " ";
		if (Blue.size() == 0 || Green.size() == 0)
				break;
	
			
	}
			
			//cout<<Blue.size()<<endl;
			//cout<<Green.size()<<endl;		
//	}
		if (Blue.size() == 0 && Green.size() == 0)
			cout<<"Both blue and green die";
		else if (Blue.size() == 0)//Green wins
		{	
				cout<<"Green wins"<<endl;
				for (int y = 0; y<sg;y++)
					if (Green[y] != 0)
						cout<<Green[y]<<" ";
			
			
		}
		else if (Green.size() == 0)
		{
				cout<<"Blue wins"<<endl;
				for(int y = 0; y < sb;y++)
					if(Blue[y] != 0)
						cout<<Blue[y]<<" ";
		}
		
	}
//		cout <<Green.size()<<endl;
//		cout <<Blue.size()<<endl;
return 0;
		
	}


