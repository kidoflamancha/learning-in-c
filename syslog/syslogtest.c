#include <syslog.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

/* man syslog */
int main(void)
{
    /*
    * 一般用 LOCAL0 ~ LOCAL7 表示本地日志, 可以配合 
    * /etc/syslog.conf 过滤出来输出到什么位置.
    * 比如: local0.*  /var/log/mytest.log
    */
    openlog("syslogtest", LOG_PID, LOG_LOCAL0);
    syslog(LOG_INFO, "here is a test log with pid %d", (pid_t)getpid());
    return 0;
}