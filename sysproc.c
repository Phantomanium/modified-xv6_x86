#include "types.h"
#include "x86.h"
#include "defs.h"
#include "date.h"
#include "param.h"
#include "memlayout.h"
#include "mmu.h"
#include "proc.h"
#include "fcntl.h"

int
sys_fork(void)
{
  return fork();
}

int
sys_exit(void)
{
  exit();
  return 0;  // not reached
}

int
sys_wait(void)
{
  return wait();
}

int
sys_kill(void)
{
  int pid;

  if(argint(0, &pid) < 0)
    return -1;
  return kill(pid);
}

int
sys_getpid(void)
{
  return myproc()->pid;
}

int
sys_sbrk(void)
{
  int addr;
  int n;

  if(argint(0, &n) < 0)
    return -1;
  addr = myproc()->sz;
  if(growproc(n) < 0)
    return -1;
  return addr;
}

int
sys_sleep(void)
{
  int n;
  uint ticks0;

  if(argint(0, &n) < 0)
    return -1;
  acquire(&tickslock);
  ticks0 = ticks;
  while(ticks - ticks0 < n){
    if(myproc()->killed){
      release(&tickslock);
      return -1;
    }
    sleep(&ticks, &tickslock);
  }
  release(&tickslock);
  return 0;
}

// return how many clock tick interrupts have occurred
// since start.
int
sys_uptime(void)
{
  uint xticks;

  acquire(&tickslock);
  xticks = ticks;
  release(&tickslock);
  return xticks;
}

int sys_gettimeoftheday(void)
{
  struct rtcdate *r;
  if(argptr(0, (void*)&r, sizeof(struct rtcdate)) < 0)
    return -1;
  cmostime(r);
  return 0;
}

int sys_setusername(void) {
    char *new_username;
    if (argstr(0, &new_username) < 0)
        return -1;
    
    //Set the new username in the Global username variable
    safestrcpy(username, new_username, MAX_USERNAME_LENGTH);
    return 0;
}

int sys_getusername(void) {
    char *buf;
    int bufsize;
    if(argint(1, &bufsize) < 0)
        return -1;
    if (argptr(0, &buf, bufsize) < 0)
        return -1;

    //Copy the username from the global variable to the buffer
    safestrcpy(buf, username, bufsize);
    return 0;
}

int sys_myneofetch(void){
    cprintf("\x1b[1;32m   XV6 Custom neofetch\x1b[0m\n");
    cprintf("\x1b[1;32m   Version: %s\x1b[0m\n", "1.0");
    cprintf("\x1b[1;32m   Build Date: %s\x1b[0m\n", __DATE__);
    cprintf("\x1b[1;32m   User: %s\x1b[0m\n", username);
    cprintf("\x1b[1;32m   kernel: %s\x1b[0m\n", "xv6");
    //Print uptime
    uint ticks = sys_uptime();
    uint secs = ticks / 100;
    uint mins = secs / 60;
    uint hours = mins / 60;
    secs = secs % 60;
    mins = mins % 60;
    hours = hours % 24;
    cprintf("\x1b[1;32m   Uptime: %d:%d:%d\x1b[0m\n", hours, mins, secs);
    return 0;
}