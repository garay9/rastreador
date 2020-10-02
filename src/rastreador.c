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

char *getname(int syscall);
char *getDescription(int syscall);
int continuar;
int ejecucionContinua;
int argNumber;
char **args;
char **bitacora;
char ***tablaAcumulada;
char ***tablaBitacora;
int sizeBitacora = 0;
int contadorTabla = 0;
int rows = 102400;
int cols = 4;
int tableSize = 0;
int cargarLinea = 0;
int terminado = 0;
int error = 0;

/*************************************************
 * *******************TRACER**********************
 *************************************************/

int procesoHijo(int argc, char **argv)
{
    //pasar argumentos de la entrada
    char *args[argc + 1];
    memcpy(args, argv, argc * sizeof(char *));
    args[argc] = NULL;
    //indicar trace
    ptrace(PTRACE_TRACEME);
    kill(getpid(), SIGSTOP);
    int estado = 0;
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
    while (esperarSyscall(hijo) == 0)
    {
        char id[255] = "";
        sprintf(id, "%i", contadorTabla);
        if (error)
        {
            strcpy(bitacora[0], id);
            strcpy(bitacora[1], "231");
            strcpy(bitacora[2], getname(231));
            strcpy(bitacora[3], getDescription(231));
            strcpy(tablaAcumulada[tableSize][0], bitacora[2]);
            strcpy(tablaAcumulada[tableSize][1], "1");
            strcpy(tablaBitacora[sizeBitacora][0], id);
            strcpy(tablaBitacora[sizeBitacora][1], "231");
            strcpy(tablaBitacora[sizeBitacora][2], getname(231));
            strcpy(tablaBitacora[sizeBitacora][3], getDescription(231));
            tableSize++;
            sizeBitacora++;
            cargarLinea = 1;
            contadorTabla++;
            continuar = 0;
            desplegarTablaAcumulada();
            addLineaBitacora();
            break;
        }
        syscall = ptrace(PTRACE_PEEKUSER, hijo, sizeof(long) * ORIG_RAX);
        int retval = ptrace(PTRACE_PEEKUSER, hijo, sizeof(long) * RAX);
        char codigo[255] = "";

        sprintf(codigo, "%i", syscall);
        strcpy(bitacora[0], id);
        strcpy(bitacora[1], codigo);
        strcpy(bitacora[2], getname(syscall));
        strcpy(bitacora[3], getDescription(syscall));
        for (int i = 0; i <= tableSize; i++)
        {
            if (i >= tableSize)
            {
                strcpy(tablaAcumulada[i][0], bitacora[2]);
                strcpy(tablaAcumulada[i][1], "1");
                tableSize++;
                if (ejecucionContinua)
                {
                    desplegarTablaAcumulada();
                }
                break;
            }
            else if (strcmp(tablaAcumulada[i][0], bitacora[2]) == 0)
            {
                int numero = atoi(tablaAcumulada[i][1]);
                numero++;
                //char frecuencia[255] = "";
                sprintf(tablaAcumulada[i][1], "%i", numero);
                if (ejecucionContinua)
                {
                    desplegarTablaAcumulada();
                }
                break;
            }
        }
        if (ejecucionContinua)
        {
            strcpy(tablaBitacora[sizeBitacora][0], id);
            strcpy(tablaBitacora[sizeBitacora][1], codigo);
            strcpy(tablaBitacora[sizeBitacora][2], getname(syscall));
            strcpy(tablaBitacora[sizeBitacora][3], getDescription(syscall));
            addLineaBitacora();
            sizeBitacora++;
        }
        cargarLinea = 1;
        contadorTabla++;
        if (syscall == 59 && retval != 0 && contadorTabla >= 8 && ejecucionContinua)
        {
            addLineaBitacora();
            error = 1;
        }

        esperarSyscall(hijo);
        continuar = 0;
    }
    terminado = 1;
    for (int j = 0; j < argNumber; j++)
    {
        free(args[j]);
    }
    free(args);
    return 0;
}

int inicializarTracer()
{
    bitacora = (char **)malloc(4 * sizeof(char *));
    for (int j = 0; j < 4; j++)
    {
        bitacora[j] = malloc(255 * sizeof(char));
    }
    tablaAcumulada = (char ***)malloc(rows * sizeof(char **));
    for (int i = 0; i < rows; i++)
    {
        tablaAcumulada[i] = (char **)malloc(2 * sizeof(char *));
        tablaAcumulada[i][0] = malloc(10 * sizeof(char));
        tablaAcumulada[i][1] = malloc(7 * sizeof(char));
    }
    tablaBitacora = (char ***)malloc(rows * 10 * sizeof(char **));
    for (int i = 0; i < rows * 10; i++)
    {
        tablaBitacora[i] = (char **)malloc(cols * sizeof(char *));
        tablaBitacora[i][0] = malloc(7 * sizeof(char));
        tablaBitacora[i][1] = malloc(4 * sizeof(char));
        tablaBitacora[i][2] = malloc(10 * sizeof(char));
        tablaBitacora[i][3] = malloc(180 * sizeof(char));
    }
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
}

void *hiloTracer(void *vargp)
{
    return inicializarTracer();

    pthread_exit(NULL);
}

void tracerNormal()
{
    inicializarTracer();
}