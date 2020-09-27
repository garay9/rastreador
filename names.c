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
    switch (syscall)
    {

        //AQUI VAN LOS MIOS

    case __NR_mq_notify:
        return ("Not available");

    case __NR_mq_getsetattr:
        return ("Not available");

    case __NR_kexec_load:
        return ("Loads a new kernel");

    case __NR_waitid:
        return ("Wait for state changes");

    case __NR_add_key:
        return ("Creates or updates a key");

    case __NR_request_key:
        return ("Attempts to find a key of the given type");

    case __NR_keyctl:
        return ("Allows user-space programs to perform key manipulation");

    case __NR_ioprio_set:
        return ("Sets the I/O scheduling class and priority of one or more threads");

    case __NR_ioprio_get:
        return ("Gets the I/O scheduling class and priority of one or more threads");

    case __NR_inotify_init:
        return ("Initializes a new inotify instance");

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
        return ("Initializes a new inotify instance");

    case __NR_preadv:
        return ("Calls a buffer to read");

    case __NR_pwritev:
        return ("Calls a buffer to write");

    case __NR_rt_tgsigqueueinfo:
        return ("Sends a signal plus data to a process or thread");

    case __NR_perf_event_open:
        return ("Returns a file descriptor from a list of parameters");

    case __NR_recvmmsg:
        return ("Allows the caller to receive multiple messages from a socket");

    case __NR_fanotify_init:
        return ("Initializes a new fanotify group and returns a file descriptor for it");

    case __NR_fanotify_mark:
        return ("Adds, removes, or modifies a fanotify mark on a filesystem object");

    case __NR_prlimit64:
        return ("Sets resource limits");

    case __NR_name_to_handle_at:
        return ("Returns an opaque handle that corresponds to a specified file");

    case __NR_open_by_handle_at:
        return ("Opens the file corresponding to a handle");

    case __NR_clock_adjtime:
        return ("Reads and optionally sets adjustment parameters for this algorithm");

    case __NR_syncfs:
        return ("Synchronizes the filesystem containing file in the open file descriptor");

    case __NR_sendmmsg:
        return ("Allows the caller to transmit multiple messages on a socket");

    case __NR_setns:
        return ("Alows the calling thread to move into different namespaces");

    case __NR_getcpu:
        return ("Writes the processor and node that the calling thread is running on to ints");

    case __NR_process_vm_readv:
        return ("Transfers data from the remote process to the local process");

    case __NR_process_vm_writev:
        return ("It transfers data from the local process to the remote process");

    case __NR_kcmp:
        return ("Checks whether two processes share a kernel resource");

    case __NR_finit_module:
        return ("Loads an ELF image into kernel space");

    case __NR_sched_setattr:
        return ("Sets the scheduling policy and associated attributes for a thread");

    case __NR_sched_getattr:
        return ("Fetches the scheduling policy and the associated attributes for a thread");

    case __NR_renameat2:
        return ("Renames a file");

    case __NR_seccomp:
        return ("Operates on the Secure Computing state of the calling process.");

    case __NR_getrandom:
        return ("Fills a buffer with random bytes");

    case __NR_memfd_create:
        return ("Creates an anonymous file and returns a file descriptor for it");

    case __NR_kexec_file_load:
        return ("Loads a new kernel");

    case __NR_bpf:
        return ("Performs a range of operations related to extended Berkeley Packet Filters");

    case __NR_execveat:
        return ("Executes a program");

    case __NR_userfaultfd:
        return ("Creates a new userfaultfd object");

    case __NR_membarrier:
        return ("Reduces the overhead of the memory barrier instructions");

    case __NR_mlock2:
        return ("mlock2");

    case __NR_copy_file_range:
        return ("Lock part or all of the calling process's virtual address space into RAM");

    case __NR_preadv2:
        return ("Reads buffers from the file associated with a file descriptor");

    case __NR_pwritev2:
        return ("Writes buffers from the file associated with a file descriptor");

    case __NR_pkey_mprotect:
        return ("Changes the access protections for the calling process's memory pages");

    case __NR_pkey_alloc:
        return ("Allocates a protection key");

    case __NR_pkey_free:
        return ("Frees a protection key");

    case __NR_statx:
        return ("Returns information about a file");

    case __NR_io_pgetevents:
        return ("Reads events");

    case __NR_rseq:
        return ("Not available");

    case __NR_pidfd_send_signal:
        return ("Sends the signal 'sig' to the target process");

    case __NR_io_uring_setup:
        return ("Not available");

    case __NR_io_uring_enter:
        return ("Not available");

    case __NR_io_uring_register:
        return ("Not available");

    case __NR_open_tree:
        return ("Not available");

    case __NR_move_mount:
        return ("Not available");

    case __NR_fsopen:
        return ("Not available");

    case __NR_fsconfig:
        return ("Not available");

    case __NR_fsmount:
        return ("Not available");

    case __NR_fspick:
        return ("Not available");

    case __NR_pidfd_open:
        return ("Creates a file descriptor that refers to a process");

    case __NR_clone3:
        return ("Creates a new 'child' process");

    case 437: //__NR_openat2
        return ("Opens a file");

    case 438: //__NR_pidfd_getfd
        return ("Allocates a new file descriptor in the calling process");

    default:
        return ("NO SE WE");
    }
}