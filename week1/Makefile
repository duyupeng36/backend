# week1/Makefile —— 你的第一个 Makefile
# make 命令会执行第一个目标（默认是 all）

CC      = gcc
CFLAGS  = -std=c23 -Wall -Wextra -g   # -g: 包含调试信息给 gdb 用

# 默认目标：构建所有程序
all: 01_hello 02_types 03_operators_flow

# 每个目标：目标名 : 依赖文件
01_hello: 01_hello.c
	$(CC) $(CFLAGS) -o $@ $<

02_types: 02_types.c
	$(CC) $(CFLAGS) -o $@ $<

03_operators_flow: 03_operators_flow.c
	$(CC) $(CFLAGS) -o $@ $<

# 清理所有编译产物
clean:
	rm -f 01_hello 02_types 03_operators_flow *.o *.i *.s

# 声明 clean 不是文件名，避免跟同名文件冲突
.PHONY: all clean
