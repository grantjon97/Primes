// Jonathan Grant
// 9/10/2016
// Primes
// This program will allow the user to input
// a positive integer, and will find all of the prime
// numbers from zero to that number.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void Instructions(){

	printf("\nPrimes");
	printf("\nThis program will allow you to");
	printf("\nenter a positive integer of up to");
	printf("\nseven digits long. It will find all");
	printf("\nprime numbers from zero to your number.");
	printf("\n\n");
}

int Input(){

	char maxStr[7]; // Value of the maximum number

	printf("Input maximum value (integer): ");
	fgets(maxStr, 50, stdin);

	printf("\nThe max input range is %s\n", maxStr);

	// Return the integer value of the input
	return (atoi(maxStr));
}

void PrintPrimes(int primesList[], int max){

	int count = 1;
	int lineCount = 1;
	int primeCount = 1;

	printf("%5d", 2);

	while ((primeCount < 500) && (count < max)){

		// If the number is prime, print it.
		if (primesList[count] != 0){

			printf("%5d", count * 2 + 1);
			lineCount++;
			primeCount++;

			// Make a new line after every 10 primes.
			if (lineCount % 10 == 0)
				printf("\n\n");
		}

		count++;
	}

	printf("\n\n");
}

int main(){

	int max;                     // Range of prime numbers to find

	int increment;               // How much to increment when
				     // checking off multiples

	int numberOfPrimes = 1;      // Assume 2 is prime at the beginning
	int numberOfComparisons = 0;
	int numberOfAssignments = 0;

	Instructions();

	// Create a list with the size of half of the input range.
	// It's safe to do this because all even numbers are not prime.
	max = Input() / 2;
	int primeList[max];

	// Initialize all numbers in the array as unchecked.
	for (int i = 1; i < max; i++){

		primeList[i] = 1;
	}

	for (int i = 1; i < max; i++){

		numberOfComparisons++;

		// If the number hasn't been checked off, it's prime.
		if (primeList[i] != 0){

			numberOfPrimes++;

			// Increment finds how much to add to the prime
			// number in order to check off its multiples.
			increment = (i * 2) + 1;

			// Check off odd multiples of the prime number.
			for (int j = i + increment; j < max; j += increment){

				primeList[j] = 0;
				numberOfAssignments++;
			}
		}
	}

	PrintPrimes(primeList, max);

	printf("Number of primes:      %7d\n", numberOfPrimes);
	printf("Number of comparisons: %7d\n", numberOfComparisons);
	printf("Number of assignments: %7d\n\n", numberOfAssignments);
	printf("For verification on the accuracy of this program,");
	printf("\ndouble click on the link below:\n\n");
	printf("\thttps://primes.utm.edu/lists/small/1000.txt\n\n");
	printf("An analysis over the efficiency of this program\n");
	printf("has also been handed in via csa, called:\n\n");
	printf("\tprimes_analysis.txt\n\n");

	return 0;
}
