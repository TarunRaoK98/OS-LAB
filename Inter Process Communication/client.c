#include "utilities.h"

void signalHandler (int);
int serverReady;

int main (int argc, char* argv[])
{
	int readFd, writeFd;
	pid_t clientID, serverID;
	pid_t* ptr = &clientID;
	Data* dataPacket;
	serverReady = 0;

	readFd = atoi (argv[0]);	writeFd = atoi (argv[1]);
	clientID = getpid();		
	serverID = getppid();
	write (writeFd, ptr, sizeof(pid_t));
	signal(SIGUSR1, signalHandler);

	printf ("Client: Online\n");
	
	while(serverReady == 0);	//wait
	serverReady = 0;
	printf ("Client: Connected to Server!!\n");

	dataPacket = malloc(sizeof(Data));

	kill(serverID, SIGUSR2);
	write(writeFd, dataPacket, sizeof(Data));
	printf("Client: Data Sent\n");

	while(serverReady == 0);	//wait
	serverReady = 0;

	printf("Client: Ending Session\n");
	kill(serverID, SIGINT);
	return 0;
}

void signalHandler (int iSig)
{
	serverReady = 1;
}
