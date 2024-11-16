   #include <stdio.h>
   #include <fcntl.h>
   #include <unistd.h>


int main(int argc, char* argv[]) {
    
    if(argc==3){
        int file1 = open(argv[1], O_RDWR);
        int file2 = open(argv[2], O_RDWR|O_CREAT, 0664);

        

        if(file1!=-1 && file2!=-1){
            char buff[1];
            
            int readE=read(file1, buff, 1);

        
            while(readE>0){
                int writeE=0;
                if(readE!=-1){
                   
                    if(buff[0]=='\n')writeE=write(file2, "\r\n", 2);
                    else{
                        writeE=write(file2, buff, 1);
                    } 
                    readE=read(file1, buff, 1);
                }
                if(writeE==-1||readE==-1){
                    perror(NULL);
                    break;
                } 
            }
        }
        else perror(NULL);

        close(file1);
        close(file2);
    }
    else printf("Program uruchomiony z nieprawidlowymi parametrami. Poadaj dwa parametry: pliku wjsciowegi i pliku docelowego");
  
  return 0;
} 
