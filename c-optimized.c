#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: %s <maxRolls>\n", argv[0]);
        return 1;
    }

    int maxRolls = atoi(argv[1]);
    printf("Running for %d rolls\n", maxRolls);
    int rounds = 231;
    int rolls = 0;
    int ones = 0;
    int maxOnes = 0;
    int items[] = {1, 2, 3, 4};

    clock_t start = clock();
    srand(time(NULL));

    while (ones < 177 && rolls < maxRolls)
    {
        ones = 0;
        for (int i = 0; i < rounds; i++)
        {
            int roll = items[rand() % 4];
            if (roll == 1)
            {
                ones++;
                if (i > maxOnes && ones + (rounds - i) < maxOnes)
                {
                    break;
                }
            }
        }
        rolls++;
        if (ones > maxOnes)
        {
            printf("%d\n", ones);
            maxOnes = ones;
        }
    }

    clock_t end = clock();
    printf("Time: %f s\n", (double)(end - start) / CLOCKS_PER_SEC);
    printf("Max: %d\n", maxOnes);

    return 0;
}
