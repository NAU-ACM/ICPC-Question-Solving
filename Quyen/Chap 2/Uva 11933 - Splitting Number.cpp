#include <iostream>
#include <bitset>
#include <cmath>
using namespace std;
int main (void)
{
	int n;
	
	while(1)
	{
		cin>>n;
		if (n == 0)
			break;
		int a = 0;
		int b = 0;
		string bit = bitset<32>(n).to_string();
		bool toA = true;
		bool toB = false;
		//cout<<bit[0];
		for (int i = 0; i < 32;i++)
			{
				if (bit[31 - i] == '1' && toA)
				{
					
					a += pow(2,i);
					toB = true;
					toA= false;
				}		
			else if (bit[31 - i] == '1' && toB)
			{
				b += pow(2,i);
				toA = true;
				toB= false;
			}	
		}
		cout << a << " ";
		cout << b << endl;
			
	}
	return 0;
	
}
