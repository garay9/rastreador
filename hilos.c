
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> //Header file for sleep(). man 3 sleep for details.
#include <pthread.h>

// A normal C function that is executed as a thread
// when its name is specified in pthread_create()
int numero;
void *myThreadFun(void *vargp)
{
    printf("%d\n", numero);
    sleep(3);
    printf("%d\n", numero);
    return NULL;
}

int main()
{
    numero = 0;
    pthread_t thread_id;
    pthread_create(&thread_id, NULL, myThreadFun, NULL);
    sleep(1);
    numero = 42;
    pthread_join(thread_id, NULL);
    printf("After Thread\n");
    exit(0);
}
