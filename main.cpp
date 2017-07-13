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

	//	printf("row is %d\n", row);
	//	printf("colunm is %d\n", colunm);

		// determine total rows and total colunms to make 2 dimentional array
		int total_rows = row; // same as the row for each digits
		int total_colunms = (digits*colunm) + (digits - 1);

	//	printf("total_rows is %d\n", total_rows);
	//	printf("total_colunms is %d\n", total_colunms);
	
		// declare 2 dimentional array all elements are zero
		// 0 : display bar
		// 1 : don't display bar
		int lcd_number[total_rows][total_colunms];

		// Init with zeros, maybe another better ways		
		for (int i = 0; i < total_rows; i++)
		{
			for (int j = 0; j < total_colunms; j++)
			{
				lcd_number[i][j] = 0;
			}
		}
       /*	
		for (int i = 0; i < total_rows; i++)
		{
			for (int j = 0; j < total_colunms; j++)
			{
				printf("%d", lcd_number[i][j]);
			}
			printf("\n");
		}
		*/

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
