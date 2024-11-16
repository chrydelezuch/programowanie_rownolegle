   #include <stdio.h>
   #include <sys/types.h>
   #include <unistd.h>


int main() {
   int pid = fork();
   if(pid==0){
    printf("Potomny: %d\n", getpid());
   }
   else if(pid!=-1) printf("Macierzysty");
   else perror(NULL);
  
  return 0;
} 