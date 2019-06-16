#ifdef BUILD_DLL
#define EXPORT __declspec(dllexport)
#define _CALL_ __stdcall
#else
#ifdef BUILD_STATIC
#include "test_dll.h"
#define EXPORT 
#define _CALL_ 
#else
#define EXPORT __declspec(dllimport)
#define _CALL_ __stdcall
#endif //BUILD_STATIC
#endif //BUILD_DLL

EXPORT int _CALL_ add2(int num){
  return num + 2;
}

EXPORT int _CALL_ mul(int num1, int num2){
  return num1 * num2;
}

EXPORT int _CALL_ incr_by_ref(int* num, int times)
{
    for(int i=0; i<times; i++)
    {
        *num += 2;
    }
    return 0;
}
