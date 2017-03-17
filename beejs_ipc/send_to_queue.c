#include <sys/msg.h>
#include <stddef.h>

int main()
{
    struct cheese_msgbuf {
        long mtype;
        char name[20];
    };
/* calculate the size of the data to send: */
    struct cheese_msgbuf mbuf;
    int size;
    size = sizeof mbuf.name;
/* Or, without a declared variable: */
    size = sizeof((struct cheese_msgbuf*) 0)->name;


//
    key_t key;
    int msqid;
    struct pirate_msgbuf pmb = {2, {"L'Olonais", 'S', 80, 10, 12035}};
    key = ftok("/home/beej/somefile", 'b');
    msqid = msgget(key, 0666 | IPC_CREAT);
/* stick him on the queue */
/* struct pirate_info is the sub-structure */
    msgsnd(msqid, &pmb, sizeof(struct pirate_info), 0);
}