GCC=x86_64-w64-mingw32-gcc
EXE=.exe
SO_EXT=dll

dll: # Test 1. make the executable that impots the dll, also make the dll
	@$(GCC) load_dll.c -o load_dll$(EXE)
	@$(GCC) -c -DBUILD_DLL test_dll.c -o test_dll.o
	@$(GCC) -shared test_dll.o -o test.$(SO_EXT)

static: # Test 2. Statically link against the dll source code (i.e. no dll generation)
	@$(GCC) -DBUILD_STATIC load_static.c test_dll.c -o load_static$(EXE)

all: dll static

clean:
	@rm *.exe *.dll *.o *.so
