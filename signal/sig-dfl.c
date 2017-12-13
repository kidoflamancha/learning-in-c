/* SIG_DFL 的用法
 * 可以使得信号恢复默认的 action
 * */
#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

#define DFL_ENABLE 0

void interrupthandler(int sig)
{
	printf("偏偏不退出\n");
}

int main(void)
{
#if DFL_ENABLE
	char in;
	/* 注册一个 signal */
	signal(SIGINT, interrupthandler);
	
	/* pause()  causes the calling process (or thread) to sleep until a signal
       is delivered that either terminates the process or causes  the  invoca‐
       tion of a signal-catching function.
	*/
	while (1) {
		in = getchar();
		if ('c' != in)
			pause();
		else
			signal(SIGINT, SIG_DFL);
	}
	
	return 0;
#else
	/* 另外一种恢复的用法
	 * 先保存原来的 signal 行为
	 * 再赋值
	 * */
	 
	char in;
	/* 注册一个 signal */
	__sighandler_t old = signal(SIGINT, interrupthandler);
	
	/* pause()  causes the calling process (or thread) to sleep until a signal
       is delivered that either terminates the process or causes  the  invoca‐
       tion of a signal-catching function.
	*/
	while (1) {
		in = getchar();
		if ('c' != in)
			pause();
		else
			signal(SIGINT, old);
	}
	
	return 0;
#endif
}

