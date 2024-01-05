#include <math.h>
#include <stdio.h>
int main(){
    int i, n = 8, arr[8] = {176, 60, 79, 114, 92, 41, 34, 11}, count = 0, head, temp[50], min, min_arr[50], j = 0, mini=0, head1;
    printf("Enter the Head: ");
    scanf("%d", &head);
    head1 = head;
    for (int k = 0; k < n; k++){
        for (i = 0; i < n; i++){
            temp[i] = abs(head - arr[i]);}
        min = temp[0];
        for (i = 1; i < n; i++){
            if (min > temp[i]){
                min = temp[i];
                mini = i;}}
        min_arr[j] = arr[mini];
        j++;
        head = arr[mini]; 
        arr[mini] = 999;}
    printf("Seek sequence is : ");
    printf("\n%d", head1);
    count = count + abs(head1 - min_arr[0]); 
    printf("\n%d", min_arr[0]);
    for (i = 1; i < n; i++){
        count = count + abs(min_arr[i] - min_arr[i - 1]);
        printf("\n%d", min_arr[i]);}
    printf("Total number of seek operations = %d", count);}
