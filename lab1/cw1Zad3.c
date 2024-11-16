   #include <stdio.h>
   #include <fcntl.h>
   #include <unistd.h>


int main(int argc, char* argv[]) {
    
    if(argc==3){
        int file1 = open(argv[1], O_RDWR);
        int file2 = open(argv[2], O_RDWR|O_CREAT, 0664);

        

        if(file1!=-1 && file2!=-1){
            char buff[16];

            if(read(file1, buff, 16)!=-1 && write(file2, buff, 16)){
                printf("operacja zakonczona sukcesem");
            }
            else perror(NULL);
        }
        else perror(NULL);

        close(file1);
        close(file2);
    }
    else printf("Program urochumiony z nieprawidlowymi parametrami. Poadaj dwa parametry: pliku wjsciowegi i pliku docelowego");
  
  return 0;
} 