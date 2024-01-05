#include <math.h>
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int i, n, inp[50], a = 0, head;
    printf("Enter the head position\n");
    scanf("%d", &head);
    printf("Enter the number of requests\n");
    scanf("%d", &n);
    printf("Enter the order\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &inp[i]);
    }
    printf("Seek Sequence is ");
    a = a + abs(head - inp[0]);
    printf("%d -> %d", head, inp[0]);
    for (i = 1; i < n; i++)
    {
        a = a + abs(inp[i] - inp[i - 1]);
        printf(" -> %d", inp[i]);
    }
    printf("total number of seek operations = %d\n", a);
}
