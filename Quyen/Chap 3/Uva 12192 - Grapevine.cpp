#include <iostream>
#include <algorithm>

using namespace std;

int main (void)
{
	while(1)
	{
	
	int row;
	cin>>row;
	int col;
	cin>>col;
	if(row == 0 && col == 0)
		break;
	int arr[row][col];
	
	for(int i = 0;i <row;i++)
		for(int j = 0; j < col;j++)
			cin>>arr[i][j];
			
	int q;
	cin>>q;
	while(q--)
		{
			int L;
			cin>>L;
			int U;
			cin>>U;
			
			int ans = 0;
			for(int j = 0; j < row;j++)
				{
					int* lb = lower_bound(arr[j], arr[j] + col,L);//finding the starting number for each line
					int index = lb - arr[j]; // get the index of the starting number
					for (int k = ans; k < row;k++)
						{
							if(j+k >= row || index + k >= col || arr[j+k][index + k] > U) 
						/* 3 conditions to terminate the loop
						   1: the last number of row
						   2: the last number of a collumn
						   3: if the diagonal index is larger than the upper bound
						*/
								break;
							if (k + 1 > ans)//add 1 if the break above not execute
							 ans = k + 1;	
						}
				}
			cout<<ans<<endl;
		}		
			cout<<"-"<<endl;
	}
	return 0;
}
