#include <stdio.h>
#define max 25
void main()
{
    int frag[max], blocks[max], files[max], i, j, no_of_blocks, no_of_file, temp, highest = 0;
    static int best_f[max], first_f[max];
    printf("\n\tMemory Management Scheme - Worst Fit");
    printf("\nEnter the number of blocks:");
    scanf("%d", &no_of_blocks);
    printf("Enter the number of files:");
    scanf("%d", &no_of_file);
    printf("\nEnter the size of the blocks:-\n");
    for (i = 1; i <= no_of_blocks; i++)
    {
        printf("Block %d:", i);
        scanf("%d", &blocks[i]);
    }
    printf("Enter the size of the files :-\n");
    for (i = 1; i <= no_of_file; i++)
    {
        printf("File %d:", i);
        scanf("%d", &files[i]);
    }
    for (i = 1; i <= no_of_file; i++)
    {
        for (j = 1; j <= no_of_blocks; j++)
        {
            if (best_f[j] != 1)
            {
                temp = blocks[j] - files[i];
                if (temp >= 0)
                    if (highest < temp)
                    {
                        first_f[i] = j;
                        highest = temp;
                    }
            }
        }
        frag[i] = highest;
        best_f[first_f[i]] = 1;
        highest = 0;
    }
    printf("\nFile_no:\tFile_size :\tBlock_no:\tBlock_size:\tFragement");
    for (i = 1; i <= no_of_file; i++)
        printf("\n%d\t\t%d\t\t\t%d\t\t\t%d\t\t\t%d", i, files[i], first_f[i], blocks[first_f[i]], frag[i]);
}
