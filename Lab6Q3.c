#include <stdio.h>
void main(){
    int i, j, temp, blocks[10], c[10], arr, no_of_block, ch, a;
    printf("\t\t FIRST FIT, BEST FIT, WORST FIT\n");
    printf("Enter the size of no. of blocks:"); scanf("%d", &no_of_block);
    for (i = 1; i <= no_of_block; i++){
        printf("Enter the size of %d block:", i); scanf("%d", &blocks[i]);
        c[i] = blocks[i];}
    printf("\nEnter the file size:"); scanf("%d", &arr);
    printf("\n1.First fit\n2.Best fit\n3.Worst fit\nEnter your choice by entering the specific number:"); scanf("%d", &ch);
    switch (ch) {
    case 1: for (i = 1; i <= no_of_block; i++){
            if (blocks[i] >= arr){
                printf("Arriving file is allocated to %d block.", i); break;}
            else continue;} break;
    case 2: for (i = 1; i <= no_of_block; i++) {
            for (j = i + 1; j <= no_of_block; j++) {
                if (blocks[i] > blocks[j]){
                    temp = blocks[i]; blocks[i] = blocks[j]; blocks[j] = temp;}}}
        for (i = 1; i <= no_of_block; i++) {
            if (blocks[i] >= arr){
                a = blocks[i]; break;}
            else continue;}
        for (i = 1; i <= no_of_block; i++){
            if (c[i] == a){printf("Arriving block is allocated to %d block.", i);}
        } break;
    case 3: for (i = 1; i <= no_of_block; i++) {
            for (j = 1; j < no_of_block; j++){
                if (blocks[j] >= blocks[j + 1]){
                    temp = blocks[j]; blocks[j] = blocks[j + 1]; blocks[j + 1] = temp;}}}
        for (i = 1; i <= no_of_block; i++){
            if (blocks[i] >= arr){
                printf("Arriving block is allocated to %d block.", i); break;}
            else continue;} break;
    default: printf("Enter the valid choice:");}}
