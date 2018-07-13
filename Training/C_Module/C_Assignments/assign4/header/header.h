#include <stdio.h>
#include <stdlib.h>
#define MAX 256

int my_atoi(char*);
int endian();

typedef unsigned int u_int;
union sample
{
    int a:5;
    int b:10;
    int c:5;
    int d:21;
    int e;
};


struct frame1
{
    char clp : 1;
    char ph : 3;
    char gfc : 4;
    char vci[2];
    char hec : 8;
    char vpi : 8;

};

struct frame2
{
    u_int destination_port : 16;
    u_int source_port : 16;
    u_int sequence_number : 32;
    u_int acknoeledgement_number : 32;
    u_int window : 16;
    u_int code_bits : 6;
    u_int reserved : 6;
    u_int header_length : 4;
    u_int urgent : 16;
    u_int checksum : 16;
    u_int options :32;
    u_int data : 32;
};


struct frame3
{
    u_int version : 4;
    u_int header_length : 4;
    u_int service_type : 8;
    u_int total_length : 16;
    u_int identification : 16;
    u_int flags : 3;
    u_int fragment_offset : 12;
    u_int ttl : 8 ;
    u_int protocol : 8;
    u_int header_checksum : 16;
    u_int source_ip_addr : 32;
    u_int destination_ip_addr : 32;
    u_int options : 19;
    u_int padding : 13;
};

