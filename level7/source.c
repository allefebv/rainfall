#include <stdlib.h>
#include <stdio.h>

int main(int argc, char **argv)
{
    /* PROLOGUE */
    //    0x08048521 <+0>:	push   ebp
    //    0x08048522 <+1>:	mov    ebp,esp
    //    0x08048524 <+3>:	and    esp,0xfffffff0

    void *buf1;
    void *buf2;
    int fd;
    //    0x08048527 <+6>:	sub    esp,0x20

    buf1 = malloc(8); // HEAP 1
    //    0x0804852a <+9>:	mov    DWORD PTR [esp],0x8
    //    0x08048531 <+16>:	call   0x80483f0 <malloc@plt>
    //    0x08048536 <+21>:	mov    DWORD PTR [esp+0x1c],eax
    //    0x0804853a <+25>:	mov    eax,DWORD PTR [esp+0x1c]

    (int)*buf1 = 1;
    //    0x0804853e <+29>:	mov    DWORD PTR [eax],0x1
    //    0x08048544 <+35>:	mov    DWORD PTR [esp],0x8
    //    0x0804854b <+42>:	call   0x80483f0 <malloc@plt>

    *(buf1 + 4) = malloc(8); // HEAP 2
    //    0x08048550 <+47>:	mov    edx,eax
    //    0x08048552 <+49>:	mov    eax,DWORD PTR [esp+0x1c]
    //    0x08048556 <+53>:	mov    DWORD PTR [eax+0x4],edx

    buf2 = malloc(8); // HEAP 3
    //    0x08048559 <+56>:	mov    DWORD PTR [esp],0x8
    //    0x08048560 <+63>:	call   0x80483f0 <malloc@plt>
    //    0x08048565 <+68>:	mov    DWORD PTR [esp+0x18],eax
    //    0x08048569 <+72>:	mov    eax,DWORD PTR [esp+0x18]

    (int)*buf2 = 2;
    //    0x0804856d <+76>:	mov    DWORD PTR [eax],0x2
    //    0x08048573 <+82>:	mov    DWORD PTR [esp],0x8
    //    0x0804857a <+89>:	call   0x80483f0 <malloc@plt>

    *(buf2 + 4) = malloc(8); // HEAP 4
    //    0x0804857f <+94>:	mov    edx,eax
    //    0x08048581 <+96>:	mov    eax,DWORD PTR [esp+0x18]
    //    0x08048585 <+100>:	mov    DWORD PTR [eax+0x4],edx

    strcpy(*(buf1 + 4), argv[1]); // replaces value stored inside heap3[4] (heap4 addr) by addr GOT puts
    //    0x08048588 <+103>:	mov    eax,DWORD PTR [ebp+0xc]
    //    0x0804858b <+106>:	add    eax,0x4
    //    0x0804858e <+109>:	mov    eax,DWORD PTR [eax]
    //    0x08048590 <+111>:	mov    edx,eax
    //    0x08048592 <+113>:	mov    eax,DWORD PTR [esp+0x1c]
    //    0x08048596 <+117>:	mov    eax,DWORD PTR [eax+0x4]
    //    0x08048599 <+120>:	mov    DWORD PTR [esp+0x4],edx
    //    0x0804859d <+124>:	mov    DWORD PTR [esp],eax
    //    0x080485a0 <+127>:	call   0x80483e0 <strcpy@plt>

    strcpy(*(buf2 + 4), argv[2]);
    //    0x080485a5 <+132>:	mov    eax,DWORD PTR [ebp+0xc]
    //    0x080485a8 <+135>:	add    eax,0x8
    //    0x080485ab <+138>:	mov    eax,DWORD PTR [eax]
    //    0x080485ad <+140>:	mov    edx,eax
    //    0x080485af <+142>:	mov    eax,DWORD PTR [esp+0x18]
    //    0x080485b3 <+146>:	mov    eax,DWORD PTR [eax+0x4]
    //    0x080485b6 <+149>:	mov    DWORD PTR [esp+0x4],edx
    //    0x080485ba <+153>:	mov    DWORD PTR [esp],eax
    //    0x080485bd <+156>:	call   0x80483e0 <strcpy@plt>

    fd = fopen("/home/user/level8/.pass", "r");
    //    0x080485c2 <+161>:	mov    edx,0x80486e9
    //    0x080485c7 <+166>:	mov    eax,0x80486eb
    //    0x080485cc <+171>:	mov    DWORD PTR [esp+0x4],edx
    //    0x080485d0 <+175>:	mov    DWORD PTR [esp],eax
    //    0x080485d3 <+178>:	call   0x8048430 <fopen@plt>

    fgets(0x8049960, 0x44, fd);
    //    0x080485d8 <+183>:	mov    DWORD PTR [esp+0x8],eax
    //    0x080485dc <+187>:	mov    DWORD PTR [esp+0x4],0x44
    //    0x080485e4 <+195>:	mov    DWORD PTR [esp],0x8049960
    //    0x080485eb <+202>:	call   0x80483c0 <fgets@plt>

    puts("~~");
    //    0x080485f0 <+207>:	mov    DWORD PTR [esp],0x8048703
    //    0x080485f7 <+214>:	call   0x8048400 <puts@plt>

    /* EPILOGUE */
    //    0x080485fc <+219>:	mov    eax,0x0
    //    0x08048601 <+224>:	leave
    //    0x08048602 <+225>:	ret
}

void m(void)
{
    /* PROLOGUE */
    //    0x080484f4 <+0>:	push   ebp
    //    0x080484f5 <+1>:	mov    ebp,esp
    //    0x080484f7 <+3>:	sub    esp,0x18

    time(0);
    //    0x080484fa <+6>:	mov    DWORD PTR [esp],0x0
    //    0x08048501 <+13>:	call   0x80483d0 <time@plt>

    printf("%s - %d\n", 0x8049960, eax);
    //    0x08048506 <+18>:	mov    edx,0x80486e0
    //    0x0804850b <+23>:	mov    DWORD PTR [esp+0x8],eax
    //    0x0804850f <+27>:	mov    DWORD PTR [esp+0x4],0x8049960
    //    0x08048517 <+35>:	mov    DWORD PTR [esp],edx
    //    0x0804851a <+38>:	call   0x80483b0 <printf@plt>

    /* EPILOGUE */
    //    0x0804851f <+43>:	leave
    //    0x08048520 <+44>:	ret
}
