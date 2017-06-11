//Almost correct. Still have a few error in some cases
#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>

using namespace std;

int main()
{
	
	int n;

	while (cin >> n)
	{
		if (n == 0)
			break;
		vector<int> numbers;
		int numb;
		int cost = 0;
		for (int i = 0; i < n;i++)
			{
				cin >> numb;
				numbers.push_back(numb);
			}
		
		while (n != 1)
		{
			sort(numbers.begin(), numbers.end());
			cost +=	numbers[1] + numbers[0];
			numbers.push_back(numbers[0] + numbers[1]);
			numbers.erase(numbers.begin(),numbers.begin() + 2);
			n--;
		}

		cout<<cost<<endl;

	}
	
    return 0;
}
