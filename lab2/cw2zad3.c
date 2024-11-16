   #include <stdio.h>
   #include <sys/types.h>
   #include <unistd.h>
   #include <sys/wait.h>

int main() {
   int pid = fork();
   if(pid==0){
    printf("Potomny: %d\n", getpid());
   }
   else if(pid!=-1){
    printf("Macierzysty");
    int status=-1;
    wait(&status);
    if(WIFEXITED(status)){
      printf("Status: %d\n", WEXITSTATUS(status));
    }
   } 
   else perror(NULL);
  
  return 0;
} 