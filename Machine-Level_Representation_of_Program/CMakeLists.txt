# 定义子项目名称
project(MachineLevelRepresentationOfProgram)

# 设置 C 标准
set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)

# 设置编译选项
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -g -O2 -Werror")

# 定义源目录
set(SRC_DIR ./src)

# 指定源文件
set(SOURCE_FILES
        ${SRC_DIR}/cpu/mmu.c
        ${SRC_DIR}/memory/instruction.c
        ${SRC_DIR}/memory/dram.c
        ${SRC_DIR}/disk/code.c
        ${SRC_DIR}/main.c
)

# 指定包含目录
include_directories(${SRC_DIR} ${SRC_DIR}/cpu ${SRC_DIR}/memory ${SRC_DIR}/disk)

# 定义生成的可执行文件
add_executable(program ${SOURCE_FILES})
