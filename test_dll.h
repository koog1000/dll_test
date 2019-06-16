#ifndef TEST_DLL_H
#define TEST_DLL_H

    #ifdef BUILD_DLL
        #define EXPORT __declspec(dllexport)
        #define _CALL_ __stdcall
    #else
        #ifdef BUILD_STATIC
            #define EXPORT 
            #define _CALL_ 
        #else
            #define EXPORT __declspec(dllimport)
            #define _CALL_ __stdcall
        #endif //BUILD_STATIC
    #endif //BUILD_DLL

    #include <string.h>
    #include <stdio.h>

    EXPORT int _CALL_ mul(int, int);
    EXPORT int _CALL_ add2(int);
    EXPORT int _CALL_ incr_by_ref(int*);
    EXPORT int _CALL_ incr_by_ref_loop(int*, int);
    EXPORT int _CALL_ get_val(char*, int*);
    EXPORT int _CALL_ set_val(char*, int);

#endif // TEST_DLL_H
