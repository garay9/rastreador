#include <sys/syscall.h>

char *getname(int syscall)
{
    switch (syscall)
    {
    case __NR_read:
        return ("read");

    case __NR_write:
        return ("write");

    case __NR_open:
        return ("open");

    case __NR_close:
        return ("close");

    case __NR_stat:
        return ("stat");

    case __NR_fstat:
        return ("fstat");

    case __NR_lstat:
        return ("lstat");

    case __NR_poll:
        return ("poll");

    case __NR_lseek:
        return ("lseek");

    case __NR_mmap:
        return ("mmap");

    case __NR_mprotect:
        return ("mprotect");

    case __NR_munmap:
        return ("munmap");

    case __NR_brk:
        return ("brk");

    case __NR_rt_sigaction:
        return ("rt_sigaction");

    case __NR_rt_sigprocmask:
        return ("rt_sigprocmask");

    case __NR_rt_sigreturn:
        return ("rt_sigreturn");

    case __NR_ioctl:
        return ("ioctl");

    case __NR_pread64:
        return ("pread64");

    case __NR_pwrite64:
        return ("pwrite64");

    case __NR_readv:
        return ("readv");

    case __NR_writev:
        return ("writev");

    case __NR_access:
        return ("access");

    case __NR_pipe:
        return ("pipe");

    case __NR_select:
        return ("select");

    case __NR_sched_yield:
        return ("sched_yield");

    case __NR_mremap:
        return ("mremap");

    case __NR_msync:
        return ("msync");

    case __NR_mincore:
        return ("mincore");

    case __NR_madvise:
        return ("madvise");

    case __NR_shmget:
        return ("shmget");

    case __NR_shmat:
        return ("shmat");

    case __NR_shmctl:
        return ("shmctl");

    case __NR_dup:
        return ("dup");

    case __NR_dup2:
        return ("dup2");

    case __NR_pause:
        return ("pause");

    case __NR_nanosleep:
        return ("nanosleep");

    case __NR_getitimer:
        return ("getitimer");

    case __NR_alarm:
        return ("alarm");

    case __NR_setitimer:
        return ("setitimer");

    case __NR_getpid:
        return ("getpid");

    case __NR_sendfile:
        return ("sendfile");

    case __NR_socket:
        return ("socket");

    case __NR_connect:
        return ("connect");

    case __NR_accept:
        return ("accept");

    case __NR_sendto:
        return ("sendto");

    case __NR_recvfrom:
        return ("recvfrom");

    case __NR_sendmsg:
        return ("sendmsg");

    case __NR_recvmsg:
        return ("recvmsg");

    case __NR_shutdown:
        return ("shutdown");

    case __NR_bind:
        return ("bind");

    case __NR_listen:
        return ("listen");

    case __NR_getsockname:
        return ("getsockname");

    case __NR_getpeername:
        return ("getpeername");

    case __NR_socketpair:
        return ("socketpair");

    case __NR_setsockopt:
        return ("setsockopt");

    case __NR_getsockopt:
        return ("getsockopt");

    case __NR_clone:
        return ("clone");

    case __NR_fork:
        return ("fork");

    case __NR_vfork:
        return ("vfork");

    case __NR_execve:
        return ("execve");

    case __NR_exit:
        return ("exit");

    case __NR_wait4:
        return ("wait4");

    case __NR_kill:
        return ("kill");

    case __NR_uname:
        return ("uname");

    case __NR_semget:
        return ("semget");

    case __NR_semop:
        return ("semop");

    case __NR_semctl:
        return ("semctl");

    case __NR_shmdt:
        return ("shmdt");

    case __NR_msgget:
        return ("msgget");

    case __NR_msgsnd:
        return ("msgsnd");

    case __NR_msgrcv:
        return ("msgrcv");

    case __NR_msgctl:
        return ("msgctl");

    case __NR_fcntl:
        return ("fcntl");

    case __NR_flock:
        return ("flock");

    case __NR_fsync:
        return ("fsync");

    case __NR_fdatasync:
        return ("fdatasync");

    case __NR_truncate:
        return ("truncate");

    case __NR_ftruncate:
        return ("ftruncate");

    case __NR_getdents:
        return ("getdents");

    case __NR_getcwd:
        return ("getcwd");

    case __NR_chdir:
        return ("chdir");

    case __NR_fchdir:
        return ("fchdir");

    case __NR_rename:
        return ("rename");

    case __NR_mkdir:
        return ("mkdir");

    case __NR_rmdir:
        return ("rmdir");

    case __NR_creat:
        return ("creat");

    case __NR_link:
        return ("link");

    case __NR_unlink:
        return ("unlink");

    case __NR_symlink:
        return ("symlink");

    case __NR_readlink:
        return ("readlink");

    case __NR_chmod:
        return ("chmod");

    case __NR_fchmod:
        return ("fchmod");

    case __NR_chown:
        return ("chown");

    case __NR_fchown:
        return ("fchown");

    case __NR_lchown:
        return ("lchown");

    case __NR_umask:
        return ("umask");

    case __NR_gettimeofday:
        return ("gettimeofday");

    case __NR_getrlimit:
        return ("getrlimit");

    case __NR_getrusage:
        return ("getrusage");

    case __NR_sysinfo:
        return ("sysinfo");

    case __NR_times:
        return ("times");

    case __NR_ptrace:
        return ("ptrace");

    case __NR_getuid:
        return ("getuid");

    case __NR_syslog:
        return ("syslog");

    case __NR_getgid:
        return ("getgid");

    case __NR_setuid:
        return ("setuid");

    case __NR_setgid:
        return ("setgid");

    case __NR_geteuid:
        return ("geteuid");

    case __NR_getegid:
        return ("getegid");

    case __NR_setpgid:
        return ("setpgid");

    case __NR_getppid:
        return ("getppid");

    case __NR_getpgrp:
        return ("getpgrp");

    case __NR_setsid:
        return ("setsid");

    case __NR_setreuid:
        return ("setreuid");

    case __NR_setregid:
        return ("setregid");

    case __NR_getgroups:
        return ("getgroups");

    case __NR_setgroups:
        return ("setgroups");

    case __NR_setresuid:
        return ("setresuid");

    case __NR_getresuid:
        return ("getresuid");

    case __NR_setresgid:
        return ("setresgid");

    case __NR_getresgid:
        return ("getresgid");

    case __NR_getpgid:
        return ("getpgid");

    case __NR_setfsuid:
        return ("setfsuid");

    case __NR_setfsgid:
        return ("setfsgid");

    case __NR_getsid:
        return ("getsid");

    case __NR_capget:
        return ("capget");

    case __NR_capset:
        return ("capset");

    case __NR_rt_sigpending:
        return ("rt_sigpending");

    case __NR_rt_sigtimedwait:
        return ("rt_sigtimedwait");

    case __NR_rt_sigqueueinfo:
        return ("rt_sigqueueinfo");

    case __NR_rt_sigsuspend:
        return ("rt_sigsuspend");

    case __NR_sigaltstack:
        return ("sigaltstack");

    case __NR_utime:
        return ("utime");

    case __NR_mknod:
        return ("mknod");

    case __NR_uselib:
        return ("uselib");

    case __NR_personality:
        return ("personality");

    case __NR_ustat:
        return ("ustat");

    case __NR_statfs:
        return ("statfs");

    case __NR_fstatfs:
        return ("fstatfs");

    case __NR_sysfs:
        return ("sysfs");

    case __NR_getpriority:
        return ("getpriority");
    case __NR_setpriority:
        return ("setpriority");
    case __NR_sched_setparam:
        return ("sched_setparam");
    case __NR_sched_getparam:
        return ("sched_getparam");
    case __NR_sched_setscheduler:
        return ("sched_setscheduler");
    case __NR_sched_getscheduler:
        return ("sched_getscheduler");
    case __NR_sched_get_priority_max:
        return ("sched_get_priority_max");
    case __NR_sched_get_priority_min:
        return ("sched_get_priority_min");
    case __NR_sched_rr_get_interval:
        return ("sched_rr_get_interval");
    case __NR_mlock:
        return ("mlock");
    case __NR_munlock:
        return ("munlock");
    case __NR_mlockall:
        return ("mlockall");
    case __NR_munlockall:
        return ("munlockall");
    case __NR_vhangup:
        return ("vhangup");
    case __NR_modify_ldt:
        return ("modify_ldt");
    case __NR_pivot_root:
        return ("pivot_root");
    case __NR__sysctl:
        return ("_NR_sysctl");
    case __NR_prctl:
        return ("prctl");
    case __NR_arch_prctl:
        return ("arch_prctl");
    case __NR_adjtimex:
        return ("adjtimex");
    case __NR_setrlimit:
        return ("setrlimit");
    case __NR_chroot:
        return ("chroot");
    case __NR_sync:
        return ("sync");
    case __NR_acct:
        return ("acct");
    case __NR_settimeofday:
        return ("settimeofday");
    case __NR_mount:
        return ("mount");
    case __NR_umount2:
        return ("umount2");
    case __NR_swapon:
        return ("swapon");
    case __NR_swapoff:
        return ("swapoff");
    case __NR_reboot:
        return ("reboot");
    case __NR_sethostname:
        return ("sethostname");
    case __NR_setdomainname:
        return ("setdomainname");
    case __NR_iopl:
        return ("iopl");
    case __NR_ioperm:
        return ("ioperm");
    case __NR_create_module:
        return ("create_module");
    case __NR_init_module:
        return ("init_module");
    case __NR_delete_module:
        return ("delete_module");
    case __NR_get_kernel_syms:
        return ("get_kernel_syms");
    case __NR_query_module:
        return ("query_module");
    case __NR_quotactl:
        return ("quotactl");
    case __NR_nfsservctl:
        return ("nfsservctl");
    case __NR_getpmsg:
        return ("getpmsg");
    case __NR_putpmsg:
        return ("putpmsg");
    case __NR_afs_syscall:
        return ("afs_syscall");
    case __NR_tuxcall:
        return ("tuxcall");
    case __NR_security:
        return ("security");
    case __NR_gettid:
        return ("gettid");
    case __NR_readahead:
        return ("readahead");
    case __NR_setxattr:
        return ("setxattr");
    case __NR_lsetxattr:
        return ("lsetxattr");
    case __NR_fsetxattr:
        return ("fsetxattr");
    case __NR_getxattr:
        return ("getxattr");
    case __NR_lgetxattr:
        return ("lgetxattr");
    case __NR_fgetxattr:
        return ("fgetxattr");
    case __NR_listxattr:
        return ("listxattr");
    case __NR_llistxattr:
        return ("llistxattr");
    case __NR_flistxattr:
        return ("flistxattr");
    case __NR_removexattr:
        return ("removexattr");
    case __NR_lremovexattr:
        return ("lremovexattr");
    case __NR_fremovexattr:
        return ("fremovexattr");
    case __NR_tkill:
        return ("");
    case __NR_time:
        return ("tkill");
    case __NR_futex:
        return ("futex");
    case __NR_sched_setaffinity:
        return ("sched_setaffinity");
    case __NR_sched_getaffinity:
        return ("sched_getaffinity");
    case __NR_set_thread_area:
        return ("set_thread_area");
    case __NR_io_setup:
        return ("io_setup");
    case __NR_io_destroy:
        return ("io_destroy");
    case __NR_io_getevents:
        return ("io_getevents");
    case __NR_io_submit:
        return ("io_submit");
    case __NR_io_cancel:
        return ("io_cancel");
    case __NR_get_thread_area:
        return ("get_thread_area");
    case __NR_lookup_dcookie:
        return ("lookup_dcookie");
    case __NR_epoll_create:
        return ("epoll_create");
    case __NR_epoll_ctl_old:
        return ("epoll_ctl_old");
    case __NR_epoll_wait_old:
        return ("epoll_wait_old");
    case __NR_remap_file_pages:
        return ("remap_file_pages");
    case __NR_getdents64:
        return ("getdents64");
    case __NR_set_tid_address:
        return ("set_tid_address");
    case __NR_restart_syscall:
        return ("restart_syscall");
    case __NR_semtimedop:
        return ("semtimedop");
    case __NR_fadvise64:
        return ("fadvise64");
    case __NR_timer_create:
        return ("timer_create");
    case __NR_timer_settime:
        return ("timer_settime");
    case __NR_timer_gettime:
        return ("timer_gettime");
    case __NR_timer_getoverrun:
        return ("timer_getoverrun");
    case __NR_timer_delete:
        return ("timer_delete");
    case __NR_clock_settime:
        return ("clock_settime");
    case __NR_clock_gettime:
        return ("clock_gettime");
    case __NR_clock_getres:
        return ("clock_getres");
    case __NR_clock_nanosleep:
        return ("clock_nanosleep");
    case __NR_exit_group:
        return ("exit_group");

    case __NR_epoll_wait:
        return ("epoll_wait");

    case __NR_epoll_ctl:
        return ("epoll_ctl");

    case __NR_tgkill:
        return ("tgkill");

    case __NR_utimes:
        return ("utimes");

    case __NR_vserver:
        return ("vserver");

    case __NR_mbind:
        return ("mbind");

    case __NR_set_mempolicy:
        return ("set_mempolicy");

    case __NR_get_mempolicy:
        return ("get_mempolicy");

    case __NR_mq_open:
        return ("mq_open");

    case __NR_mq_unlink:
        return ("mq_unlink");

    case __NR_mq_timedsend:
        return ("mq_timedsend");

    case __NR_mq_timedreceive:
        return ("mq_timedreceive");

    case __NR_mq_notify:
        return ("mq_notify");

    case __NR_mq_getsetattr:
        return ("mq_getsetattr");

    case __NR_kexec_load:
        return ("kexec_load");

    case __NR_waitid:
        return ("waitid");

    case __NR_add_key:
        return ("add_key");

    case __NR_request_key:
        return ("request_key");

    case __NR_keyctl:
        return ("keyctl");

    case __NR_ioprio_set:
        return ("ioprio_set");

    case __NR_ioprio_get:
        return ("ioprio_get");

    case __NR_inotify_init:
        return ("inotify_init");

    case __NR_inotify_add_watch:
        return ("inotify_add_watch");

    case __NR_inotify_rm_watch:
        return ("inotify_rm_watch");

    case __NR_migrate_pages:
        return ("migrate_pages");

    case __NR_openat:
        return ("openat");

    case __NR_mkdirat:
        return ("mkdirat");

    case __NR_mknodat:
        return ("mknodat");

    case __NR_fchownat:
        return ("fchownat");

    case __NR_futimesat:
        return ("futimesat");

    case __NR_newfstatat:
        return ("newfstatat");

    case __NR_unlinkat:
        return ("unlinkat");

    case __NR_renameat:
        return ("renameat");

    case __NR_linkat:
        return ("linkat");

    case __NR_symlinkat:
        return ("symlinkat");

    case __NR_readlinkat:
        return ("readlinkat");

    case __NR_fchmodat:
        return ("fchmodat");

    case __NR_faccessat:
        return ("faccessat");

    case __NR_pselect6:
        return ("pselect6");

    case __NR_ppoll:
        return ("ppoll");

    case __NR_unshare:
        return ("unshare");

    case __NR_set_robust_list:
        return ("set_robust_list");

    case __NR_get_robust_list:
        return ("get_robust_list");

    case __NR_splice:
        return ("splice");

    case __NR_tee:
        return ("tee");

    case __NR_sync_file_range:
        return ("sync_file_range");

    case __NR_vmsplice:
        return ("vmsplice");

    case __NR_move_pages:
        return ("move_pages");

    case __NR_utimensat:
        return ("utimensat");

    case __NR_epoll_pwait:
        return ("epoll_pwait");

    case __NR_signalfd:
        return ("signalfd");

    case __NR_timerfd_create:
        return ("timerfd_create");

    case __NR_eventfd:
        return ("eventfd");

    case __NR_fallocate:
        return ("fallocate");

    case __NR_timerfd_settime:
        return ("timerfd_settime");

    case __NR_timerfd_gettime:
        return ("timerfd_gettime");

    case __NR_accept4:
        return ("accept4");

    case __NR_signalfd4:
        return ("signalfd4");

    case __NR_eventfd2:
        return ("eventfd2");

    case __NR_epoll_create1:
        return ("epoll_create1");

    case __NR_dup3:
        return ("dup3");

    case __NR_pipe2:
        return ("pipe2");

    case __NR_inotify_init1:
        return ("inotify_init1");

    case __NR_preadv:
        return ("preadv");

    case __NR_pwritev:
        return ("pwritev");

    case __NR_rt_tgsigqueueinfo:
        return ("rt_tgsigqueueinfo");

    case __NR_perf_event_open:
        return ("perf_event_open");

    case __NR_recvmmsg:
        return ("recvmmsg");

    case __NR_fanotify_init:
        return ("fanotify_init");

    case __NR_fanotify_mark:
        return ("fanotify_mark");

    case __NR_prlimit64:
        return ("prlimit64");

    case __NR_name_to_handle_at:
        return ("name_to_handle_at");

    case __NR_open_by_handle_at:
        return ("open_by_handle_at");

    case __NR_clock_adjtime:
        return ("clock_adjtime");

    case __NR_syncfs:
        return ("syncfs");

    case __NR_sendmmsg:
        return ("sendmmsg");

    case __NR_setns:
        return ("setns");

    case __NR_getcpu:
        return ("getcpu");

    case __NR_process_vm_readv:
        return ("process_vm_readv");

    case __NR_process_vm_writev:
        return ("process_vm_writev");

    case __NR_kcmp:
        return ("kcmp");

    case __NR_finit_module:
        return ("finit_module");

    case __NR_sched_setattr:
        return ("sched_setattr");

    case __NR_sched_getattr:
        return ("sched_getattr");

    case __NR_renameat2:
        return ("renameat2");

    case __NR_seccomp:
        return ("seccomp");

    case __NR_getrandom:
        return ("getrandom");

    case __NR_memfd_create:
        return ("memfd_create");

    case __NR_kexec_file_load:
        return ("kexec_file_load");

    case __NR_bpf:
        return ("bpf");

    case __NR_execveat:
        return ("execveat");

    case __NR_userfaultfd:
        return ("userfaultfd");

    case __NR_membarrier:
        return ("membarrier");

    case __NR_mlock2:
        return ("mlock2");

    case __NR_copy_file_range:
        return ("copy_file_range");

    case __NR_preadv2:
        return ("preadv2");

    case __NR_pwritev2:
        return ("pwritev2");

    case __NR_pkey_mprotect:
        return ("pkey_mprotect");

    case __NR_pkey_alloc:
        return ("pkey_alloc");

    case __NR_pkey_free:
        return ("pkey_free");

    case __NR_statx:
        return ("statx");

    case __NR_io_pgetevents:
        return ("io_pgetevents");

    case __NR_rseq:
        return ("rseq");

    case __NR_pidfd_send_signal:
        return ("pidfd_send_signal");

    case __NR_io_uring_setup:
        return ("io_uring_setup");

    case __NR_io_uring_enter:
        return ("io_uring_enter");

    case __NR_io_uring_register:
        return ("io_uring_register");

    case __NR_open_tree:
        return ("open_tree");

    case __NR_move_mount:
        return ("move_mount");

    case __NR_fsopen:
        return ("fsopen");

    case __NR_fsconfig:
        return ("fsconfig");

    case __NR_fsmount:
        return ("fsmount");

    case __NR_fspick:
        return ("fspick");

    case __NR_pidfd_open:
        return ("pidfd_open");

    case __NR_clone3:
        return ("clone3");

    case 437: //__NR_openat2
        return ("openat2");

    case 438: //__NR_pidfd_getfd
        return ("pidfd_getfd");

    default:
        return ("NO SE WE");
    }
}

