   #include <stdio.h>
   #include <sys/types.h>
   #include <unistd.h>
  

int main() {
   if(fork()==0){
        if(execlp("ls", "ls", "-a", NULL)==-1) perror(NULL);
   }
   else perror(NULL);
  
  return 0;
} 