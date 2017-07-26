#include<iostream>
#include<algorithm>

using namespace std;
int arr[100000];
int main (void)
{

	int T;
	cin>>T;
	int Case = 1;
	while (T--)
		{
			
			int x;
			cin>>x;
		
			for (int j = 0; j < x;j++)
				cin>>arr[j];
			int k = arr[0];
		
			for (int i = 1; i < x ;i++)
				{
					k = max(k,arr[i] - arr[i-1]);
				}//find  k
				cout<<k<<endl;
			int j = k;	
			if(arr[0] == j)
				j--;
			for(int i = 1;i < x;i++)
				{
					int d = arr[i] - arr[i-1];
					if (d==j)
						j--;
					else if (d > j)	
					{
						k++;
						break;
					}
				}
			cout<<"Case "<<Case++<<": "<<k<<endl;
		}

		return 0;
}
