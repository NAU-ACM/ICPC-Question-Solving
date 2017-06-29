#include <iostream>
#include <cmath>
using namespace std;

int rowPosition[1000];
int position[1000];
int ans;

bool place (int newCol,int newRow)
{
	for (int i = 1; i < newCol;i++)
		{
			if (rowPosition[i] == newRow)
				return false;
			if (abs(i - newCol) == abs(rowPosition[i] - newRow))
				return false;
		}
		return true;

}	
int count()
{
	int count = 0;
	for (int i = 1; i < 9;i++)
		if(rowPosition[i] - position[i] != 0)
			count++;
//	cout<<"Count: "<<count<<endl;
//	cout<<"Ans: "<<ans<<endl;		
	if (count < ans)
		ans = count;		
		
}

void backtrack(int col)
{
	if (col == 9)
	{
	 	count();
	// 	cout<<"Hi"<<endl;
	 }
	 
	for (int row = 1; row < 9;row++)
		{
			if (place(col,row))
				{
			//		cout<<place(row,col)<<endl;
				    rowPosition[col]=row;
					backtrack(col+1);
			}
		
		}
}



int main (void)
{
	int Case = 1;
	while(cin>>position[1]>>position[2]>>position[3]>>position[4]>>position[5]>>
				position[6]>>position[7]>>position[8])
	{
	
		
		ans = 1000;
		backtrack(1);
		
		cout<<"Case "<<Case++<<": "<<ans<<endl;
	//	for(int i = 1; i < 9;i++)
	//		cout<<rowPosition[i]<<" "<<endl;
	}
	return 0;
}
