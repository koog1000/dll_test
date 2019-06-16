#include<stdio.h>
#include<windows.h>

int main(){

    HANDLE ldll;
    int (*add2)(int);
    int (*mul)(int,int);
        printf("ERROR with code: %d\n", GetLastError());

    ldll = LoadLibrary("test.dll");
    printf("Load returned: %d", &ldll);
        printf("ERROR with code: %d\n", GetLastError());
    if(ldll>(void*)HINSTANCE_ERROR)
    {
        add2 = GetProcAddress(ldll, "add2");
        mul = GetProcAddress(ldll, "mul");
        printf("add2(3): %d\nmul(4,5): %d\n", add2(3), mul(4,5));
    } 
    else 
    {
        printf("ERROR with code: %d\n", GetLastError());
    }

}
