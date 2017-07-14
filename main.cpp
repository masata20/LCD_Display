#import<iostream>
#import<math.h>
using namespace std;

int countDigits(int); // count the number of digits

void arrayInitializer(int, int, int**); // initializeing 2d array
void arrayDisplay(int, int, int**); // display 2d array

void lcdConverter(int, int, int, int**);

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

		// create array of input numbers
		int raw_number[digits];
		for (int i = 0, j = digits-1; i < digits; i++, j--)
		{
			raw_number[j] = num / int(pow(10, i)) % 10;	
		}

		/*
		for (int i = 0; i < digits; i++)
			printf("%d\n", raw_number[i]);
		*/
		
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
	
		// dynamically allocate the 2d array for lcd typed number 
		// 2 : display "-"
		// 1 : display "|" 
		// 0 : don't display bar 
	    int **lcd_number = new int*[total_rows];
		for (int i = 0; i < total_rows; i++)
		{
			lcd_number[i] = new int[total_colunms];
		}

		//initilza array with all 0s
		arrayInitializer(total_rows, total_colunms, lcd_number);

		//arrayDisplay(total_rows, total_colunms, lcd_number);


		// change array 0 to 1 where there is no bar
		// for each digits
		// loop digits times
		for (int i = 0; i < digits; i++)
		{
			lcdConverter(bar_size, i, raw_number[i], lcd_number);	
		}

		arrayDisplay(total_rows, total_colunms, lcd_number);

		// delete colunms arrays
		for (int i = 0; i < total_rows; i++)
			delete[] lcd_number[i];
		// delete row arrays
		delete[] lcd_number;
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

void arrayInitializer(int row, int colunm, int** arr)
{
		// Init with zeros, maybe another better ways		
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < colunm; j++)
		{
			arr[i][j] = 0;
		}
	}
}
void arrayDisplay(int row, int colunm, int** arr)
{ 

	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < colunm; j++)
		{
			printf("%d", arr[i][j]);
		}
		printf("\n");
	}
}

void lcdConverter(int bar_size, int digitNumber, int raw_value, int** arr)
{
	int row_begin = 0;
	int row_middle = bar_size + 1; // the middle row for lcd format numbers
	int row_end = 2*(bar_size) + 2; // not +3 since it is for index

	int colunm_begin, colunm_end;
	colunm_begin = (bar_size+2) * digitNumber + digitNumber;
	colunm_end = colunm_begin + (bar_size+1);

	//printf("digit number is %d\n", digitNumber);
    //printf("row_end is %d\n", row_end);
	//printf("colunm_begin is %d\n", colunm_begin);
	//printf("colunm_end is %d\n", colunm_end);
	

	if (raw_value == 0)
	{
		
		// for first row and end row
		for (int i = 1; i <= bar_size; i++)
		{
			arr[row_begin][colunm_begin+i] = 2;
			arr[row_end][colunm_begin+i] = 2;
		}

		// for first colunm and ene colunm
		for (int i = 1; i <= bar_size; i++)
		{
			// first half
			arr[row_begin+i][colunm_begin] = 1;
			arr[row_begin+i][colunm_end] = 1;

			// second half
			arr[row_end-i][colunm_begin] = 1;
			arr[row_end-i][colunm_end] = 1;
		}

		return;
	}
	 
	if (raw_value == 1)
	{
		// for end colunm
		// first half
		for ( int i = 1; i <= bar_size; i++)
		{
			// first half
			arr[row_begin+i][colunm_end] = 1;
			
			// second half
			arr[row_end-i][colunm_end] = 1;
		}

		return;
	}

	if (raw_value == 2)
	{
		// for rows
		for (int i = 1; i <= bar_size; i++)
		{
			// first row
			arr[row_begin][colunm_begin+i] = 2;
			// middle row
			arr[row_middle][colunm_begin+i] = 2;
			// end row
			arr[row_end][colunm_begin+i] = 2;
		}

		// for first colunm and ene colunm
		for (int i = 1; i <= bar_size; i++)
		{
			// first half, end column
			arr[row_begin+i][colunm_end] = 1;

			// second half, first, colunm
			arr[row_end-i][colunm_begin] = 1;
		}
		return;
	}

	if (raw_value == 3)
	{
		// for rows
		for (int i = 1; i <= bar_size; i++)
		{
			// first row
			arr[row_begin][colunm_begin+i] = 2;
			// middle row
			arr[row_middle][colunm_begin+i] = 2;
			// end row
			arr[row_end][colunm_begin+i] = 2;
		}

      	// for end colunm
		for (int i = 1; i <= bar_size; i++)
		{
			// first half, end column
			arr[row_begin+i][colunm_end] = 1;

			// second half, first, colunm
			arr[row_end-i][colunm_end] = 1;
		}


		return;
	}

	if (raw_value == 4)
	{
		// for rows
		for (int i = 1; i <= bar_size; i++)
		{
			// middle row
			arr[row_middle][colunm_begin+i] = 2;
		}
		return;
	}

	if (raw_value == 5)
	{

		return;
	}

	if (raw_value == 6)
	{

		return;
	}

	if (raw_value == 7)
	{

		return;
	}

	if (raw_value == 8)
	{

		return;
	}

	if (raw_value == 9)
	{

		return;
	}

}
