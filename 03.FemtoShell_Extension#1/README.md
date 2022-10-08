# Assignment #3 (Femto Shell Extension #1)

Extend your femto shell to support the following features:

1. Executing external commands using fork and exec
1. Local and env variables where the env variables are passed to any child created by your shell while the local variables are not passed to the children.

## Compilation commands

```bash
gcc -o fecho echo.c
gcc -o fcp cp.c
gcc -o fmv mv.c
gcc -o fpwd pwd.c
gcc -o femtoShell femtoShell.c
```

## Sample Output

```bash
It's the femto shell >> 
It's the femto shell >> 
It's the femto shell >> 
It's the femto shell >> ls
cp.c  echo.c  fcp  fecho  femtoShell  femtoShell.c  fmv  fpwd  hello  interface.h  mv.c  private.h  pwd.c
It's the femto shell >> pwd
/home/ahmed/Data/LinuxRunners/Github/Linux-Runners/03.FemtoShell_Extension#1
It's the femto shell >> fpwd
Current Working Directory: /home/ahmed/Data/LinuxRunners/Github/Linux-Runners/03.FemtoShell_Extension#1
It's the femto shell >> 
It's the femto shell >> cat hello
Hello, test copy and move.

Thanks.
It's the femto shell >> 
It's the femto shell >> cp hello helloCopy
It's the femto shell >> 
It's the femto shell >> ls
cp.c  echo.c  fcp  fecho  femtoShell  femtoShell.c  fmv  fpwd  hello  helloCopy  interface.h  mv.c  private.h  pwd.c
It's the femto shell >> 
It's the femto shell >> cat helloCopy
Hello, test copy and move.

Thanks.
It's the femto shell >> 
It's the femto shell >> 
It's the femto shell >> fcp hello helloCopyFemto
It's the femto shell >> 
It's the femto shell >> ls
cp.c  echo.c  fcp  fecho  femtoShell  femtoShell.c  fmv  fpwd  hello  helloCopy  helloCopyFemto  interface.h  mv.c  private.h  pwd.c
It's the femto shell >> cat helloCopyFemto
Hello, test copy and move.

Thanks.
It's the femto shell >> 
It's the femto shell >> fmv helloCopy helloMoveFemto
It's the femto shell >> 
It's the femto shell >> ls
cp.c  echo.c  fcp  fecho  femtoShell  femtoShell.c  fmv  fpwd  hello  helloCopyFemto  helloMoveFemto  interface.h  mv.c  private.h  pwd.c
It's the femto shell >> 
It's the femto shell >> cat helloMoveFemto
Hello, test copy and move.

Thanks.
It's the femto shell >> 
It's the femto shell >> echo Ahmed
Ahmed
It's the femto shell >> 
It's the femto shell >> Fecho Ahmed Gouda
Command doesn't exist is femto shell or main shell
It's the femto shell >> fecho Ahmed Gouda
Ahmed Gouda 
It's the femto shell >> ls                 -l                   /
total 76
lrwxrwxrwx   1 root root     7 Sep 23 18:27 bin -> usr/bin
drwxr-xr-x   4 root root  4096 Oct  1 12:51 boot
drwxrwxr-x   2 root root  4096 Sep 23 18:30 cdrom
drwxr-xr-x  20 root root  5060 Oct  8 13:33 dev
drwxr-xr-x 135 root root 12288 Oct  8 13:29 etc
drwxr-xr-x   3 root root  4096 Sep 23 18:31 home
lrwxrwxrwx   1 root root     7 Sep 23 18:27 lib -> usr/lib
lrwxrwxrwx   1 root root     9 Sep 23 18:27 lib32 -> usr/lib32
lrwxrwxrwx   1 root root     9 Sep 23 18:27 lib64 -> usr/lib64
lrwxrwxrwx   1 root root    10 Sep 23 18:27 libx32 -> usr/libx32
drwx------   2 root root 16384 Sep 23 18:27 lost+found
drwxr-xr-x   3 root root  4096 Sep 23 23:37 media
drwxr-xr-x   2 root root  4096 Aug  9 13:48 mnt
drwxr-xr-x   3 root root  4096 Sep 24 00:37 opt
dr-xr-xr-x 445 root root     0 Oct  8 13:33 proc
drwx------   4 root root  4096 Sep 26 03:52 root
drwxr-xr-x  37 root root  1080 Oct  8 14:29 run
lrwxrwxrwx   1 root root     8 Sep 23 18:27 sbin -> usr/sbin
drwxr-xr-x  22 root root  4096 Sep 26 02:16 snap
drwxr-xr-x   2 root root  4096 Aug  9 13:48 srv
dr-xr-xr-x  13 root root     0 Oct  8 13:33 sys
drwxrwxrwt  30 root root  4096 Oct  8 16:27 tmp
drwxr-xr-x  14 root root  4096 Aug  9 13:48 usr
drwxr-xr-x  14 root root  4096 Aug  9 13:54 var
It's the femto shell >> 
It's the femto shell >> 
It's the femto shell >> x=10
It's the femto shell >> y=11
It's the femto shell >> z=12
It's the femto shell >> fset
localVar[0]: x = 10
localVar[1]: y = 11
localVar[2]: z = 12
It's the femto shell >> 
It's the femto shell >> 
It's the femto shell >> env
...
...
LC_NUMERIC=en_US.UTF-8
_=/home/ahmed/Data/LinuxRunners/Github/Linux-Runners/03.FemtoShell_Extension#1/femtoShell
It's the femto shell >>
It's the femto shell >> fexport x
It's the femto shell >> fexport z
It's the femto shell >> 
It's the femto shell >> fexport xyz
Couldn't export [xyz], variable doesn't exist.
It's the femto shell >> 
It's the femto shell >> env
...
...
LC_NUMERIC=en_US.UTF-8
_=/home/ahmed/Data/LinuxRunners/Github/Linux-Runners/03.FemtoShell_Extension#1/femtoShell
x=10
z=12
It's the femto shell >> 
It's the femto shell >> fecho Thanks Eng. Reda
Thanks Eng. Reda 
It's the femto shell >> 
It's the femto shell >> 
It's the femto shell >> fexit
```
