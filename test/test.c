#include <stdio.h>
#include <stdlib.h>
#include <array.h>


int
main(void)
{
    Array * array = array_init(sizeof(int), 3, (int[]){1,2,3});


    if(array == NULL)
    {
        fprintf(stderr, "Allocation error!\n");
        return EXIT_FAILURE;
    }

    for(size_t i = 0; i < array->size; i++)
    {
        printf("%ld | %d\n",i, ((int*)ARRAY(array))[i]);
    }


    array = array_resize(array, 5);

    if(array == NULL)
    {
        fprintf(stderr, "Resize error!\n");
        return EXIT_FAILURE;
    }

    putchar('\n');


    for(size_t i = 0; i < array->size; i++)
    {
        printf("%ld | %d\n",i, ((int*) ARRAY(array))[i]);
    }

    free(array);


    printf("Program exit success.\n");
    
    return EXIT_SUCCESS;
}

