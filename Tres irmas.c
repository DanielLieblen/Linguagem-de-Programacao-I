#include <stdio.h>

main()
{
    int n1 = 0, n2 = 0, n3 = 0;

    scanf("%d", &n1);
    scanf("%d", &n2);
    scanf("%d", &n3);

    if (n1 < 5 && n1 > 100 && n2 < 5 && n2 > 100 && n3 < 5 && n3 > 100)
    {
        printf("Invalid argument");
    }
    else
    {
        if ((n1 > n2 && n2 > n3) || (n2 > n1 && n2 < n3))
        {
            printf("idade do meio: %d\n", n2);
        }
        else if ((n1 > n3 && n3 > n2) || (n2 > n3 && n3 > n1))
        {
            printf("idade do meio: %d\n", n3);
        }
        else if ((n3 > n1 && n1 > n2) || (n2 > n1 && n1 > n3))
        {
            printf("idade do meio: %d\n", n1);
        }
        if ((n1 == n2) && (n2 == n3) && (n3 == n1))
            printf("idade do meio eh: %d\n", n1);
    }
}
