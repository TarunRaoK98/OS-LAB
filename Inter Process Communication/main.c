#include "utilities.h"

int main (void)
{
	pid_t pid;

	char numberBuff1[4];		char numberBuff2[4];
	char numberBuff3[4];		char numberBuff4[4];

	char* clientInit[2];		char* serverInit[2];
	char* clientArgs[3];		char* serverArgs[3];	
	
	int requestPipe[2];		int responsePipe[2];

	pipe(requestPipe);		pipe(responsePipe);
	
	sprintf(numberBuff1, "%d", responsePipe[0]);
	sprintf(numberBuff2, "%d", requestPipe[1]);
	sprintf(numberBuff3, "%d", requestPipe[0]);
	sprintf(numberBuff4, "%d", responsePipe[1]);

	clientInit[0] = "./clientInit";		serverInit[0] = "./serverInit";
	clientInit[1] = NULL;			serverInit[1] = NULL;	
	clientArgs[0] = numberBuff1;		serverArgs[0] = numberBuff3;	
	clientArgs[1] = numberBuff2;		serverArgs[1] = numberBuff4;
	clientArgs[2] = NULL;			serverArgs[2] = NULL;

	
	pid = fork();

	if (pid == 0)
		execvp (clientInit[0], clientArgs);

	else if (pid > 0)
		execvp (serverInit[0], serverArgs);

	return 0;
}
