
#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/wait.h>
#include <unistd.h>
#include <arpa/inet.h>

#define SERVPORT 6001
#define SERVPORT2 6002



int sock_fd, recvbytes;
int sock_fd2, recvbytes2;
int sock_fd3, recvbytes3;
int sock_fd4, recvbytes4;
int sock_fd5, recvbytes5;
int sock_fd6, recvbytes6;
int sock_fd7, recvbytes7;
int sock_fd8, recvbytes8;
int sock_fd9, recvbytes9;
int sock_fd10, recvbytes10;
//Mu-MIMO
int sock_fd11, recvbytes11;
int sock_fd12, recvbytes12;
int sock_fd13, recvbytes13;
int sock_fd14, recvbytes14;
//CoMP_CB
int sock_fd15, recvbytes15;
int sock_fd16, recvbytes16;
int sock_fd17, recvbytes17;
int sock_fd18, recvbytes18;

int sock_fd19, recvbytes19;
int sock_fd20, recvbytes20;

struct hostent *host;
struct sockaddr_in serv_addr;
struct sockaddr_in serv_addr2;
struct sockaddr_in serv_addr3;
struct sockaddr_in serv_addr4;
struct sockaddr_in serv_addr5;
struct sockaddr_in serv_addr6;
struct sockaddr_in serv_addr7;
struct sockaddr_in serv_addr8;
struct sockaddr_in serv_addr9;
struct sockaddr_in serv_addr10;
struct sockaddr_in serv_addr11;
struct sockaddr_in serv_addr12;
struct sockaddr_in serv_addr13;
struct sockaddr_in serv_addr14;
struct sockaddr_in serv_addr15;
struct sockaddr_in serv_addr16;
struct sockaddr_in serv_addr17;
struct sockaddr_in serv_addr18;
struct sockaddr_in serv_addr19;
struct sockaddr_in serv_addr20;

