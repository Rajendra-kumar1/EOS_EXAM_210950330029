/*1. Open the file /usr/share/dictionary.txt in process P1 and send the strings starting with letter 'm' to process P2 using message queues. In process P2 find and print the length of string.*/

#include<stdio.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<mqueue.h>

mqd_t mq;
struct mq_attr mq_attr;

int main(int argc, char const *argv[])
{
    mq_attr.mq_flags =0;
    mq_attr.mq_maxmsg =1;
    mq_attr.mq_msgsize =2;
    mq_attr.mq_curmsgs =0;

    mq = mq_open("m", O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR, &mq_attr);

    mq_send(mq, "m\n",2, 1);    //message queues give string "m"

    mq_close(mq);
    return 0;
}
