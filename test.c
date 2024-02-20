#include <stdio.h>
#include <stdlib.h>

int main()
{
    char *arr[] = {"hello", "ydik", "feh"};
    int size = sizeof(arr) / sizeof(arr[0]);
    printf("%d\n", size);
}