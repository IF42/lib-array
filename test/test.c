#include <stdio.h>
#include <stdlib.h>
#include <array.h>


typedef struct 
{
    Array super;
    int vector[];
}IntArray;




int
main(void)
{
    IntArray * array = 
        (IntArray*) array_init(
                sizeof(int)
                , 3 
                , (int[]) {1,2,3});

    if(array == NULL)
    {
        fprintf(stderr, "Allocation error!\n");
        return EXIT_FAILURE;
    }

    for(size_t i = 0; i < array->super.size; i++)
    {
        printf("%ld | %d\n",i, array->vector[i]);
    }

    array = (IntArray*) array_resize(ARRAY(array), 5);

    if(array == NULL)
    {
        fprintf(stderr, "Resize error!\n");
        return EXIT_FAILURE;
    }

    putchar('\n');

    IntArray * clone = (IntArray*)array_clone(ARRAY(array));

    for(size_t i = 0; i < array->super.size; i++)
    {
        printf("%ld | %d | %d\n",i, array->vector[i], clone->vector[i]);
    }

    free(array);

    printf("Program exit success.\n");
    
    return EXIT_SUCCESS;
}

