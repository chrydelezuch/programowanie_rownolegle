   #include <stdio.h>
   #include <sys/types.h>
   #include <unistd.h>
   #include <sys/wait.h>

int main() {
   int pid = fork();
   if(pid==0){
    printf("Potomny: %d Przodek %d\n", getpid(), getppid());
   }
   else if(pid!=-1){
    int pid1 =fork();
    if(pid1==0) printf("Potomny: %d Przodek %d\n", getpid(), getppid());
   } 
   else perror(NULL);
  
  return 0;
} 