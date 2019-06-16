#include<stdio.h>
#include<windows.h>

int main(){

    HANDLE ldll;
    int (*add2)(int);
    int (*mul)(int,int);

    ldll = LoadLibrary("test.dll");
    if(ldll>(void*)HINSTANCE_ERROR)
    {
        printf("Load DLL success. Returned: %d\n", &ldll);
        add2 = GetProcAddress(ldll, "add2");
        mul = GetProcAddress(ldll, "mul");
        printf("add2(3): %d\nmul(4,5): %d\n", add2(3), mul(4,5));
    } 
    else 
    {
        printf("ERROR with code: %d\n", GetLastError());
    }

}
