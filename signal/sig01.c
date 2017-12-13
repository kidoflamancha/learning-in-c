/* 最简单的注册信号测试
 * 将在输入 5 次信号后, 退出程序
 * */
#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

int count;
void interrupthandler(int sig)
{
	if (4 == count) {
		printf("MD, 算你赢\n");
		exit(0);
	}
	count++;
	printf("偏偏不退出\n");
}

int main(void)
{
	count = 0;
	/* 注册一个 signal */
	if (signal(SIGINT, interrupthandler) == SIG_ERR)
		perror("register signal error!\n");
	
	/* pause()  causes the calling process (or thread) to sleep until a signal
       is delivered that either terminates the process or causes  the  invoca‐
       tion of a signal-catching function.
	*/
	while (1) {
		pause();
	}
	
	return 0;
}
