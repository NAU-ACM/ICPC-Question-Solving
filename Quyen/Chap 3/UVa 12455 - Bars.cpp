#include <iostream>

using namespace std;
int main (void)
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int p;
		cin>>p;
		int array[p];
		for (int a = 0; a < p;a++)
			cin>>array[a];
		int ans;
		bool check = false;
		for(int i = 0; i < (1<<p); i++ ){
			ans = 0;
			for (int j = 0; j < p; j++)
			 if (i & (1<<j))
			 	ans += array[j];
			if (ans == n)
			{
				check = true;
				break;	
			}
	}
    

		if (check) cout<<"YES"<<endl;
		else	   cout<<"NO"<<endl;	
		
	}
	
	return 0;
}
