#import<iostream>
using namespace std;

int countDigits(int); // count the number of digits

int main()
{
	int bar_size;
	int num;
	
	while (scanf("%d%d", &bar_size, &num), bar_size)
	{
		//printf("bar_size is %d, num is %d\n", bar_size, num);

		// determine the number of digits in input number
		int digits = countDigits(num);
		
		//printf("digits is : %d\n", digits);
		
		// caluculate row and colunm for one digit
		int row = 2*bar_size + 3;
		int colunm = bar_size + 2;

		printf("row is %d\n", row);
		printf("colunm is %d\n", colunm);

		// determine total rows and total colunms to make 2 dimentional array
		int total_rows = row; // same as the row for each digits
		int total_colunms = (digits*colunm) + (digits - 1);

		printf("total_rows is %d\n", total_rows);
		printf("total_colunms is %d\n", total_colunms);

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
