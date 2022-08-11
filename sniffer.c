#include<stdio.h>	//For standard things
#include<stdlib.h>	//malloc
#include<string.h>	//memset
#include<netinet/ip_icmp.h>	//Provides declarations for icmp header
#include<netinet/udp.h>	//Provides declarations for udp header
#include<netinet/tcp.h>	//Provides declarations for tcp header
#include<netinet/ip.h>	//Provides declarations for ip header
#include<sys/socket.h>
#include<arpa/inet.h>

#include <sys/socket.h>
#include <linux/if_packet.h>
#include <net/ethernet.h>
#include <stdio.h>

#define SOURCE_IP "127.0.0.1"
// i.e the gateway or ping to google.com for their ip-address
#define DESTINATION_IP "8.8.8.8"
#define SIZE 10000


socklen_t len;
struct sockaddr_in srcaddr, destaddr;// SOCKADDR_IN structure specifies a transport address and port for the AF_INET address family.
// from this struct we know the src info and the dest info of what we sniffed.

void print_ip_header(unsigned char* Buffer, int Size)
{
    printf("Sniffing info ..\n");
	unsigned short iphdrlen;
		
	struct iphdr *iph = (struct iphdr *)Buffer;
	iphdrlen =iph->ihl*4;
	
	memset(&srcaddr, 0, sizeof(srcaddr));
	srcaddr.sin_addr.s_addr = iph->saddr;
	
	memset(&destaddr, 0, sizeof(destaddr));//dest
	destaddr.sin_addr.s_addr = iph->daddr;
	
	printf("Code             : %d\n",(unsigned int)iph->tos);
	printf("Protocol         : %d\n",(unsigned int)iph->protocol);
	printf("Source IP        : %s\n",inet_ntoa(srcaddr.sin_addr));//inet_ntoa() — Get the decimal Internet host address.
	printf("Destination IP   : %s\n",inet_ntoa(destaddr.sin_addr));
    printf("\n");
}

int main(){
    int sockfd,recvm,recvf,flags = 0;
    char buf[SIZE];
    int sniff = 1; 

    sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
    if (sockfd < 0){
        perror("sock:");
        exit(1);
    }
    len = sizeof(struct sockaddr_in);    
    printf("Ready to sniff...\n");
    while(sniff){ 
        printf("sniffing\n");
        recvf = recvfrom(sockfd,buf,SIZE,0,(struct sockaddr *)&srcaddr,&len);//sniff the messege sent from client to server
        // recvm = recvmsg(sockfd, msg ,flags);
        printf("\n");
        printf("Recv'd %d bytes\n",recvf);
        buf[recvf]='\0';
        printf("\n");
        print_ip_header(buf,SIZE);
        printf("PRASS 0 - to end sniff , PRASS 1 - TO continue\n");
        scanf("%d",&sniff);
        if(sniff==0) printf("sniffing end.\n");   
    }
    return 0;
}
