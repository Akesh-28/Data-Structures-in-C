#include <stdio.h>
#include <stdlib.h>
int main(){
    // malloc() - memory allocation
    int *ptr;
    ptr = (int*) malloc(4 * sizeof(int));

    if(ptr == NULL){
        printf("Memory not allocated");
        return 0;
    }

    //take input
    for(int i=0; i<4; i++){
        scanf("%d", &ptr[i]);
    }
    // print output
    for(int i=0; i<4; i++){
        printf("%d", ptr[i]);
    }
    free(ptr);
    return 0;

    // calloc() - contiguous allocation
    int *ptr;
    ptr = (int*) calloc(4, sizeof(int));

    if(ptr == NULL){
        printf("Memory not allocated");
        return 0;
    }
    //take input
    for(int i=0; i<4; i++){
        scanf("%d", &ptr[i]);
    }
    // print output
    for(int i=0; i<4; i++){
        printf("%d", ptr[i]);
    }
    free(ptr);
    return 0;

    // realloc() - reallocation
     
    int *ptr;
    ptr = (int*) malloc(3 * sizeof(int));
    ptr[0] = 10;
    ptr[1] = 20;
    ptr[2] = 30;

    ptr = (int*) realloc(ptr, 6 * sizeof(int));
    ptr[3] = 40;
    ptr[4] = 50;
    ptr[5] = 60;

    for(int i=0; i<6; i++){
    printf("%d ", ptr[i]);
    }
    free(ptr);
    return 0;
    
}
