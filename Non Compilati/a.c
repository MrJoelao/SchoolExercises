#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
int ntimes = 0;
void stampa(){
printf ("processo %d ricevuto per %d volte il segnale\n",getpid(), ++ntimes);
}
int main(){
int pid, ppid;
signal(SIGUSR1, stampa);
if ((pid = fork()) < 0) /* fork fallita */
exit(1);
else if (pid == 0) /* figlio*/
{ ppid = getppid(); /* PID del padre */
for (;;){
//printf("FIGLIO %d\n", getpid());
sleep(1);
kill(ppid, SIGUSR1);
//pause();
}
}
else /* padre */
for(;;) /* ciclo infinito */
{ //printf("PADRE %d\n", getpid());
pause();
sleep(1);
kill(pid, SIGUSR1);
}
return 0;
}
