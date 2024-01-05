#include <stdio.h>
#include <stdlib.h>
int mutex = 1, full = 0, empty = 10, x = 0;
void producer()
{
    --mutex;
    ++full;
    --empty;
    x++;
    printf("\nproducer produces"
           "item %d",
           x);
    ++mutex;
}
void consumer()
{
    --mutex;
    --full;
    ++empty;
    printf("\nconsumer consumes"
           "item %d",
           x);
    x--;
    ++mutex;
}
int main()
{
    int n, i;
    printf("\n1.Press 1 for producer"
           "\n2.Press 2 for consumer"
           "\n3.Press 3 for exit");
    for (i = 1; i > 0; i++)
    {
        printf("\n enter your choice");
        scanf("%d", &n);
        switch (n)
        {
        case 1:
            if ((mutex == 1) && (empty != 0))
            {
                producer();
            }
            else
            {
                printf("buffer is full");
            }
            break;
        case 2:
            if ((mutex == 1) && (full != 0))
            {
                consumer();
            }
            else
            {
                printf("buffer is empty");
            }
            break;
        case 3:
            exit(0);
            break;
        }
    }
}