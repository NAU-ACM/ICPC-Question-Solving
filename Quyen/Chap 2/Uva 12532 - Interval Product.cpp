#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main (void)
{
	int n;
	int k;
	while(cin>>n>>k)
	{
		vector<int> sequence;
		string result;
		for (int i = 0;i < n;i++)
		{
			int a;
			cin>>a;
			sequence.push_back(a);
	}
		char command;
		
		while(k--)
	{
		cin>>command;
		if (command == 'C')
		{
			int I;
			int V;
			cin>>I;
			cin>>V;
			sequence[I - 1] = V;
//			for (int i = 0; i<n;i++)
//				cout<<sequence[i]<<" ";
	
		}
		else if (command == 'P')
			{
				int product = 1;
				int I;
				int J;
				cin>>I;
				cin>>J;
				for (int i = I-1; i < J;i++)
					product *= sequence[i];
				if(product == 0)
					result.push_back('0');
				else if (product > 0)
					result.push_back('+');
				else
					result.push_back('-');	
				product = 1;		
			}
//		cout<<k<<endl;
			
	}
		cout<<result<<endl;
	}
	return 0;
}
