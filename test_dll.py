import time
from ctypes import windll, byref, c_int, c_char_p


test_lib = windll.LoadLibrary('test.dll')

start = time.monotonic()
a = c_int(3)
test_lib.incr_by_ref_loop(byref(a), 10000000)
print('C loop:', a, 'Time: ', time.monotonic()-start)

# start = time.monotonic()
# a = c_int(3)
# for _ in range(10000000):
#     test_lib.incr_by_ref(byref(a))
# print('Python loop calling dll:', a, 'Time: ', time.monotonic()-start)

start = time.monotonic()
a = 3
for _ in range(10000000):
    a = a+2
print('Pure python:', a, 'Time: ', time.monotonic()-start)

a = c_int(5)
print('a at start:', a)
test_lib.get_val(b'Test1', byref(a))  # NOTE: need to bytes, not str, in order for ctypes to correctly cast to char*
print('a after gettting Test1 value:', a)
test_lib.set_val(b'Test1', 100)
test_lib.get_val(b'Test1', byref(a))
print('a after setting Test1 to 100:', a)
