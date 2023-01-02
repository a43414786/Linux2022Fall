// Server side C/C++ program to demonstrate Socket
// programming
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>
#include <ctype.h>
#include <pthread.h>
#define PORT 8080

void* threadTask(void *sock);
void msgProcessing(char*msg,char* output);

int main(int argc, char const* argv[])
{
    for(;;){
        int server_fd;
        struct sockaddr_in address;
        int opt = 1;
        int addrlen = sizeof(address);
        
        // Creating socket file descriptor
        if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
            perror("socket failed");
            exit(EXIT_FAILURE);
        }

        // Forcefully attaching socket to the port 8080
        if (setsockopt(server_fd, SOL_SOCKET,
                    SO_REUSEADDR | SO_REUSEPORT, &opt,
                    sizeof(opt))) {
            perror("setsockopt");
            exit(EXIT_FAILURE);
        }
        address.sin_family = AF_INET;
        address.sin_addr.s_addr = INADDR_ANY;
        address.sin_port = htons(PORT);

        // Forcefully attaching socket to the port 8080
        if (bind(server_fd, (struct sockaddr*)&address,
                sizeof(address))
            < 0) {
            perror("bind failed");
            exit(EXIT_FAILURE);
        }
        if (listen(server_fd, 3) < 0) {
            perror("listen");
            exit(EXIT_FAILURE);
        }
        for(;;){
            pthread_t tid; // 宣告 pthread id
            int new_socket;
            if ((new_socket
                = accept(server_fd, (struct sockaddr*)&address,
                        (socklen_t*)&addrlen))
                < 0) {
                perror("accept");
                exit(EXIT_FAILURE);
            }
            pthread_create(&tid, NULL, threadTask, &new_socket); // 建立子執行緒            
        }
        // closing the listening socket
        shutdown(server_fd, SHUT_RDWR);
    }
    return 0;
}
void* threadTask(void *sock){
    int new_socket = *((int*) sock);
    int valread;
    char buffer[1024] = { 0 };
    char outputBuffer[1024] = { 0 };    
    for(;;){
        valread = read(new_socket, buffer, 1024);
        msgProcessing(buffer,outputBuffer);
        send(new_socket, outputBuffer, strlen(outputBuffer), 0);
        memset(buffer,0,1024);
        memset(outputBuffer,0,1024);
    }
    close(new_socket);
    pthread_exit(NULL); // 離開子執行緒
}
void msgProcessing(char*msg,char* output){
    char *temp = strtok(msg," ");
    int counter = 0;
    if(!strcmp(temp,"add"))
    {
        int sum = 0;
        temp = strtok(NULL," ");
        while(temp){
            for(int i = 0 ; i < strlen(temp) ; i++){
                if(isalpha(temp[i])){
                    strcpy(output,"Illegal input\n");
                    return;
                }
            }
            sum += atoi(temp);
            temp = strtok(NULL," ");
            counter++;
        }
        if(counter < 2){
            strcpy(output,"Wrong input number\n");
            return;
        }
        sprintf(output,"%d\n",sum);
    }
    else if(!strcmp(temp,"mul"))
    {
        int sum = 1;
        temp = strtok(NULL," ");
        while(temp){
            for(int i = 0 ; i < strlen(temp) ; i++){
                if(isalpha(temp[i])){
                    strcpy(output,"Illegal input\n");
                    return;
                }
            }
            sum *= atoi(temp);
            temp = strtok(NULL," ");
            counter++;
        }
        if(counter < 2){
            strcpy(output,"Wrong input number\n");
            return;
        }
        sprintf(output,"%d\n",sum);
    }
    else if(!strcmp(temp,"abs"))
    {
        int rst = 0;
        temp = strtok(NULL," ");
        while(temp){
            for(int i = 0 ; i < strlen(temp) ; i++){
                if(isalpha(temp[i])){
                    strcpy(output,"Illegal input\n");
                    return;
                }
            }
            rst = abs(atoi(temp));
            temp = strtok(NULL," ");
            counter++;
        }
        if(counter < 1){
            strcpy(output,"Illegal input\n");
            return;
        }
        sprintf(output,"%d\n",rst);
    }
    else if(!strcmp(temp,"kill"))
    {
        exit(0);
    }
    else
    {
        strcpy(output,"Hello\n");
    }

}
