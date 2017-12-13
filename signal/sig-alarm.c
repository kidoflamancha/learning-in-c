/* 研究下 alarm() 函数和 SIGALRM
 * */
#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>


void handler(int sig)
{
	printf("receive signal %d\n", sig);
	/* 做一个间接递归, handler() 函数会被一直调用 */
	alarm(1);
}

int main(void)
{
	/* 注册一个 signal */
	if (signal(SIGALRM, handler) == SIG_ERR)
		perror("register signal error!\n");
	
	/* 意思就是让内核 1s 后给这个进程发送一个 SIGALRM 信号 */
	alarm(1);
	
	while (1) {
		pause();
	}

	return 0;
}

