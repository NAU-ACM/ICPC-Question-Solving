#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int main (void)
{
	int n;
	int count = 0;
	while(1)
	{
		cin>>n;
		int array[n];
		if (n != 0 && count != 0)
			cout<<endl;
		else if(n == 0)
			break;
		count++;	
		for(int i = 0; i < n;i++)
				cin>>array[i];
			
		
		for (int a = 0; a < n - 5;a++)
			for (int b = a + 1; b < n - 4;b++)
				for(int c = b + 1; c < n - 3; c++)
					for(int d = c + 1;d < n - 2; d ++)
						for(int e = d + 1; e < n - 1; e++ )
							for(int f = e + 1; f < n;f++)
							cout<<array[a]<<" "<<array[b]<<" "<<array[c]<<" "<<array[d]<<" "<<array[e]<<" "<<array[f]<<endl;
	
								
	}
	return 0;
}
