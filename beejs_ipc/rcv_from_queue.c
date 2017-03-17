#include <sys/msg.h>
#include <stddef.h>

int main()
{
    key_t key;
    int msqid;
    struct pirate_msgbuf pmb; /* where L'Olonais is to be kept */
    key = ftok("/home/beej/somefile", 'b');
    msqid = msgget(key, 0666 | IPC_CREAT);
    /* get him off the queue! */
    msgrcv(msqid, &pmb, sizeof(struct pirate_info), 2, 0);
}