CC=gcc
# -Wall 输出 gcc 的提示
# -g 在 bin 文件中插入标准调试
CFLAGS=-Wall -g -O2
# 这里放你要编译成的 bin 文件
BIN=largest_malloc_size

# 使用隐含规则将 .o 都生成 bin 文件.
all:$(BIN)
# 将所有的 .c 都编译成 .o
%.o: %.c
	$(CC) -c $(CFLAGS) $< -o $@
clean:
	-rm *.o $(BIN) -rf
# 忽略 all 或 clean 文件, 避免重名
.PHONY: clean all