char *getDescription(int syscall)
{
    switch (syscall){
        case __NR_setgid:
        return ("Establece el ID del grupo efectivo del proceso de llamada.");

    case __NR_geteuid:
        return ("Retorna el ID de usuario real del proceso de llamada.");

    case __NR_getegid:
        return ("Retorna el ID del grupo real del proceso de llamada.");

    case __NR_setpgid:
        return ("Establece el ID del grupo de procesos es'especificado por PID a PGID.");

    case __NR_getppid:
        return ("Retorna el ID del proceso del al que se llamó.");

    case __NR_getpgrp:
        return ("Establece el PGID del proceso especificado por pid a pgid");

    case __NR_setsid:
        return ("Crea una nueva sesión si la llamada al proceso no es un grupo líder de proceso.");

    case __NR_setreuid:
        return ("Establece los ID reales y efectivos del proceso de llamada.");

    case __NR_setregid:
        return ("Establece los ID reales y efectivos del proceso de llamada.");

    case __NR_getgroups:
        return ("Retorna los ID de grupos suplementarios del proceso de llamada en lista.");

    case __NR_setgroups:
        return ("Establece los ID de grupos suplementarios del proceso de llamada en lista.");

    case __NR_setresuid:
        return ("Establece el ID de usuario real, el de usuario efectivo y el set-user-ID guardado del proceso de llamada.");

    case __NR_getresuid:
        return ("Retorna el ID de usuario real, el de usuario efectivo y el de guardado set-user-ID del proceso de llamada.");

    case __NR_setresgid:
        return ("Establece el ID de usuario real, el de usuario efectivo y el set-user-ID guardado del proceso de llamada.");

    case __NR_getresgid:
        return ("Retorna el UID real, el efectivo y el set-user-ID guardado del proceso de llamada.");

    case __NR_getpgid:
        return ("Establece el PGID del proceso especificado por pid a pgid.");

    case __NR_setfsuid:
        return ("Establece la identidad del usuario usada para la verificación del sistema de archivos.");

    case __NR_setfsgid:
        return ("Establece la identidad del usuario usada para la verificación del sistema de archivos.");

    case __NR_getsid:
        return ("Retorna el ID de la sesión del proceso de llamada.");

    case __NR_capget:
        return ("Retorna las capacidades de un proceso.");

    case __NR_capset:
        return ("Establece las capacidades de un proceso.");

    case __NR_rt_sigpending:
        return ("Retorna el conjunto de señales que están pendientes de entrega a un hilo de llamada.");

    case __NR_rt_sigtimedwait:
        return ("Rmueve le señal desde el conjunto de señales pendientes y retorna el numero de la señal como si fuese el resultad de una función.");

    case __NR_rt_sigqueueinfo:
        return ("Envía la señal sig al grupo de procesos con el ID tgid.");

    case __NR_rt_sigsuspend:
        return ("Reemplaza temporalmente la máscara de la señal del hilo llamada con la máscara dada por mask.");

    case __NR_sigaltstack:
        return ("Permite a un proceso definir una pila de señales alternativas y/o  recuperar el estado de una pila existente.");

    case __NR_utime:
        return ("Cambia los tiempos de acceso y modificación del inode especificado por nombre del archivo, campos actime y modtime. ");

    case __NR_mknod:
        return ("Crea un nodo de sistema de archivos llamado pathname, con atributos especificados por mode y dev.");

    case __NR_uselib:
        return ("Carga una biblioteca compartida para ser usada por el proceso de llamada.");

    case __NR_personality:
        return ("Establece el dominio del proceso de ejecución.");

    case __NR_ustat:
        return ("Retorna información acerca del sistema de archivos montado.");

    case __NR_statfs:
        return ("Retorna información acerca del sistema de archivos montado.");

    case __NR_fstatfs:
        return ("Retorna información acerca del sistema de archivos montado.");

    case __NR_sysfs:
        return ("Retorna información acerca de los tipos de sistema de archivos actualmente presentes en el Kernel.");

    case __NR_getpriority:
        return ("Retorna la prioridad de un programa.");
    case __NR_setpriority:

        return ("Establece la prioridad de un programa.");

    case __NR_sched_setparam:
        return ("Establece los parámetros programados asociados con la política de programación para el hilo cuyo ID está especificado en PID");

    case __NR_sched_getparam:
        return ("Retorna los parámetros programados asociados con la política de programación para el hilo cuyo ID está especificado en PID");

    case __NR_sched_setscheduler:
        return ("Establece las dos políticas de programación y parámetros para el hilo cuyo ID es especificado en pid");

    case __NR_sched_getscheduler:
        return ("Retorna las dos políticas de programación y parámetros para el hilo cuyo ID es especificado en pid");

    case __NR_sched_get_priority_max:
        return ("Retorna el valor de prioridad máximo que puede ser usado con el algoritmo de programación identificado por policy.");

    case __NR_sched_get_priority_min:
        return ("Retorna el valor de prioridad mínimo que puede ser usado con el algoritmo de programación identificado por policy.");

    case __NR_sched_rr_get_interval:
        return ("Escribe en timespec una estructura apuntando por tp.");

    case __NR_mlock:
        return ("Bloquea páginas en el rango de la dirección empezando en addr y continuando hasta len bytes.");

    case __NR_munlock:
        return ("Ejecuta operaciones de conversión, desbloqueando parte o todo el espacio de la dirección virtual de llamada del proceso.");

    case __NR_mlockall:
        return ("Bloquea todas las páginas mapeadas en el espacio de dirección de la llamada del proceso.");

    case __NR_munlockall:
        return ("Desbloquea todas las páginas mapeadas en el espacio de dirección de la llamada del proceso.");

    case __NR_vhangup:
        return ("Simula un bloqueo en el terminal actual.");

    case __NR_modify_ldt:
        return ("Lee o escribe la tabla de descriptores actual para un proceso.");

    case __NR_pivot_root:
        return ("Cambia el montaje de la raíz en el namespace de la llamada del proceso.");

    case __NR__sysctl:
        return ("Lee y/o escribe los parámetros del Kernel.");

    case __NR_prctl:
        return ("Manipula varios aspectos del comportamiento de la llamada al hilo o proceso.");

    case __NR_arch_prctl:
        return ("Establece el estado de un proceso o hilo de arquitectura específico ");

    case __NR_adjtimex:
        return ("Ajusta el reloj del Kernel.");

    case __NR_setrlimit:
        return ("Establece los limites de recursos.");

    case __NR_chroot:
        return ("Cambia el directorio raíz de la llamada del proceso al especificado en el path.");

    case __NR_sync:
        return ("Hace todas las modificaciones pendientes del sistema de archivos y los almacena en chaché, en otros sistemas de archivo.");

    case __NR_acct:
        return ("Activa o desactiva procesos contables.");

    case __NR_settimeofday:
        return ("Retorna el tiempo de acuerdo a la zona horaria.");

    case __NR_mount:
        return ("Adjunta el systema de archivos especificado por source a la locación especificada por el pathname en target.");

    case __NR_umount2:
        return ("Remueve el systema de archivos adjuntos montados en Target.");

    case __NR_swapon:
        return ("Establece el are de intercambio del archivo o bloque especificado por path.");

    case __NR_swapoff:
        return ("Detiene el intercambio del archivo o bloque especificado por el path.");

    case __NR_reboot:
        return ("Reinicia el sistema o activa/desactiva el el reinicio de pulsación de tecla.");

    case __NR_sethostname:
        return ("Establece el hostname para el valor daro en el array de carácteres name.");

    case __NR_setdomainname:
        return ("Establece el nombre del dominio o cambia el nombre del dominio NIS en el host del sistema.");

    case __NR_iopl:
        return ("Cambia el nivel de privilegio de I/O de la llamada al hilo.");

    case __NR_ioperm:
        return ("Establece el permiso de bits del puerto de acceso de la llamada al hilo por num bits, empezando desde la dirección del puesto from.");

    case __NR_create_module:
        return ("Crea un módulo de entrada cargable.");

    case __NR_init_module:
        return ("Inicializa el módulo de entrada cargable.");

    case __NR_delete_module:
        return ("Elimina el módulo de entrada cargable.");

    case __NR_get_kernel_syms:
        return ("Devuelve el kernel exportado y los symbolos del módulo.");

    case __NR_query_module:
        return ("Consulta al Kernel por varios bits pertenecientes al mod.");

    case __NR_quotactl:
        return ("Manipula las cuotas de disco.");

    case __NR_nfsservctl:
        return ("Interfaz de llamada al sistema al nfs demon del Kernel.");

    case __NR_getpmsg:
        return ("Syscall  sin implementar :(");

    case __NR_putpmsg:
        return ("Syscall  sin implementar :(");

    case __NR_afs_syscall:
        return ("Syscall  sin implementar :(");

    case __NR_tuxcall:
        return ("Syscall  sin implementar :(");

    case __NR_security:
        return ("Syscall  sin implementar :(");

    case __NR_gettid:
        return ("Retorna el identificador de un hilo.");

    case __NR_readahead:
        return ("Inicializa un archivo readhead en una página del caché.");

    case __NR_setxattr:
        return ("Establece el valor de un atributo extendido.");

    case __NR_lsetxattr:
        return ("Establece el valor de un atributo extendido.");

    case __NR_fsetxattr:
        return ("Establece el valor de un atributo extendido.");

    case __NR_getxattr:
        return ("Retorna el valor de un atributo extendido.");

    case __NR_lgetxattr:
        return ("Retorna el valor de un atributo extendido.");

    case __NR_fgetxattr:
        return ("Retorna el valor de un atributo extendido.");

    case __NR_listxattr:
        return ("Retorna la lista de los nombres de atributos extendidos con el path dado.");

    case __NR_llistxattr:
        return ("Retorna la lista de los nombres de atributos extendidos con el path dado. Si es un enlace simbólico, devuelve los atributos asociados con dicho enlace.");

    case __NR_flistxattr:
        return ("Retorna la lista de los nombres de atributos extendidos con el path dado.");

    case __NR_removexattr:
        return ("Remueve el indentificadores de atributo extendido por name y asociados con el path dado en el sistema de archivos.");

    case __NR_lremovexattr:
        return ("Remueve el indentificadores de atributo extendido por name y asociados con el path dado en el sistema de archivos.");

    case __NR_fremovexattr:
        return ("Remueve el indentificadores de atributo extendido por name y asociados con el path dado en el sistema de archivos.");

    case __NR_tkill:
        return ("Envía la señal sig al hilo usando su ID tid.");

    case __NR_time:
        return ("Retorna el tiempo como el numero de segundos dede el Epoch.");

    case __NR_futex:
        return ("Provee un método de espera hasta cierta condición se haga verdadera.");

    case __NR_sched_setaffinity:
        return ("Establece la máscara de afinidad del CPU del hilo, cuyo ID es pid al valor especificado por mask.");

    case __NR_sched_getaffinity:
        return ("Escribe la máscara de afinidad del Hilo con el ID pid.");

    case __NR_set_thread_area:
        return ("Establece una entrada TLS en el GDT.");

    case __NR_io_setup:
        return ("Crea un contexto asincrónico de I/O, sostenible por las operaciones del procesamiento de concurrencia nr_events.");

    case __NR_io_destroy:
        return ("Destruye un contexto I/0 asincrónico.");

    case __NR_io_getevents:
        return ("Lee un  evento asincrónico de tipo I/O desde la cola de finalización.");

    case __NR_io_submit:
        return ("Envía bloques I/O asincrónicos para procesar.");

    case __NR_io_cancel:
        return ("Cancela una operación I/O asincrónica en espera.");

    case __NR_get_thread_area:
        return ("Lee la entrada GDT indicada por u_info->entry_number.");

    case __NR_lookup_dcookie:
        return ("Retorna el path de entrada del directorio.");

    case __NR_epoll_create:
        return ("Crea una nueva instancia epoll(7)");

    case __NR_epoll_ctl_old:
        return ("Interfaz de control para un descriptor de archivo epoll.");

    case __NR_epoll_wait_old:
        return ("Espera por eventos en la instancia epoll(7) referida por el descriptor de archivo epfd.");

    case __NR_remap_file_pages:
        return ("Crea un mapeo no lineal, donde las páginas de los archivos son mapeados de forma no secuancial en memoria.");

    case __NR_getdents64:
        return ("Lee varias estructuras linux_dirent desde el directorio referido por el descriptor abierto de archivos.");

    case __NR_set_tid_address:
        return ("Establece un punto señalando al ID del hilo.");

    case __NR_restart_syscall:
        return ("Reinicia una llamada al sistema después de la interrupción por una señal para detenerse.");

    case __NR_semtimedop:
        return ("semtimedop");

    case __NR_fadvise64:
        return ("Predeclara el patrón de acceso para el registro de archivos.");

    case __NR_timer_create:
        return ("Crea un nuevo temporizador de intervalo de preproceso.");

    case __NR_timer_settime:
        return ("Arma o desarma el temporizador identificado por timerid.");

    case __NR_timer_gettime:
        return ("Obtiene el temporizador identificado por timerid.");

    case __NR_timer_getoverrun:
        return ("Retorna el overrun count para el temporizador referido por timerid.");

    case __NR_timer_delete:
        return ("Elimina el temporizador cuyo ID es dado en timerid.");

    case __NR_clock_settime:
        return ("Encuentra a resolución del reloj clockid especificado.");

    case __NR_clock_gettime:
        return ("Devuelve el tiempo del reloj especificado usando clockid.");

    case __NR_clock_getres:
        return ("Encuentra a resolución del reloj clockid especificado.");

    case __NR_clock_nanosleep:
        return ("Permite la pausa de un hilo de llamada por un intervalo especificado en nanosegundos.");

    case __NR_exit_group:
        return ("Detiene todos los hilos en un proceso.");

    case __NR_epoll_wait:
        return ("Espera por eventos en la instancia epoll(7) referida por el descriptor de archivo epfd.");

    case __NR_epoll_ctl:
        return ("Interfaz de control para un descriptor de archivo epoll.");

    case __NR_tgkill:
        return ("Envía una señal a un hilo.");

    case __NR_utimes:
        return ("Cambia el archivo y tiempos de acceso y modificación.");

    case __NR_vserver:
        return ("Syscall  sin implementar :(");

    case __NR_mbind:
        return ("Establece una política de memoria a un rango de memoria.");

    case __NR_set_mempolicy:
        return ("Establece una política de memoria NUMA por defecto para un hilo y sus hijos.");

    case __NR_get_mempolicy:
        return ("Devuelve una política de memoria NUMA para un hilo.");

    case __NR_mq_open:
        return ("Crea una cola de tipo mensaje POSIX o abre una ya existente.");

    case __NR_mq_unlink:
        return ("Remueve un mensaje de la cola name.");

    case __NR_mq_timedsend:
        return ("Añade un pensaje apuntado por msg_ptr a otro mensaje en la cola referido por el descriptor mqdes");

    case __NR_mq_timedreceive:
        return ("Remueve el más viejo mensaje con el nivel de prioridad más alto desde el mensaje de la cola referido por el descriptor de mensajes de cola mqdes.");
        //Danny
    case __NR_read:
        return ("Intenta leer para contar los bytes del descriptor de archivos fd en el bufffer");

    case __NR_write:
        return ("Escribe contadores de bytes desde el principio de buf al buffer");

    case __NR_open:
        return ("Abre el archivo especificado por el pathname");

    case __NR_close:
        return ("Cierra el descriptor del archivo así no queda referido a ninguno");

    case __NR_stat:
        return ("Retorna información del archivo, señalado por statbuf en el buffer");

    case __NR_fstat:
        return ("Retorna información del archivo, señalado por el descriptor de archivo fd");

    case __NR_lstat:
        return ("Si el pathname es un symbolic link retorna la informacion del link");

    case __NR_poll:
        return ("Espera conjunto de file descriptors para estar listo oara realizar I/O");

    case __NR_lseek:
        return ("Reposiciona el file offset de la descripción asociada al file descriptor fd al argumento offset");

    case __NR_mmap:
        return ("Crea un nuevo mapeo en el espacio de dirección virtual del proceso de llamada");

    case __NR_mprotect:
        return ("Cambia el acceso de protección para el proceso de llamada de memoria");

    case __NR_munmap:
        return ("Borra el mapeo para un rango de dirrección especifico");

    case __NR_brk:
        return ("Establece el final del segemento de información al valor especificado en en addr");

    case __NR_rt_sigaction:
        return ("Es utilizado para cambiar la accion tomada por el proceso en la recepción de una señal específica");

    case __NR_rt_sigprocmask:
        return ("Es utilizado para traer y/o cambiar la señal máscara del hilo de llamada");

    case __NR_rt_sigreturn:
        return ("Deshace todo lo hecho o cambiado por el proceso signal mask");

    case __NR_ioctl:
        return ("Manipula los parámetros del dispositivo subyacente de archivos especiales ");

    case __NR_pread64:
        return ("Lee hasta count bytes del descriptor de archivo fd, con desplazamiento offset, en el buffer empezando en buf");

    case __NR_pwrite64:
        return ("Escribe hasta count bytes del buffer, empezando en buf hasta fd, con desplazamiento offset");

    case __NR_readv:
        return ("Lee los iovcnt buffers del archivo asociado con el file descriptor fd en el buffer descrito por iov");

    case __NR_writev:
        return ("Escribe los oivcnt buffers de la información descrita por iov al archivo asociado con el file descriptor fd");

    case __NR_access:
        return ("Comprueba se el proceso de llamada puede acceder al archivo pathname");

    case __NR_pipe:
        return ("Crea una pipe, un canal de información unidireccional, utilizado para comunicación entre procesos");

    case __NR_select:
        return ("Permite al programa monitorear multimples file descriptors, esperando hasta que alguno esté listo para operaciones I/O");

    case __NR_sched_yield:
        return ("Hace que el hilo de llamada seda el CPU");

    case __NR_mremap:
        return ("Expande o encoge memoria de mapeado existente");

    case __NR_msync:
        return ("Vacía los cambios realizados en la copia en el núcleo de un archivo que se mapeado en la memoria usando mmap (2) de regreso al sistema de archivos");

    case __NR_mincore:
        return ("Retorna un vector que indica si las páginas de la memoria virtual del proceso de llamada se encuentra en el núcleo");

    case __NR_madvise:
        return ("Se utioliza para dar copnsejos o direcciones al kernel sobre el rango de direcciones que comienza en la dirección addr y de longitud length");

    case __NR_shmget:
        return ("Retorma el identificador del segmento de memoria compartida del System V asociado con el valor del argumento key");

    case __NR_shmat:
        return ("Adjunta el segmento de memoria compartida del System V identificado por shmid al espacio de dirección del proceso de llamada");

    case __NR_shmctl:
        return ("Realiza la operación de control especificada por el cmd en el segemnto de memoria compartida del System V cuyo identificador es dado por shmid");

    case __NR_dup:
        return ("Crea una copia del file descriptor oldfd, utilizando el descriptor de archivo no utilizado con el número más bajo para el nuevo descriptor");

    case __NR_dup2:
        return ("Crea una copia del file descriptor oldfd, utilizando el descriptor de archivo no utilizado el file descriptor number especificado en newfd");

    case __NR_pause:
        return ("Causa que la llamada a proceso se detenga hasta que una señasl sea entregada");

    case __NR_nanosleep:
        return ("Suspende la ejecucion del hilo de llamada hasta que haya concluido el tiempo especificado en *req");

    case __NR_getitimer:
        return ("Coloca el valor actual del timer esecificado por which en el buffer apuntado por curr_value");

    case __NR_alarm:
        return ("Hace arreglos para que se envie una señal SIGALRM al proceso que lo llamo en seconds segundos");

    case __NR_setitimer:
        return ("Arma o desarma el timer especificado por which");

    case __NR_getpid:
        return ("Retorna el process ID (PID) del proceso llamado");

    case __NR_sendfile:
        return ("Copia información entre un file descriptor y otro");

    case __NR_socket:
        return ("Crea un endpoint para la comunicación y retorno de un file descriptor que refiere ese endpoint");

    case __NR_connect:
        return ("Conecta el socket referido por el file descriptor sockfd a la direccion especificada en addr");

    case __NR_accept:
        return ("Extrae la primera solicitud de conexión en la cola de conexiones");

    case __NR_sendto:
        return ("Es utilizado para transmitir un mensaje a otro socket");

    case __NR_recvfrom:
        return ("Es utilizado para recibir un mensaje de un ssocket");

    case __NR_sendmsg:
        return ("Es utilizado para transmitir un mensaje a otro socket");

    case __NR_recvmsg:
        return ("Es utilizado para recibir un mensaje de un ssocket");

    case __NR_shutdown:
        return ("Causa que todas a parte de las conexiones al socket asociado a socfd sean apagadas");

    case __NR_bind:
        return ("Asigna la dirección especificada en addr al socket referido por sockfd");

    case __NR_listen:
        return ("Marca el socket referido por sockfd como un socket pasivo");

    case __NR_getsockname:
        return ("Retorna la dirección a la que sockfd está enlazado, en el buffer apuntado por addr");

    case __NR_getpeername:
        return ("Retorna la dirección del peer conectado al socket sockfd, en el buffer al que apunta addr");

    case __NR_socketpair:
        return ("Crea un par de soquets conectados en el dominio especificado, sin nombre");

    case __NR_setsockopt:
        return ("Manipula opciones para el socket referido por el file descriptor sockfd");

    case __NR_getsockopt:
        return ("Manipula opciones para el socket referido por el file descriptor sockfd");

    case __NR_clone:
        return ("Crea un nuevo proceso hijo, similar a fork");

    case __NR_fork:
        return ("Crea un nuevo proceso duplicando el proceso de llamada");

    case __NR_vfork:
        return ("Crea un nuevo proceso duplicando el proceso de llamada, pero con un comportamietno indefinido");

    case __NR_execve:
        return ("Ejecuta el programa que le es mandado por el parámetro pathname");

    case __NR_exit:
        return ("Termina el proceso de llamada inmediatamente");

    case __NR_wait4:
        return ("Retorna información acerca el uso de recursos usados por el hijo, en adición a suspender la ejecución del hilo de llamada");

    case __NR_kill:
        return ("Es usado para enviar cualquier señal al cualquier proceso ogrupo de procesos");

    case __NR_uname:
        return ("Retorna información del sistema en la estructura apuntada por buf");

    case __NR_semget:
        return ("Retorna el identificador del semáforo del System V asociado con el argumento key");

    case __NR_semop:
        return ("Realiza operaciones en los semáforos seleccionados por el conjunto por semid");

    case __NR_semctl:
        return ("Realiza la operación de control especificada por el cmd en el conjunto de semáforos del System V identificado por semid");

    case __NR_shmdt:
        return ("Une el segmento de memoria compartida System V al espacio de direcciones del proceso de llamada");

    case __NR_msgget:
        return ("Retorna el identificador de la cola de mensajes del System V asociado con el valor del argumento key");

    case __NR_msgsnd:
        return ("Agrega una copia del mensaje a la cola de mensajes");

    case __NR_msgrcv:
        return ("Remueve el mensaje de la cola y lo coloca en el buffer");

    case __NR_msgctl:
        return ("Realiza la operación de control en la cola de mensajes de System V");

    case __NR_fcntl:
        return ("Realiza distintas operaciones, entre ellas duplicar un file descriptos, banderas de flags descriptor, entre otros");

    case __NR_flock:
        return ("Aplica o elimina un bloqueo de advertencia al abrir archivos");

    case __NR_fsync:
        return ("Transfiere toda la información in-core modificada del archivo referido por el file descriptor fd al disco 'vertiendola'");

    case __NR_fdatasync:
        return ("Transfiere toda la información in-core modificada del archivo referido por el file descriptor fd al disco, pero no 'vierte' la metadata a menos que sea necesario");

    case __NR_truncate:
        return ("Hace que el archivo regular pasado por parámetro sea truncado a un tamaño preciso pasado por parámetro, en el archivo se debe poder escribir");

    case __NR_ftruncate:
        return ("Hace que el archivo regular pasado por parámetro sea truncado a un tamaño preciso pasado por parámetro, pero el archivo debe ser abiero para escritura");

    case __NR_getdents:
        return ("Lee varias estructuras linux_derent del directorio referido por parámetro, en el buffer pasado por parámetro");

    case __NR_getcwd:
        return ("Copia el nombre de la ruta absoluta del directorio de trabajo actual, a la matriz apuntada por buf, de tamaño lenght");

    case __NR_chdir:
        return ("Cambia el directorio de trabajo actual del proceso de llamada al directorio especificado en path");

    case __NR_fchdir:
        return ("Cambia el directorio de trabajo actual del proceso de llamada al file descriptor fd");

    case __NR_rename:
        return ("Renombra un archivo");

    case __NR_mkdir:
        return ("Intenta hacer un directorio con el nombre pasado por parámetro");

    case __NR_rmdir:
        return ("Borra un directorio que debe estar vacio");

    case __NR_creat:
        return ("Es equivalente a llamar open, con las banderas O_CREAT o O_WRONLY o O_TRUNC");

    case __NR_link:
        return ("Crea un nuevo link a un archivo existente");

    case __NR_unlink:
        return ("Borra el nobre del filesystem, Si el nombre es el último enlace a un archivo y ningún proceso lo teiene abiero, elimina el archivo");

    case __NR_symlink:
        return ("Crea un link simbólico con el nombre del parámetro linkpath, que contiene el string target");

    case __NR_readlink:
        return ("Coloca el contenido del link simbolico pathname en el buffer buf");

    case __NR_chmod:
        return ("Cambia el modo del archivo especificado por el pathname");

    case __NR_fchmod:
        return ("Cambia el modo del archivo referenciado por el file descriptor fd");

    case __NR_chown:
        return ("Cambia la propiedad del archivo especificado por pathname");

    case __NR_fchown:
        return ("Cambia la propiedad del archivo referenciado por el file descriptor fd");

    case __NR_lchown:
        return ("Cambia la propiedad del archivo especificado por pathname, pero no diferencia links simbólicos");

    case __NR_umask:
        return ("Establece el proceso de llamada del modo de creación de máscaras a el parámetro mask y retorna el valor anterior de la máscara");

    case __NR_gettimeofday:
        return ("Obtiene el tiempo del la zona horaria");

    case __NR_getrlimit:
        return ("Obtiene el límite de recursos");

    case __NR_getrusage:
        return ("Retorna el uso de recursos de lo que se le pase por el parámetro who");

    case __NR_sysinfo:
        return ("Retorna ciertas estadísticas sobre el uso de memoria y swap, como así como el promedio de carga");

    case __NR_times:
        return ("Almacena los tiempos de proceso actuales en struct tms al cual buf apunta");

    case __NR_ptrace:
        return ("Proporciona un medio por el cual un proceso puede observar y controlar la ejecución de otro proceso");

    case __NR_getuid:
        return ("Retorna el user ID real del proceso de llamada");

    case __NR_syslog:
        return ("Genera un mensaje de registro");

    case __NR_getgid:
        return ("Retorna el group ID real del proceso de llamada");

    case __NR_setuid:
        return ("Establece el user ID efectivo del proceso de llamada");
        //AQUI VAN LOS MIOS

    case __NR_mq_notify:
        return ("No disponible");

    case __NR_mq_getsetattr:
        return ("No disponible");

    case __NR_kexec_load:
        return ("Carga un nuevo kernel");

    case __NR_waitid:
        return ("Espera por cambios en el estado");

    case __NR_add_key:
        return ("Crea y actualiza una llave");

    case __NR_request_key:
        return ("Busca una llave del tipo especificado");

    case __NR_keyctl:
        return ("Permite a los programas manipular llaves");

    case __NR_ioprio_set:
        return ("Setea la clase de E/S y la prioridad de los hilos");

    case __NR_ioprio_get:
        return ("Setea la clase de E/S y la prioridad de los hilos");

    case __NR_inotify_init:
        return ("Inicializza una nueva instancia de inotify");

    case __NR_inotify_add_watch:
        return ("Adds a new watch, or modifies an existing watch");

    case __NR_inotify_rm_watch:
        return ("Removes the watch associated with the watch descriptor");

    case __NR_migrate_pages:
        return ("Attempts to move all pages of a process from old_nodes to new_nodes");

    case __NR_openat:
        return ("Opens the file specified by pathname");

    case __NR_mkdirat:
        return ("Attempts to create a directory");

    case __NR_mknodat:
        return ("Creates a filesystem node");

    case __NR_fchownat:
        return ("Change the owner and group of a file");

    case __NR_futimesat:
        return ("Obsolete");

    case __NR_newfstatat:
        return ("Return information about a file");

    case __NR_unlinkat:
        return ("Deletes a name from the filesystem");

    case __NR_renameat:
        return ("Renames a file");

    case __NR_linkat:
        return ("creates a new link to an existing file");

    case __NR_symlinkat:
        return ("Creates a symbolic link");

    case __NR_readlinkat:
        return ("Places the contents of the symbolic link pathname in the buffer");

    case __NR_fchmodat:
        return ("System calls change a files mode bits");

    case __NR_faccessat:
        return ("Checks whether the calling process can access the file");

    case __NR_pselect6:
        return ("Allows a program to monitor multiple file descriptors");

    case __NR_ppoll:
        return ("It waits for one of a set of file descriptors to perform I/O");

    case __NR_unshare:
        return ("Disassociate parts of its execution context");

    case __NR_set_robust_list:
        return ("Inform the kernel of the location of its robust futex list");

    case __NR_get_robust_list:
        return ("Obtains a thread's robust futex list");

    case __NR_splice:
        return ("Moves data between two file descriptors");

    case __NR_tee:
        return ("Duplicates bytes of data between pipes");

    case __NR_sync_file_range:
        return ("Permits fine control when synchronizing a file with disk");

    case __NR_vmsplice:
        return ("Maps or fills a range of user memory");

    case __NR_move_pages:
        return ("Moves pages to memory nodes");

    case __NR_utimensat:
        return ("Updates timestamps of a file");

    case __NR_epoll_pwait:
        return ("Waits for events on an epoll instance");

    case __NR_signalfd:
        return ("Creates a file descriptor that can be used to accept signals targeted at the caller");

    case __NR_timerfd_create:
        return ("Creates and operates on a timer that delivers timer expiration notifications");

    case __NR_eventfd:
        return ("Creates an eventfd object");

    case __NR_fallocate:
        return ("Allows the caller to directly manipulate the allocated disk space for a file");

    case __NR_timerfd_settime:
        return ("Sets a timer");

    case __NR_timerfd_gettime:
        return ("Gets the value of a timer");

    case __NR_accept4:
        return ("It extracts the first connection request on the queue");

    case __NR_signalfd4:
        return ("Creates a file descriptor that can be used to accept signals targeted at the caller");

    case __NR_eventfd2:
        return ("Creates an eventfd object");

    case __NR_epoll_create1:
        return ("Creates a new epoll(7) instance");

    case __NR_dup3:
        return ("Creates a copy of the file descriptor");

    case __NR_pipe2:
        return ("Creates a pipe");

    case __NR_inotify_init1:
        return ("Inicializza una nueva instancia de inotify");

    case __NR_preadv:
        return ("Llama un buffer para leer");

    case __NR_pwritev:
        return ("Llama un buffer para escribir");

    case __NR_rt_tgsigqueueinfo:
        return ("Envía una señal e información a un hilo");

    case __NR_perf_event_open:
        return ("Retorna un descriptor de archivo");

    case __NR_recvmmsg:
        return ("Permite recibir muchos mensajes de un socket");

    case __NR_fanotify_init:
        return ("Inicializa un nuevo grupo fanotify");

    case __NR_fanotify_mark:
        return ("Modifica marcas fanotify");

    case __NR_prlimit64:
        return ("Define límites de recursos");

    case __NR_name_to_handle_at:
        return ("Retorna el identificador de un archivo");

    case __NR_open_by_handle_at:
        return ("Abre el archivo correspondiente al identificador");

    case __NR_clock_adjtime:
        return ("Lee y setea los parámetros del reloj");

    case __NR_syncfs:
        return ("Sincroniza el sistema de archivos con los descriptores");

    case __NR_sendmmsg:
        return ("Permite enviar muchos mensajes de un socket");

    case __NR_setns:
        return ("Permite que un hilo se mueva a otro contexto");

    case __NR_getcpu:
        return ("Retorna el número de procesador y nodo un hilo");

    case __NR_process_vm_readv:
        return ("Transfiere datos del proceso remoto a uno local");

    case __NR_process_vm_writev:
        return ("Transfiere datos del proceso local a uno remoto");

    case __NR_kcmp:
        return ("Revisa si dos procesos comparten recursos del kernel");

    case __NR_finit_module:
        return ("Carga una imagen ELF en el espacio del kernel");

    case __NR_sched_setattr:
        return ("Setea la política de planificación para un hilo");

    case __NR_sched_getattr:
        return ("Trae la política de planificación asociada a un hilo");

    case __NR_renameat2:
        return ("Cambia el nombre de un archivo");

    case __NR_seccomp:
        return ("Opera el estado de Secure Computing de un proceso que lo llama");

    case __NR_getrandom:
        return ("Llena un buffer con bytes al azar");

    case __NR_memfd_create:
        return ("Crea un archivo anónimo y retorna su descriptor");

    case __NR_kexec_file_load:
        return ("Carga un nuevo kernel");

    case __NR_bpf:
        return ("Realiza operaciones de paquetes de filtros Berkeley");

    case __NR_execveat:
        return ("Ejecuta un programa");

    case __NR_userfaultfd:
        return ("Crea un nuevo objeto userfaultfd");

    case __NR_membarrier:
        return ("Reduce el overhead de instrucciones de memoria");

    case __NR_mlock2:
        return ("Bloquea parte o todo el espacio de direcciones virtual de un proceso en RAM");

    case __NR_copy_file_range:
        return ("Realiza una copia entre descriptores del kernel");

    case __NR_preadv2:
        return ("Lee el buffer de un descriptor");

    case __NR_pwritev2:
        return ("Escribe en el buffer de un descriptor");

    case __NR_pkey_mprotect:
        return ("Cambia las protecciones de acceso a las páginas de memoria de un proceso");

    case __NR_pkey_alloc:
        return ("Asigna una llave de protección");

    case __NR_pkey_free:
        return ("Libera una llave de protección");

    case __NR_statx:
        return ("Retorna la información de un archivo");

    case __NR_io_pgetevents:
        return ("Lee eventos");

    case __NR_rseq:
        return ("No disponible");

    case __NR_pidfd_send_signal:
        return ("Envía la señal 'sig' al proceso indicado");

    case __NR_io_uring_setup:
        return ("No disponible");

    case __NR_io_uring_enter:
        return ("No disponible");

    case __NR_io_uring_register:
        return ("No disponible");

    case __NR_open_tree:
        return ("No disponible");

    case __NR_move_mount:
        return ("No disponible");

    case __NR_fsopen:
        return ("No disponible");

    case __NR_fsconfig:
        return ("No disponible");

    case __NR_fsmount:
        return ("No disponible");

    case __NR_fspick:
        return ("No disponible");

    case __NR_pidfd_open:
        return ("Crea el descriptor de un proceso");

    case __NR_clone3:
        return ("Crea un nuevo proceso 'hijo'");

    case 437: //__NR_openat2
        return ("Abre un archivo");

    case 438: //__NR_pidfd_getfd
        return ("Asigna un nuevo descriptor a un proceso");

    default:
        return ("NO SE WE");
    }
}