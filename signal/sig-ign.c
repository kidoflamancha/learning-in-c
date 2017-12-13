/* SIG_IGN 的使用
 * */
#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>


int main(void)
{
	/* 先弄一个僵尸进程出来 */
	pid_t pid = fork();
	
	/* 忽略掉子进程的信号 
	 * 因此不会产生僵尸进程 (魔道?)
	 * */
	signal(SIGCHLD, SIG_IGN);
	
	if (pid == 0) {
		/* 子进程直接退出, 父进程不调用 wait(), 形成僵尸 */
		exit(0);
	}
	
	while (1) {
		pause();
	}
	
	return 0;
}


