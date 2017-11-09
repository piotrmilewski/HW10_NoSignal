#ifndef MAIN
#define MAIN

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>
#include <signal.h>
#include <sys/stat.h>

void printError( int err);
static void sighandler( int signo);
int main();

#endif
