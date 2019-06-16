import time
from ctypes import windll, byref, c_int, pointer


test_lib = windll.LoadLibrary('test.dll')

print(test_lib.add2(10))

start = time.monotonic()
a = c_int(3)
test_lib.incr_by_ref(byref(a), 100000000)
print('C code:', a, 'Time: ', time.monotonic()-start)

start = time.monotonic()
a = 3
for _ in range(100000000):
    a = a+2
print('C code:', a, 'Time: ', time.monotonic()-start)
