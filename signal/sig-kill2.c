/* kill() 函数可以用来发送信号
 * 为什么要起这么奇怪的名字?
 * 写俩瓜娃子的例子
 * */
#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>


void handler(int sig)
{
	if (sig == SIGUSR1)
		printf("大傻, 是你啊\n");
	else if (sig == SIGUSR2)
		printf("二傻, 你也来了啊\n");
}

int main(void)
{
	/* 先注册信号, 这个信号可以被子进程继承 */
	signal(SIGUSR1, handler);
	signal(SIGUSR2, handler);
	int sleeptime = 3;
	
	/* 先创建大傻 */
	pid_t pid = fork();
	
	if (pid < 0 )
		perror("fork error\n");
	else if (pid == 0) {
		/* 时不时烦一下粑粑 */
		while (1) {
			kill(getppid(), SIGUSR1);
			sleep(sleeptime);
		}
	}
	
	/* 创建二傻 */
	pid_t pid2 = fork();
	if (pid2 < 0 )
		perror("fork error\n");
	else if (pid2 == 0) {
		/* 时不时烦一下粑粑 */
		while (1) {
			kill(getppid(), SIGUSR2);
			sleep(sleeptime);
		}
	}
	while (1) {
		pause();
	}
	
	return 0;
}



