#include <sys/msg.h>

int main()
{
    key_t key = ftok("/home/beej/somefile", 'b');
    int msqid = msgget(key, 0666 | IPC_CREAT);
}