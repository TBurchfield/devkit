/*
 * DevKit
 * main.c
 *
 * Core code for running the devkit executable and parsing commands.
 * This file ALWAYS compiles into devkit.
 *
 * USAGE:
 *  ARGS:
 *    argv[0] - command type, all other flag parsing is dependent on this.
 */
#include "stdio.h"
#include "string.h"

int main(int argc, char ** argv) {
  if (strcmp(argv[0],"devkit")==0) {
    fprintf(stdout,"devkit\n");
  }
  return 0;
}
