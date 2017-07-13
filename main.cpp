#import<iostream>
using namespace std;

int countDigits(int); // count the number of digits

int main()
{
	int bar_size;
	int num;
	
	while (scanf("%d%d", &bar_size, &num), bar_size)
	{
		printf("bar_size is %d, num is %d\n", bar_size, num);

		int digits = countDigits(num);
		
		printf("digits is : %d\n", digits);



	}

	return 0;
}

int countDigits(int num)
{
	int digits = 1;
	//dont forget = sign
	while (num /= 10)
		digits++;
	return digits;
}
