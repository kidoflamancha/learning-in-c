# 写一些关于 makefile 的自动变量练习

# $@ 代表当前的 target
test.o:
	@echo $@
	
# $< 代表第一个前置条件
a:
b:
test1: a b
	@echo $<

# $^ 代表所有前置条件
test2: a b
	@echo $^
