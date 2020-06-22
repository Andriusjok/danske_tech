#include <iostream>
int FibonacciSum(int maxvalue)
{
    if (maxvalue < 2)
        return 0;

    long int fiboA = 0, fiboB = 2;
    long int sum = fiboA + fiboB;

    while (fiboB <= maxvalue)
    {
        long long int ef3 = 4 * fiboB + fiboA;

        if (ef3 > maxvalue)
            break;

        fiboA = fiboB;
        fiboB = ef3;
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
