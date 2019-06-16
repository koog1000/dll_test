import time
from ctypes import windll, byref, c_int, pointer


test_lib = windll.LoadLibrary('test.dll')

start = time.monotonic()
a = c_int(3)
test_lib.incr_by_ref_loop(byref(a), 10000000)
print('C loop:', a, 'Time: ', time.monotonic()-start)

start = time.monotonic()
a = c_int(3)
for _ in range(10000000):
    test_lib.incr_by_ref_loop(byref(a))
print('Python loop calling dll:', a, 'Time: ', time.monotonic()-start)

start = time.monotonic()
a = 3
for _ in range(10000000):
    a = a+2
print('Pure python:', a, 'Time: ', time.monotonic()-start)
