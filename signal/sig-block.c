/* 信号的阻断通过信号集控制
 * 信号集的1表示接收, 0 表示阻塞
 * 关键函数:  int sigprocmask(int how, const sigset_t *set, sigset_t *oldset);
 * */
 
#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

/* 信号的三种状态
 * block -> 设置为阻塞的话, 信号会保持成 pading 状态
 * pading -> 设置位 pading, 相当于队列为 1 的 queue
 * handle
 * */

/* 操作信号集的一系列函数
 * #include <signal.h>

 * int sigemptyset(sigset_t *set);

 * int sigfillset(sigset_t *set);

 * int sigaddset(sigset_t *set, int signum);

 * int sigdelset(sigset_t *set, int signum);

 * int sigismember(const sigset_t *set, int signum);
 * */


void handler(int sig) {
	if (sig == SIGQUIT) {
		/* 按 C-\ 的时候恢复 C-c 的功能 */
		sigset_t rset;
		sigemptyset(&rset);
		sigaddset(&rset, SIGINT);
		sigprocmask(SIG_UNBLOCK, &rset, NULL);
	} 
	/* 按照 peding 是长度为 1 的队列
	 * 一旦解除 block, 这个信号就会递达, 程序会立即退出
	 * */
	else if (sig == SIGINT)
		exit(0);
	else
		printf("handling~~~~\n");
}

void printsigset(sigset_t *set) {
	int i;
	for (i = 1; i < 65; i++) {
		if (sigismember(set, i))
			putchar('1');
		else
			putchar('0');
	}
	printf("\n");
}

int main(void)
{
	sigset_t pset;
	sigset_t bset;

	sigemptyset(&bset);
	sigaddset(&bset, SIGINT);

	/* 给两个信号 */
	if (signal(SIGINT, handler) == SIG_ERR)
		perror("signal error\n");
		
	if (signal(SIGQUIT, handler) == SIG_ERR)
		perror("signal error\n");
	
	/* 
	 * SIG_BLOCK 设置阻塞
	 * SIG_UNBLOCK 解除阻塞
	 * SIG_SETMASK 直接用 set 来设置阻塞
	 * */
	sigprocmask(SIG_BLOCK, &bset, NULL);
	
	while (1) {
		/* 把本进程的 pading 位读取出来. 
		 * 读取出的值就存在 pset 中
		 * */
		sigpending(&pset);
		printsigset(&pset);
		sleep(1);
	}
	
	return 0;
}
 
