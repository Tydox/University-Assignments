#include <stdio.h>
#include <stdlib.h>

#define SIZE2 2
#define SIZE3 3

int* getPrimeArr(int** arr, int rows, int cols, int* psize);
int isPrime(int num);

int main()
{
    int psize = 0;
    /////////////////////////////////////////////////////////////////////
    int* arrhead[SIZE2]; // pointer array of pointers
    // The mistake begin here!!! UP
    /////////////////////////////////////////////////////////////////////////
    int* arr1 = (int*)malloc(SIZE3 * sizeof(int)); //pointer array 1
    if (arr1 == NULL)
    {
        printf("Error: out of memory.\n");
        return -1;
    }
    int* arr2 = (int*)malloc(SIZE3 * sizeof(int)); // pointer array 2
    if (arr2 == NULL)
    {
        printf("Error: out of memory.\n");
        return -1;
    }
    arrhead[0] = arr1;
    arrhead[1] = arr2;
    printf("%s", "Welcome to my Prime Number Investigator\nI will need you to enter numbers and then I will let you know after many hard calculations,\nwhich numbers are Prime Numbers\n");
    for (int i = 0; i < SIZE2; ++i) // input numbers into the dynamic arrays
        for (int j = 0; j < SIZE3; ++j)
        {
            printf("Number[%d][%d]: ", i, j);
            scanf_s("%d", &(arrhead[i][j]));
        }
    int* adrprime = getPrimeArr(arrhead, SIZE2, SIZE3, &psize);
    printf("The prime numbers are:\n");
    for (int i = 0; i < psize; ++i)
        printf("%d ", adrprime[i]);
    free(adrprime);
    free(arr1);
    free(arr2);
    adrprime = NULL;
    arr1 = NULL;
    arr2 = NULL;
}

int* getPrimeArr(int** arr, int rows, int cols, int* psize)
{
    int prime_count = 0;
    //calculate the amount of prime numbers prior to allocating dynamic memory
    for (int i = 0; i < rows; ++i) // rows index
        for (int j = 0; j < cols; ++j) // cols index
            if (isPrime(arr[i][j]) == 0)
                ++prime_count;
    int* primenums = (int*)calloc(prime_count, sizeof(int)); // allocate memory
    if (primenums == NULL) // verify that the memory allocation is successful
    {
        puts("Memory Allocation Failed");
        return NULL;
    }
    prime_count = 0;
    //calculate the amount of prime numbers and insert them into the array
    for (int i = 0; i < rows; ++i) // rows index
        for (int j = 0; j < cols; ++j) // cols index
            if (isPrime(arr[i][j]) == 0)
                primenums[prime_count++] = arr[i][j]; // put the value of the number in the new array
    *psize = prime_count; // return the value of how many prime numbers there are
    return primenums; // return the address of the index of the first array
}

int isPrime(int num)
{
    if (num < 2)
        return -1; // -1 means the number is not a prime nor composite
    for (int i = 2; i <= num / 2; ++i)
        if (num % i == 0)
            return 1; // 1 means the number is a composite number
    return 0; // 0 means the number is a prime
}