#line 0"rsh.c"

#include <stdio.h>
#include <stdlib.h>
#include <spawn.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>

extern char **environ;

int main(){
for(;;){
fprintf(stderr, "rsh>");
char line[256];
if(fgets(line, sizeof line, stdin) && strcmp(line, "\n")){
{
char *end = line + strlen(line);
*--end = ' ';
while(*--end == ' '){
end[1] = 0;}}
char *argv[20], **argPtr = argv;
for(char *arg = line; *(*argPtr++ = arg); ++arg){
while(*arg != ' '){
++arg;}
*arg = 0;}
*--argPtr = 0;
if(!(strcmp(line,"cp") && strcmp(line,"touch") && strcmp(line,"mkdir") && strcmp(line,"ls") && strcmp(line,"cat") && strcmp(line,"grep") && strcmp(line,"chmod") && strcmp(line,"diff"))){
posix_spawnattr_t attr;
posix_spawnattr_init(&attr);
pid_t pid;
posix_spawnp(&pid, *argv, NULL, &attr, argv, environ);
waitpid(pid, (int[1]){}, 0);
posix_spawnattr_destroy(&attr);}
else if(!strcmp(line, "cd")){
if(argPtr - argv > 2){
printf("-rsh: cd: too many arguments\n");}
else{
chdir(argv[1]);}}
else if(!strcmp(line, "exit")){
return 0;}
else if(!strcmp(line, "help")){
printf("The allowed commands are:\n1: cp\n2: touch\n3: mkdir\n4: ls\n5: pwd\n6: cat\n7: grep\n8: chmod\n9: diff\n10: cd\n11: exit\n12: help\n");}













else{
printf("NOT ALLOWED!\n");}}}}
