/* kill() 函数可以用来发送信号
 * 为什么要起这么奇怪的名字?
 * */
#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>


void handler(int sig)
{
	printf("get signal %d\n", sig);
	printf("逆子啊, 逆子啊!\n");
	exit(1);
}
/*  
 * If pid equals 0, then sig is sent to every process in the process group
 * of the calling process.

 * If pid equals -1, then sig is sent to every process for which the call‐
 * ing  process  has  permission  to  send  signals,  except for process 1
 * (init), but see below.

 * If pid is less than -1, then sig  is  sent  to  every  process  in  the
 * process group whose ID is -pid.
*/
int main(void)
{
	/* 先注册信号, 这个信号可以被子进程继承 */
	signal(SIGUSR1, handler);
	pid_t pid = fork();
	
	if (pid < 0 )
		perror("fork error\n");
	else if (pid == 0) {
		/* 发给粑粑一个信号 */
		kill(getppid(), SIGUSR1);
		exit(0);
	}
	
	while (1) {
		pause();
	}
	
	return 0;
}



