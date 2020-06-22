#include <iostream>
int FibonacciSum(int maxvalue)
{
    if (maxvalue < 2)
        return 0;

    long int fiboA = 0, fiboB = 2;
    long int sum = fiboA + fiboB;

    while (fiboB <= maxvalue)
    {
        long int fiboNext = 4 * fiboB + fiboA;

        if (fiboNext > maxvalue)
            break;

        fiboA = fiboB;
        fiboB = fiboNext;
        sum += fiboB;
    }

    return sum;
}
int main()
{
    int maxvalue = 4000000;
    std::cout << FibonacciSum(maxvalue) << std::endl;
    //rezultatas = 4613732
}
