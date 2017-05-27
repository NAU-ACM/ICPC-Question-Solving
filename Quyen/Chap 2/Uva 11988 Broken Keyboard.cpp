#include <stdio.h>

int main (void)
{
	char text[100000];
	scanf ("%s", text);
	for (int i = 0; i < 100000;i++)
	{
		if(text[i] == ']' || text[i] == '[')
		{
			for (int x = i ; x < 100000 - 1 ; x++ )
				{
					text[x] = text[x+1];
					i = 0;
				}
			
		}
	}
	printf ("%s", text);
	return 0;
}
