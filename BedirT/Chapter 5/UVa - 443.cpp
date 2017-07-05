#include <iostream>
#include <set>
using namespace std;

int main (){	
	int n;

	set<long> s;
	s.insert(1);

	for(int i = 0; i < 5842; ++i){
		long mn = *next(s.begin(), i);
		s.insert(mn*2);
		s.insert(mn*3);
		s.insert(mn*5);
		s.insert(mn*7);
	}
	while(cin >> n && n){
		long res = *next(s.begin(), n-1);
		
		printf("The %d", n);
		if(n % 10 == 1 && n % 100 != 11) 		printf("st");
		else if(n % 10 == 2 && n % 100 != 12) 	printf("nd");
		else if(n % 10 == 3 && n % 100 != 13) 	printf("rd");
		else 									printf("th");
		printf(" humble number is %ld.\n", res);

	}
}