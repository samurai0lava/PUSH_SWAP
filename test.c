#include <stdio.h>
#include <stdlib.h>

int main()
{

    // char *arr[] = {"hello", "ydik", "feh"};
    // int size = sizeof(arr) / sizeof(arr[0]);
    // printf("%d\n", size);
    int array[] = {1,2,3,4,7,9,0,8};
    printf("%ld", sizeof(array)/sizeof(int));
}