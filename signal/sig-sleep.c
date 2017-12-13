/* 探究下 signal 对 sleep 函数的影响
 * */
#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

#define SLEEP_ENOUGHT 0

void interrupthandler(int sig)
{
	printf("receive signal %d\n", sig);
}

int main(void)
{
	/* 注册一个 signal */
	if (signal(SIGINT, interrupthandler) == SIG_ERR)
		perror("register signal error!\n");
	
	/* pause()  causes the calling process (or thread) to sleep until a signal
       is delivered that either terminates the process or causes  the  invoca‐
       tion of a signal-catching function.
	*/
#if SLEEP_ENOUGHT
	/* 这种情况下, 接受到信号后, sleep 函数就断了 */
	sleep(100);
	printf("weak up!\n");
#else
	/* 想要让它睡饱, 得这么做 */
	int lefttime = 10;
	
	do {	
		lefttime = sleep(lefttime);
		printf("lefttime is %d\n", lefttime);
	} while (lefttime > 0);
#endif

	return 0;
}
