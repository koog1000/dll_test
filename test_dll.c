

#include "test_dll.h"

typedef struct reg_map
{
    char name[255];
    int value;
} reg_map_t;

reg_map_t reg[2] = {
    {"Test1", 56},
    {"Test2", 123}
};

EXPORT int _CALL_ get_val(char* string, int* value)
{
    for(int i=0; i < (sizeof(reg)/sizeof(reg_map_t)); i++)
    {
        if (strcmp(reg[i].name, string) == 0)
        {
            *value = reg[i].value;
            return 0;
        }
    }
    return -1;
}

EXPORT int _CALL_ set_val(char* string, int value)
{
    for(int i=0; i < (sizeof(reg)/sizeof(reg_map_t)); i++)
    {
        if (strcmp(reg[i].name, string) == 0)
        {
            reg[i].value = value;
            return 0;
        }
    }
    return -1;
}

EXPORT int _CALL_ add2(int num){
    return num + 2;
}

EXPORT int _CALL_ mul(int num1, int num2){
    return num1 * num2;
}

EXPORT int _CALL_ incr_by_ref(int* num)
{
    *num += 2;
    return 0;
}

EXPORT int _CALL_ incr_by_ref_loop(int* num, int times)
{
    for(int i=0; i<times; i++)
    {
        *num += 2;
    }
    return 0;
}