int socket_init(){
    host=gethostbyname("127.0.0.1");
    sock_fd = socket(AF_INET, SOCK_DGRAM, 0);
    serv_addr.sin_family=AF_INET;
    serv_addr.sin_port=htons(7005);
    serv_addr.sin_addr = *((struct in_addr *)host->h_addr);
    bzero(&(serv_addr.sin_zero),8);

    sock_fd2 = socket(AF_INET, SOCK_DGRAM, 0);
    serv_addr2.sin_family=AF_INET;
    serv_addr2.sin_port=htons(7004);
    serv_addr2.sin_addr = *((struct in_addr *)host->h_addr);
    bzero(&(serv_addr2.sin_zero),8);

    sock_fd3 = socket(AF_INET, SOCK_DGRAM, 0);
    serv_addr3.sin_family=AF_INET;
    serv_addr3.sin_port=htons(7003);// for Channel H11
    serv_addr3.sin_addr = *((struct in_addr *)host->h_addr);
    bzero(&(serv_addr3.sin_zero),8);

    sock_fd4 = socket(AF_INET, SOCK_DGRAM, 0);
    serv_addr4.sin_family=AF_INET;
    serv_addr4.sin_port=htons(7006);// for Channel H11
    serv_addr4.sin_addr = *((struct in_addr *)host->h_addr);
    bzero(&(serv_addr4.sin_zero),8);

    sock_fd5 = socket(AF_INET, SOCK_DGRAM, 0);
    serv_addr5.sin_family=AF_INET;
    serv_addr5.sin_port=htons(7007);// for Channel H11
    serv_addr5.sin_addr = *((struct in_addr *)host->h_addr);
    bzero(&(serv_addr5.sin_zero),8);

    sock_fd6 = socket(AF_INET, SOCK_DGRAM, 0);
    serv_addr6.sin_family=AF_INET;
    serv_addr6.sin_port=htons(7008);// for Channel H11
    serv_addr6.sin_addr = *((struct in_addr *)host->h_addr);
    bzero(&(serv_addr6.sin_zero),8);


    sock_fd7 = socket(AF_INET, SOCK_DGRAM, 0);
    serv_addr7.sin_family=AF_INET;
    serv_addr7.sin_port=htons(7009);// for comp qpsk rx1
    serv_addr7.sin_addr = *((struct in_addr *)host->h_addr);
    bzero(&(serv_addr7.sin_zero),8);

    sock_fd8 = socket(AF_INET, SOCK_DGRAM, 0);
    serv_addr8.sin_family=AF_INET;
    serv_addr8.sin_port=htons(7010);// for Channel H11
    serv_addr8.sin_addr = *((struct in_addr *)host->h_addr);
    bzero(&(serv_addr8.sin_zero),8);

    sock_fd9 = socket(AF_INET, SOCK_DGRAM, 0);
    serv_addr9.sin_family=AF_INET;
    serv_addr9.sin_port=htons(7011);// for Channel H11
    serv_addr9.sin_addr = *((struct in_addr *)host->h_addr);
    bzero(&(serv_addr9.sin_zero),8);
    

    sock_fd10 = socket(AF_INET, SOCK_DGRAM, 0);
    serv_addr10.sin_family=AF_INET;
    serv_addr10.sin_port=htons(7012);// for Channel H11
    serv_addr10.sin_addr = *((struct in_addr *)host->h_addr);
    bzero(&(serv_addr10.sin_zero),8);

    sock_fd11 = socket(AF_INET, SOCK_DGRAM, 0);
    serv_addr11.sin_family=AF_INET;
    serv_addr11.sin_port=htons(7013);// for c1cc  stream 1
    serv_addr11.sin_addr = *((struct in_addr *)host->h_addr);
    bzero(&(serv_addr11.sin_zero),8);

    sock_fd12 = socket(AF_INET, SOCK_DGRAM, 0);
    serv_addr12.sin_family=AF_INET;
    serv_addr12.sin_port=htons(7014);// for c1cc  stream 2
    serv_addr12.sin_addr = *((struct in_addr *)host->h_addr);
    bzero(&(serv_addr12.sin_zero),8);

    sock_fd13 = socket(AF_INET, SOCK_DGRAM, 0);
    serv_addr13.sin_family=AF_INET;
    serv_addr13.sin_port=htons(7015);// for c1cc  stream 3
    serv_addr13.sin_addr = *((struct in_addr *)host->h_addr);
    bzero(&(serv_addr13.sin_zero),8);

    sock_fd14 = socket(AF_INET, SOCK_DGRAM, 0);
    serv_addr14.sin_family=AF_INET;
    serv_addr14.sin_port=htons(7016);// for c1cc  stream 4
    serv_addr14.sin_addr = *((struct in_addr *)host->h_addr);
    bzero(&(serv_addr14.sin_zero),8);


    sock_fd15 = socket(AF_INET, SOCK_DGRAM, 0);
    serv_addr15.sin_family=AF_INET;
    serv_addr15.sin_port=htons(7017);// for c1cc  stream 4
    serv_addr15.sin_addr = *((struct in_addr *)host->h_addr);
    bzero(&(serv_addr15.sin_zero),8);

    sock_fd16 = socket(AF_INET, SOCK_DGRAM, 0);
    serv_addr16.sin_family=AF_INET;
    serv_addr16.sin_port=htons(7018);// for c1cc  stream 4
    serv_addr16.sin_addr = *((struct in_addr *)host->h_addr);
    bzero(&(serv_addr16.sin_zero),8);

    sock_fd17 = socket(AF_INET, SOCK_DGRAM, 0);
    serv_addr17.sin_family=AF_INET;
    serv_addr17.sin_port=htons(7019);// for c1cc  stream 4
    serv_addr17.sin_addr = *((struct in_addr *)host->h_addr);
    bzero(&(serv_addr17.sin_zero),8);

    sock_fd18 = socket(AF_INET, SOCK_DGRAM, 0);
    serv_addr18.sin_family=AF_INET;
    serv_addr18.sin_port=htons(7020);// for c1cc  stream 4
    serv_addr18.sin_addr = *((struct in_addr *)host->h_addr);
    bzero(&(serv_addr18.sin_zero),8);

    sock_fd19 = socket(AF_INET, SOCK_DGRAM, 0);
    serv_addr19.sin_family=AF_INET;
    serv_addr19.sin_port=htons(7021);// for c1cc  stream 4
    serv_addr19.sin_addr = *((struct in_addr *)host->h_addr);
    bzero(&(serv_addr19.sin_zero),8);


    sock_fd20 = socket(AF_INET, SOCK_DGRAM, 0);
    serv_addr20.sin_family=AF_INET;
    serv_addr20.sin_port=htons(7022);// for c1cc  stream 4
    serv_addr20.sin_addr = *((struct in_addr *)host->h_addr);
    bzero(&(serv_addr20.sin_zero),8);


    return 0;
}


  
void socket_send_rx(char *s1,char *s2,char *s3,char *s4){
    sendto(sock_fd7,s1,SENDSIZE*3+20,0,(struct sockaddr *)&serv_addr7,sizeof(serv_addr));//port:7009, send to rx_1 CoMP_Stream
    sendto(sock_fd8,s2,SENDSIZE*3+20,0,(struct sockaddr *)&serv_addr8,sizeof(serv_addr));//port:7010, send to rx_1 QAM_Star
    sendto(sock_fd9,s3,SENDSIZE*3+20,0,(struct sockaddr *)&serv_addr9,sizeof(serv_addr));//port:7011, send to rx_1 QAM_Star
    sendto(sock_fd10,s4,SENDSIZE*3+20,0,(struct sockaddr *)&serv_addr10,sizeof(serv_addr));//port:7012, send to rx_1 QAM_Star
}
void socket_send_c1cc(char *s1){

    sendto(sock_fd11,s1,SENDSIZE*3+20,0,(struct sockaddr *)&serv_addr11,sizeof(serv_addr));//port:7005 , send to QPSK plot GUI 
    sendto(sock_fd12,s1,SENDSIZE*3+20,0,(struct sockaddr *)&serv_addr12,sizeof(serv_addr));//port:7005 , send to QPSK plot GUI 
    sendto(sock_fd13,s1,SENDSIZE*3+20,0,(struct sockaddr *)&serv_addr13,sizeof(serv_addr));//port:7005 , send to QPSK plot GUI 
    sendto(sock_fd14,s1,SENDSIZE*3+20,0,(struct sockaddr *)&serv_addr14,sizeof(serv_addr));//port:7005 , send to QPSK plot GUI
    // CoMP-CB
    sendto(sock_fd15,s1,SENDSIZE*3+20,0,(struct sockaddr *)&serv_addr15,sizeof(serv_addr));//port:7005 , send to QPSK plot GUI 
    sendto(sock_fd16,s1,SENDSIZE*3+20,0,(struct sockaddr *)&serv_addr16,sizeof(serv_addr));//port:7005 , send to QPSK plot GUI 
    sendto(sock_fd17,s1,SENDSIZE*3+20,0,(struct sockaddr *)&serv_addr17,sizeof(serv_addr));//port:7005 , send to QPSK plot GUI 
    sendto(sock_fd18,s1,SENDSIZE*3+20,0,(struct sockaddr *)&serv_addr18,sizeof(serv_addr));//port:7005 , send to QPSK plot GUI 
    sendto(sock_fd19,s1,SENDSIZE*3+20,0,(struct sockaddr *)&serv_addr19,sizeof(serv_addr));//port:7005 , send to QPSK plot GUI 

}

void socket_send(char *s1){

    sendto(sock_fd,s1,SENDSIZE*3+20,0,(struct sockaddr *)&serv_addr,sizeof(serv_addr));//port:7005 , send to QPSK plot GUI 
    sendto(sock_fd2,s1,SENDSIZE*3+20,0,(struct sockaddr *)&serv_addr2,sizeof(serv_addr));//port:7004, send to channel plot GUI
    sendto(sock_fd3,s1,SENDSIZE*3+20,0,(struct sockaddr *)&serv_addr3,sizeof(serv_addr));//port:7003, send to channel plot GUI
    sendto(sock_fd4,s1,SENDSIZE*3+20,0,(struct sockaddr *)&serv_addr4,sizeof(serv_addr));//port:7006, send to channel plot GUI
    sendto(sock_fd5,s1,SENDSIZE*3+20,0,(struct sockaddr *)&serv_addr5,sizeof(serv_addr));//port:7003, send to channel plot GUI
    sendto(sock_fd6,s1,SENDSIZE*3+20,0,(struct sockaddr *)&serv_addr6,sizeof(serv_addr));//port:7006, send to channel plot GUI
}
