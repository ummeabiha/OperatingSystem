#include <stdio.h>
#include <stdlib.h>
int main(){
    int arr[199], i, j, n, TotalSeekOperations = 0, initial_head, disk_size, direction;
    printf("Enter the number of Requests\n"); scanf("%d", &n);
    printf("Enter the Requests sequence\n");
    for (i = 0; i < n; i++) scanf("%d", &arr[i]);
    printf("Enter initial head position\n"); scanf("%d", &initial_head);
    printf("Enter total disk size\n"); scanf("%d", &disk_size);
    printf("Enter the head movement direction for right '1' and for left '0'\n"); scanf("%d", &direction);
    for (i = 0; i < n; i++){
        for (j = 0; j < n - i - 1; j++){
            if (arr[j] > arr[j + 1]){
                int temp;
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp; }}}
    int index; for (i = 0; i < n; i++){
        if (initial_head < arr[i]){
            index = i; break;}}
    if (direction == 1) {
        for (i = index; i < n; i++){
            TotalSeekOperations = TotalSeekOperations + abs(arr[i] - initial_head);
            initial_head = arr[i];}
        for (i = index - 1; i >= 0; i--){
            TotalSeekOperations = TotalSeekOperations + abs(arr[i] - initial_head);
            initial_head = arr[i];}}
    else{
        for (i = index - 1; i >= 0; i--){
            TotalSeekOperations = TotalSeekOperations + abs(arr[i] - initial_head);
            initial_head = arr[i];}
        for (i = index; i < n; i++){
            TotalSeekOperations = TotalSeekOperations + abs(arr[i] - initial_head);
            initial_head = arr[i];}}
    printf("Total head movement is %d \n", TotalSeekOperations);}
