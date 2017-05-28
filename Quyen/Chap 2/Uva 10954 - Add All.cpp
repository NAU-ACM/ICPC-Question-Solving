//Almost correct. Still have a few error in some cases
#include <iostream>
#include <vector>
#include <algorithm>
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
		sort(numbers.begin(), numbers.end());
		for (int j = 0; j < n - 1; j++)
		{
			numbers[j+1] = numbers[j] + numbers[j + 1];
			cost += numbers[j+1];
			
		}

		cout<<cost;

	}
    return 0;
}
