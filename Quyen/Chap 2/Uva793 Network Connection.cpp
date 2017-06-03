#include<iostream>
#include<sstream>
#include <fstream>
#define fin cin
#define fout cout
using namespace std;
int root(int Computer[],int i);
void Union(int Computer[],int size[],int A, int B);


int main (void)
{

/*	ifstream fin;

	ofstream fout;

	fin.open("input.txt");

	fout.open("output.txt");*/
	int n;
	cin>>n;
	while (n--)
	{
		int c;
		cin>>c;
		int size[c];
		int Computer[c];
		for (int i = 1; i <= c;i++)
			{
				Computer[i] = i;
				size[i] = 1;
		}
		int ss = 0;
		int us = 0 ;
		string st;
		getline(cin,st);
	//	getline(cin,st);
		while (getline(cin,st))
		{
			if (st == "")
				break;
			int ci;
			int cj;
			char status;	
			istringstream s(st);
			s>>status>>ci>>cj;
		
	//		cout<<status<<ci<<cj;
			if (status == 'c')
				
				{//cout<<"Union"<<endl;
					Union(Computer,size,ci,cj);
				}
			else 
				{
				//	cout<<"q"<<endl;
			//	cout<<root(Computer,ci)<<" "<< root(Computer,cj)<<endl;
					if (root(Computer,ci) == root(Computer,cj))
						ss++;
					else 
					 	us++;
				}
				 	
		}

		cout<<ss<<","<<us<<endl;
	if(n)	cout<<endl;
	
	}
//	fin.close();
//	fout.close();
	return 0;
}

int root(int Computer[],int i)
{
//	cout<<Computer[i]<< " "<< i<<endl;
    while(Computer[ i ] != i)           //chase parent of current element until it reaches root.
    {
  
    Computer[i] = Computer[Computer[ i ]] ;
       i = Computer[ i ];
    }
    return i;
}

void Union(int Computer[],int size[],int A, int B)
{
    int root_A = root(Computer,A);
    int root_B = root(Computer,B);
    if (root(Computer,A) == root(Computer,B))
    {
		return;
	}
    if(size[root_A] < size[root_B])
    {
		Computer[ root_A ] = Computer[root_B];
		size[root_B] += size[root_A];
		
	}
    else
    {
		Computer[ root_B ] = Computer[root_A];
		size[root_A] += size[root_B];
	}
}


