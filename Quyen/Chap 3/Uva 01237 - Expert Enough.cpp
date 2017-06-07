// Uva 1237 - Expert Enough.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <string>
#include <fstream>
//#define fin cin
//#define fout cout
using namespace std;
 struct Car{
	string name;
	int low;
	int high;
};

int main()
{
/*	ifstream fin;

	ofstream fout;

	fin.open("input.txt");

	fout.open("output.txt");*/
	int t;
	cin >> t;
	while (t--)
	{
		int d;
		cin >> d;
		Car* pcar = new Car[d];
		int a = 0;
		while (a != d)
		{	
	//	cout<<a<<endl;
			//cout<<d<<endl;
		 	cin >> pcar[a].name >> pcar[a].low >> pcar[a].high;
		 	//cout<< pcar[d-1].name << pcar[d-1].low << pcar[d-1].high;
			a++;
		}
			
		int qSize;
		cin >> qSize;
		while (qSize--)
		{
			int q;
			cin >> q;
		//	cout<<"HI";
		int count = 0;
		int spec = 0;
			for (int i = 0;i < d; i++)
				{
		//	cout<<pcar[i].low<<pcar[i].high<<endl;	
					if (q >= pcar[i].low && q <= pcar[i].high)
						{
							count++;
							spec = i;
						}
	
				}
			if (count == 1)
				cout <<pcar[spec].name<<endl;
			else
				cout<<"UNDETERMINED"<<endl;	
				
		}
		if(t) cout<<endl;
	}
//	fin.close();
//	fout.close();
    return 0;
}


