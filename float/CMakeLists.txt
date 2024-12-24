# 定义子项目名称
project(float)

# 设置 C 标准
set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)

# 设置编译选项
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -g -O2 -Werror")

# 指定源文件
set(SOURCE_FILES uint2float.c)

# 定义生成的可执行文件
add_executable(uint2float ${SOURCE_FILES})