#include <stdio.h>
//#include <sys/types.h>
//#include <sys/stat.h>
//#include <fcntl.h>
//#include <unistd.h>
//#include <sys/ioctl.h>
#include <sys/time.h>
#include <time.h>
//#include <stdlib.h>
//#include <errno.h>
#include <pthread.h>
//#include "ml605_api.h"
#include "ml605_api.cpp"
//#include "xpmon_be.h"
//#define RAWDATA_FILENAME    "/dev/ml605_raw_data"
//#define XDMA_FILENAME       "/dev/xdma_stat"
//#define PKTSIZE             4096
static const int size = 4096;
bool isclose = false;
int testfd;
int count=0;
long int mycount = 0;
int mysleep = 1000000;
unsigned char res[4096];
unsigned char  pool[25805];

unsigned char *p1;
int start = 0;
void extract(){
    int cnt = 0;

    unsigned char sendbuff[4096];
    while(cnt < 4096 ){
         sendbuff[cnt] = pool[start];
         start++;
         cnt++;
         if(start == 25804){
              start = 0;
          }
    }
   for( int i = 0 ; i < 4096 ; i++ ){
       res[i] = sendbuff[i];

   }


}
void render(){

    pool[0] = 0xbb;
    pool[1] = 0xb0;
    pool[2] = 0xcc;
    pool[3] = 0xc0;
    for(int i = 4 ; i < 204 ; i++){
         pool[i] = 0x00;
     }
    for( int i = 0 ; i < 50 ; i++ ){
         for( int j = 0 ; j < 512 ; j+= 2 ){
               pool[ i*512 + j + 204] = 0x00;
               pool[ i*512 + j + 1 +204] = j/2;

          }
    }    
/*
    for( int i = 0 ; i < 25804 ; i++ ){
          if( i % 4096 == 0){
                fprintf(fp1,"\n");
           }
          fprintf(fp1,"%x,",pool[i]);

     }
*/
    p1 = &pool[0];
   
}

void* mywrite(void* param)
{
unsigned char txbuff[size];

while(!isclose)
   {
   for(int i=0;i<size;i++){
      txbuff[i] = i % 200;
   }

    extract();
    

       int sendsize = ML605Send(testfd,res,size);
        //sleep(1);
/*
       for( int i = 0 ; i < 10 ; i++ ){
             printf("%x,",res[i]);
        }printf("\n sendsize :%d:",sendsize);
*/
	   if(sendsize!=size)printf("send error!\n");
	   
	  // usleep(1);
    count++;
   }

}

void* myread(void* param)
{
	unsigned char rxbuff[size];
	while(!isclose){    //usleep(1);
        	int recvsize = ML605Recv(testfd,rxbuff,4096);
	   	if(recvsize!=size)
			printf("recv error!\n");
        	else{
     			mycount = mycount + 1;
	/*
			printf("recv successful!=%d",recvsize);
            		for(int i=0;i<10;i++)
	           		printf("%x,",rxbuff[i]);
            		printf("one receive cycle\n");
*/
        	}//end else
		   
		//usleep(500000);

   	}// end while

}//myread
void* GetRate(void* param)
{   int scount;
    int ecount;
    double recvrata;
    while(!isclose){ 
          scount = mycount;
          printf("scount=%d\n",scount);
          //usleep(1000000);
          ecount = mycount;
          printf("ecount=%d\n",ecount);
          recvrata = (ecount - scount)*4096*8/1000000;
          printf("receive data rata = %f M/S \n",recvrata);
}
}
int main()
{
render();
   printf("my:hello fedora!\n");
if((testfd = ML605Open())<0)
   printf("open ml605 failed");

if(ML605StartEthernet(testfd, SFP_TX_START)<0) {
    printf("PCIe:Start ethernet failure\n");
	  ML605Close(testfd);
    exit(-1);
  }
/*
 pthread_t writethread;
  if (pthread_create(&writethread, NULL, mywrite, NULL)) 
  {
    perror("writethread process thread creation failed");
  }  
  sleep(1);
  

*/
  pthread_t readthread;
  if (pthread_create(&readthread, NULL, GetRate, NULL)) 
  {
    perror("readthread process thread creation failed");
  }  
  sleep(1);
  
  pthread_t ratathread;
  if (pthread_create(&ratathread, NULL, myread, NULL)) 
  {
    perror("readthread process thread creation failed");
  }  
  sleep(1);


		// read only one time
	
  
  char ch_input;
  scanf("%c", &ch_input);
  isclose=true;
  ML605Close(testfd);
}
