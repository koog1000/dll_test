# dll_test

Just to learn how to create dll without using Visual Studio.
Also to write code that can be used to create dll or to statically link against
Added a python test as well to check compatibility with python dll import

This project uses Windows Subsystem for Linux to crosscompile C source code using mingw gcc compiler. For whatever reason the windows native mingw compiler has issues. I also had issues compiling in linux VM and copying sources over to windows host. 

## pre build requirements
1. WSL setup ([Instructions](https://docs.microsoft.com/en-us/windows/wsl/install-win10))
2. MinGW environemnt installed in WSL (`sudo apt install mingw-w64`) 

## build 
1. download source `git clone ...; cd dll_test`
2. run make `make all`

This will create 1 dll (test.dll) and two executables (load_dll.exe and load_static.exe). As the names imply one dynamically loads the dll and the other is linked at compile time. If you have python installed in your windows host environment then you can run `python.exe test_dll.py` to see the performance comparison for running a loop in native (the dll), running the loop in python while calling dll function, and running the same loop in pure python. Of cource there are optimizations to play with, this is just a simple (read - stupid) example.

