#include "utilities.h"

int clientReady = 0;
void signalHandler (int);

int main (int argc, char* argv[])
{
	signal(SIGUSR2, signalHandler);
	int readFd, writeFd;
	pid_t clientID, serverID;
	Data* dataPacket;

	pid_t* ptr = &clientID;
	dataPacket = malloc(sizeof(Data));

	readFd = atoi (argv[0]);	writeFd = atoi (argv[1]);
	serverID = getpid();	
	read(readFd, ptr, sizeof(pid_t));
	clientID = *ptr;

	printf ("Server: Online\n");
	kill(clientID, SIGUSR1);

	while (1)
	{
		while(clientReady == 0);	//wait
		clientReady = 0;
	
		read(readFd, dataPacket, sizeof(Data));
	
		printf("Server: Data Received\n");
		kill(clientID, SIGUSR1);
	}	
	
	return 0;
}

void signalHandler (int iSig)
{
	clientReady = 1;
}
