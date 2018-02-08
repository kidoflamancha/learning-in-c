/* 简单练习下 fork 的基本操作 */

#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <unistd.h>

int main(void)
{
	pid_t pid = fork();
	int status = 0;
	
	if (pid < 0)
		perror("fork error\n");
	else if(pid == 0) {
		int i;
		for (i=0; i < 5; i++) {
			printf("%d..", i);
			sleep(1);
		}
	} else {
		/* 等待子进程结束 
		 * pid 代表子进程 ID
		 * */
		wait(&status);
		printf("\n count end, end process, status = %d\n", status);
	}
	return 0;
}
