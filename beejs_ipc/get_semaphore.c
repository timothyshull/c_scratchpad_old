#include <sys/ipc.h>
#include <sys/sem.h>

int main()
{
    key_t key;
    int semid;
    key = ftok("/home/beej/somefile", 'E');
    semid = semget(key, 10, 0666 | IPC_CREAT);
}