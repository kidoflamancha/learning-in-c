txt = Hello World

# 两种方式都可以调用变量
# 一般用${}调用 shell 变量
# $() 调用 makefile 变量
test:
	@echo ${txt}
	@echo $(txt)
test1:
	echo ${txt}
