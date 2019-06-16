#! /bin/bash

# run the build outputs, the testing is up to the user to determine if everything ran correctly
./load_dll.exe
./load_static.exe
python.exe test_dll.py