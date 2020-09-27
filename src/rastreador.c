#include <sys/ptrace.h>
#include <sys/syscall.h>
#include <sys/reg.h>
#include <sys/reg.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include "names.c"

char *getname(int syscall);
char *getDescription(int syscall);
int continuar;
int ejecucionContinua;
int argNumber;
char** args;
void* prueba(void *vargp)
{
    continuar = 0;
    pid_t hijo = fork();
    if (hijo == 0)
    {
        return procesoHijo(argNumber, args);
    }
    else
    {
        return tracear(hijo);
    }
    pthread_exit(NULL);
}

int procesoHijo(int argc, char **argv)
{
    //pasar argumentos de la entrada
    char *args[argc + 1];
    memcpy(args, argv, argc * sizeof(char *));
    args[argc] = NULL;
    //indicar trace
    ptrace(PTRACE_TRACEME);
    kill(getpid(), SIGSTOP);
    return execvp(args[0], args);
}

int esperarSyscall(pid_t hijo)
{
    int estado;
    while (1)
    {
        if (continuar || ejecucionContinua)
        {
            ptrace(PTRACE_SYSCALL, hijo, 0, 0);
            waitpid(hijo, &estado, 0);
            if (WIFSTOPPED(estado) && WSTOPSIG(estado) & 0x80)
                return 0;
            if (WIFEXITED(estado))
                return 1;
        }
    }
}

int tracear(pid_t hijo)
{
    int estado, syscall;
    waitpid(hijo, &estado, 0);
    ptrace(PTRACE_SETOPTIONS, hijo, 0, PTRACE_O_TRACESYSGOOD);
    fprintf(stderr, "%d\n%d\n", ejecucionContinua, continuar);
    while (esperarSyscall(hijo) == 0)
    {
        syscall = ptrace(PTRACE_PEEKUSER, hijo, sizeof(long) * ORIG_RAX);
        fprintf(stderr, "%s\n descripción %s\n", getname(syscall), getDescription(syscall));
        continuar = 0;
    }
    return 0;
}