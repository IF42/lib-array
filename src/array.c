#include "array.h"
#include <stdlib.h>
#include <string.h>


Array *
array_new(
    size_t item_size
    , size_t init_size)
{
    if(item_size == 0 
        || init_size == 0)
    {
        return NULL;
    }

    Array * array = malloc((sizeof(Array)) + (item_size * init_size));

    if(array == NULL) return NULL;

    array->size      = init_size;
    array->item_size = item_size;

    return array;
}


Array *
array_init(
    size_t item_size
    , size_t size
    , void * array_buffer)
{
    if(item_size == 0 
        || size == 0)
    {
        return NULL;
    }

    Array * array = 
        malloc((sizeof(Array)) + (item_size * size));

    if(array == NULL) return NULL;

    array->item_size = item_size;
    array->size      = size;

    memcpy(
        ARRAY(array)
        , array_buffer
        , size * item_size);


    return array;
}


Array *
array_resize(
    Array * array
    , size_t new_size)
{
    if(new_size == 0) return array;

    Array * resized_array = 
        malloc((sizeof(Array)) + (array->item_size * new_size));

    if(resized_array == NULL) return array;

    resized_array->item_size = array->item_size;
    resized_array->size      = new_size;

    memcpy(
        resized_array+sizeof(Array)
        , array+sizeof(Array)
        , array->item_size * array->size);
    
    free(array);

    return resized_array;
}





