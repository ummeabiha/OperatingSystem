#include <stdio.h>
#define max 25
void main()
{
    int frag[max], blocks[max], file_size[max], i, j, no_of_blocks, no_of_files, temp;
    static int best_f[max], first_f[max];
    printf("\n\tMemory Management Scheme - First Fit");
    printf("\nEnter the number of blocks: ");
    scanf("%d", &no_of_blocks);
    printf("Enter the number of files: ");
    scanf("%d", &no_of_files);
    printf("\nEnter the size of the blocks: \n");
    for (i = 1; i <= no_of_blocks; i++)
    {
        printf("Block %d:", i);
        scanf("%d", &blocks[i]);
    }
    printf("Enter the size of the files:-\n");
    for (i = 1; i <= no_of_files; i++)
    {
        printf("File %d:", i);
        scanf("%d", &file_size[i]);
    }
    for (i = 1; i <= no_of_files; i++)
    {
        for (j = 1; j <= no_of_blocks; j++)
        {
            if (best_f[j] != 1)
            {
                temp = blocks[j] - file_size[i];
                if (temp >= 0)
                {
                    first_f[i] = j;
                    break;
                }
            }
        }
        frag[i] = temp;
        best_f[first_f[i]] = 1;
    }
    printf("\nFile no:\tFile Size: \tBlock No:\tBlock Size:\tFragment");
    for (i = 1; i <= no_of_files; i++)
    {
        printf("\n%d\t\t\t%d\t\t\t%d\t\t\t%d\t\t\t%d", i, file_size[i], first_f[i], blocks[first_f[i]], frag[i]);
    }
}
