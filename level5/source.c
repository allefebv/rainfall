#include <stdlib.h>
#include <stdio.h>

void n(void)
{
    //    0x080484c2 <+0>:	push   ebp
    //    0x080484c3 <+1>:	mov    ebp,esp

    char buf[536];
    //    0x080484c5 <+3>:	sub    esp,0x218

    fgets(buf, 0x200, stdout);
    //    0x080484cb <+9>:	mov    eax,ds:0x8049848
    //    0x080484d0 <+14>:	mov    DWORD PTR [esp+0x8],eax
    //    0x080484d4 <+18>:	mov    DWORD PTR [esp+0x4],0x200
    //    0x080484dc <+26>:	lea    eax,[ebp-0x208]
    //    0x080484e2 <+32>:	mov    DWORD PTR [esp],eax
    //    0x080484e5 <+35>:	call   0x80483a0 <fgets@plt>

    printf(buf);
    //    0x080484ea <+40>:	lea    eax,[ebp-0x208]
    //    0x080484f0 <+46>:	mov    DWORD PTR [esp],eax
    //    0x080484f3 <+49>:	call   0x8048380 <printf@plt>

    exit(1);  // overwrite GOT exit
    //    0x080484f8 <+54>:	mov    DWORD PTR [esp],0x1
    //    0x080484ff <+61>:	call   0x80483d0 <exit@plt>
}

int main(void)
{
    //    0x08048504 <+0>:	push   ebp
    //    0x08048505 <+1>:	mov    ebp,esp
    //    0x08048507 <+3>:	and    esp,0xfffffff0

    n();
    //    0x0804850a <+6>:	call   0x80484c2 <n>

    return (0);
    //    0x0804850f <+11>:	leave
    //    0x08048510 <+12>:	ret
}

void o(void) // function pointer is 0x080484a4
{
    //    0x080484a4 <+0>:	push   ebp
    //    0x080484a5 <+1>:	mov    ebp,esp

    char buf[24];
    //    0x080484a7 <+3>:	sub    esp,0x18
    //    0x080484aa <+6>:	mov    DWORD PTR [esp],0x80485f0

    system("/bin/sh");
    //    0x080484b1 <+13>:	call   0x80483b0 <system@plt>
    //    0x080484b6 <+18>:	mov    DWORD PTR [esp],0x1

    exit(1);
    //    0x080484bd <+25>:	call   0x8048390 <_exit@plt>
}