# clang-format
```shell script
clang-format
    --style=file
    -i
    --verbose
    ./src/**/*.cpp
    ./src/**/*.hpp
    ./test/**/*.cpp 
    ./test/**/*.hpp
    ./fuzz_test/**/*.cpp
    ./fuzz_test/**/*.hpp
```

# cppcheck
```shell script
cppcheck --project=./build/Release/compile_commands.json 2> output.cppcheck
```