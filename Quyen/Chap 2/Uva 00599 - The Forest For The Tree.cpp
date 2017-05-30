#include <iostream>
#include <string>

using namespace std;
int size[26];
int Alphabet[26];

void initialize()
{
	
    for(int i = 0;i<26;i++)
    {
	
	Alphabet[i] = i ;
	size[ i ] = 1;
	}	
}

int root(int i)
{
    while(Alphabet[ i ] != i)           //chase parent of current element until it reaches root.
    {
  
    Alphabet[i] = Alphabet[Alphabet[ i ] ] ;
       i = Alphabet[ i ];
    }
    return i;
}

void Union(int A, int B)
{
    int root_A = root(A);
    int root_B = root(B);
    if (root(A) == root(B))
    {
		return;
	}
    if(size[root_A] < size[root_B])
    {
		Alphabet[ root_A ] = Alphabet[root_B];
		size[root_B] += size[root_A];
		size[root_A] = 0;
	}
    else
    {
		Alphabet[ root_B ] = Alphabet[root_A];
		size[root_A] += size[root_B];
		size[root_B] = 0;
	}
	
}




int main (void)
{
	int n;
	cin>>n;
	while (n--)
	{
		initialize();
		string s;
		string a;
		while(1)
			{
		//		cout<<"hi";
				cin>>s;
				if (s[0] == '*')
					break;	
				Union(s[1]-65, s[3] - 65);
			}
		cin>>a;
		int tree = 0;
		int acorn = 0;
		for (int x = 0; x <26;x++)
			cout<<size[x]<<endl;
		for (int i = 0; i < a.size(); i+=2)
			{
				size[a[i] - 65]++;
			}
		for (int j = 0; j < 26;j++)
			{
				if (size[j] > 2)
				tree++;
				else if (size[j] == 2)
					acorn++;
			}
	//	for (int x = 0; x <26;x++)
	//		cout<<size[x]<<endl;
		cout<<"There are "<<tree<<" tree(s)";
		cout<<" and "<<acorn<<" acorn(s)";			
	}
	return 0;
}
