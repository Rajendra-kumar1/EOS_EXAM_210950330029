/*1. Open the file /usr/share/dictionary.txt in process P1 and send the strings starting with letter 'm' to process P2 using message queues. In process P2 find and print the length of string.*/

#include<stdio.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<mqueue.h>

mqd_t mq;
struct mq_attr mq_attr;
char buff[16];
int msg_prio;

int main(int argc, char const *argv[])
{
    mq_attr.mq_flags =0;
    mq_attr.mq_maxmsg =16;
    mq_attr.mq_msgsize =2;
    mq_attr.mq_curmsgs =0;

    mq = mq_open("m", O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR, &mq_attr);

    mq_receive(mq, buff, 16, &msg_prio);             //receive message "m"
    printf("Receied msg: %s\n msg prio: %d\n", buff, msg_prio);

    mq_close(mq);
    return 0;
}
