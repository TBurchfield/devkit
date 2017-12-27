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

#include "main.h"

int main(int argc, char ** argv) {
  fprintf(stdout,"Starting devkit...\n");
  char* command;
  int flag_index = 0;
  if (strcmp(argv[0],"devkit")==0) {
    fprintf(stdout,"devkit\n");
    command = argv[1];
    flag_index = 2;
  } else {
    command = argv[0];
    flag_index = 1;
  }
  fprintf(stdout, "%s\n", command);
  if (strcmp(command,"pre")==0) {
    //pre_func(argc, argv);
    pre(argc, argv);
  }
  return 0;
}
