#ifndef _ARRAY_H_
#define _ARRAY_H_

#include <stdbool.h>
#include <stddef.h>


typedef struct 
{
    size_t size;
    size_t item_size;
}Array;


#define ARRAY(T)                                    \
    _Generic(                                       \
        (T)                                         \
        , Array*: ((void*)((T) + sizeof(Array))))


Array * 
array_new(
    size_t item_size
    , size_t init_size);


Array *
array_init(
    size_t item_size
    , size_t size
    , void * array_buffer);


Array *
array_resize(
    Array * array
    , size_t new_size);




#endif
