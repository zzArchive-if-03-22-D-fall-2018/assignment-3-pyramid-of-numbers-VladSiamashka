/*----------------------------------------------------------
 *				HTBLA-Leonding / Class: <your class>
 * ---------------------------------------------------------
 * Exercise Number: 0
 * Title:			Pyramid of Numbers
 * Author:			<your name>
 * ----------------------------------------------------------
 * Description:
 * Calculates a pyramid of numbers, i.e., it multiplies a big
 * integer by the number 2, its result by 3, etc. and then
 * returns to the original value by subsequently dividing,
 * again starting by 2, 3, etc.
 * ----------------------------------------------------------
 */
#include <stdio.h>
#include <string.h>
/// The maximum number of digits allowed in a big int.
#define MAX_DIGITS 80

/** BigInt represents an integer number which can have MAX_DIGITS digits
*** @see MAX_DIGITS
*/
struct BigInt {
	/** number of digits of the big int. */
	int digits_count;

	/** array of digits of big int. */
	unsigned int the_int[MAX_DIGITS];
};

/** strtobig_int converts a string into a BigInt. If strtobig_int runs
*** against a character not between '0' and '9' the conversion stops
*** at this point.
*** @param *str The string to be converted.
*** @param len Number of characters in string to be converted.
*** @param *big_int The converted string now as BigInt.
* @return The number of characters converted.
*/
int strtobig_int(const char *str, int len, struct BigInt *big_int);

/** print_big_int() prints a BigInt.
*** @param *big_int The BigInt to be printed.
*/
void print_big_int(const struct BigInt *big_int);

/** multiply() multiplies a BigInt by an int.
*** @param big_int The BigInt to be multiplied.
*** @param factor The int value which is multiplied by BigInt.
*** @param *big_result The result of the multiplication.
*/
void multiply(const struct BigInt *big_int, int factor, struct BigInt *big_result);

/** divide() multiplies a BigInt by an int.
*** @param big_int The BigInt to be divided.
*** @param divisor The int value by which we want to devide big_int.
*** @param *big_result The result of the division.
*/
void divide(const struct BigInt *big_int, int divisor, struct BigInt *big_result);

/** copy_big_int() copies a BigInt to another BigInt.
*** @param from The source where we want to copy from.
*** @param *to The target where we want to copy to.
*/
void copy_big_int(const struct BigInt *from, struct BigInt *to);

/**
*** main() reads the base number from which the pyramid has to be calculated
*** into an array of char. The max. length of this number is MAX_DIGITS.
*** The number is checked to contain only digits. If not the program exits.
*** Then the inputted number is converted into a big int by calling the
*** function strtobig_int().
*** After the conversion the tower is calculated by calling the functions
*** multiply(), print_big_int(), and copy_big_int() consecutively from 2 to
*** 9 and then again with divide() instead of multiply() from 2 to 9.
***
*/
int main(int argc, char *argv[])
{
	struct BigInt number;
	struct BigInt big_result;
	char user_input[MAX_DIGITS];
	int len;

	printf("Pyramid of Numbers\n" );
	printf("Please enter a number:" );
	scanf("%s", user_input);
	len = strlen(user_input);
	strtobig_int(user_input, len, &number);

 for (int i = 2; i < 10; i++)
   {
		 print_big_int(&number);
     multiply(&number, i, &big_result);
     printf(" * %d = ", i);
     print_big_int(&big_result);
     printf("\n");
		 copy_big_int(&big_result,&number);
  }
	for (int i = 2; i < 10; i++)
{
		print_big_int(&number);
		divide(&number, i, &big_result);
		printf(" / %d = ", i);
		print_big_int(&big_result);
		printf("\n");
		copy_big_int(&big_result,&number);
}

	return 0;
}

int strtobig_int(const char *str, int len, struct BigInt *big_int)
{
	big_int->digits_count = 0;
	int k = len-1 ;
	for (int i = 0; i < len; i++)
	{

		if (str[i] >= '0'&&str[i] <= '9')
		{
			big_int->the_int[k]=str[i] - '0';
			k--;
			big_int->digits_count++;
		}
	}
}

void multiply(const struct BigInt *big_int, int factor, struct BigInt *big_result)
{
	big_result->digits_count=big_int->digits_count;
	big_result->digits_count--;
	int overflow = 0;
	int otherOverflow = 0;
	int tempResult = 0;
	for (int i = 0; i < big_int->digits_count; i++)
	{
		otherOverflow = overflow;
		tempResult=big_int->the_int[i]*factor;
		if (tempResult >=10 )
		{
			overflow = tempResult/10;

			big_result->the_int[big_result->digits_count]=tempResult%10+otherOverflow;

		}
		else
		{
			big_result->the_int[big_result->digits_count]=tempResult+otherOverflow;

		}
		big_result->digits_count--;

	}
}

void divide(const struct BigInt *big_int, int divisor, struct BigInt *big_result)
{
	return 0;
}

void print_big_int(const struct BigInt *big_int)
{
	for (int i = 0; i < big_int->digits_count; i++)
	{
		printf("%d",big_int->the_int[i]);
	}
}
void copy_big_int(const struct BigInt *from, struct BigInt *to)
{
     *to=*from;
}
