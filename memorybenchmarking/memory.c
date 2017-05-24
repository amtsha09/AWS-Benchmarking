#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <string.h>

#define BYTE 1
#define KILO_BYTE 1024
#define MEGA_BYTE 1024*1024
#define BUFSIZE 1024*1024*10

void *memory_banchmark_byte_operation( void )
{
	printf("INSIDE BYTE OPERATION:\n");
	char *pcDestinationBuf;
	char *pcSourceBuf;
	int iLoopCounter;
	double dStartTime, dEndTime, dTotalTime;
	int iRandomNum;
	
	pcDestinationBuf = (char *)malloc(BUFSIZE*sizeof(char ));
	pcSourceBuf = (char *)malloc(BUFSIZE*sizeof(char ));

	/* Sequential process */	
	dStartTime = clock();
	for(iLoopCounter = 0; iLoopCounter < 10000; iLoopCounter++)
	{
		memcpy(pcDestinationBuf+(iLoopCounter * BYTE), pcSourceBuf+ (iLoopCounter * BYTE), (sizeof(char)*BYTE));		
	}
	dEndTime = clock();
	dTotalTime = (double)dEndTime - dStartTime/CLOCKS_PER_SEC;
	printf("************************************************************\n*\t\t Sequential Access write time\t\t*\n");
	printf("*  Latancy time in msec = %lf\t\t*\n", ((dTotalTime*1000)/(BYTE*10000)));
	printf("*  Speed of Sequential write in Mb/Sec = %lf\t\t*\n", ((BYTE*10000)/(dTotalTime)));
	
	/* Random Process */
	dStartTime = clock();
	for(iLoopCounter = 0; iLoopCounter < 10000; iLoopCounter++)
	{
		iRandomNum = rand()%BYTE;
		memcpy(pcDestinationBuf+(iLoopCounter*BYTE)%(BUFSIZE - 1), pcSourceBuf+(iRandomNum%(BUFSIZE -1)), (sizeof(char)*BYTE));		

	}
	dEndTime = clock();
	dTotalTime = (double)dEndTime - dStartTime/CLOCKS_PER_SEC;
	printf("************************************************************\n*\t\t Random Access write time\t\t*\n");
	printf("*  Latancy time in msec = %lf\t\t*\n", ((dTotalTime*1000)/(BYTE*10000)));
	printf("*  Speed of Random write in Mb/Sec = %lf\t\t*\n", ((BYTE*10000*2)/(dTotalTime)));

}
void *memory_banchmark_kilobyte_operation( void )
{
	printf("INSIDE KILOBYTES OPERATION:\n");
	char *pcDestinationBuf;
	char *pcSourceBuf;
	int iLoopCounter;
	double dStartTime, dEndTime, dTotalTime;
	int iRandomNum;
	
	pcDestinationBuf = (char *)malloc(BUFSIZE*sizeof(char ));
	pcSourceBuf = (char *)malloc(BUFSIZE*sizeof(char ));

	/* Sequential process */	
	dStartTime = clock();
	for(iLoopCounter = 0; iLoopCounter < 1000; iLoopCounter++)
	{
		memcpy(pcDestinationBuf+(iLoopCounter * KILO_BYTE), pcSourceBuf+ (iLoopCounter * KILO_BYTE), (sizeof(char)*KILO_BYTE));		
	}
	dEndTime = clock();
	dTotalTime = (double)dEndTime - dStartTime/CLOCKS_PER_SEC;
	printf("************************************************************\n*\t\t Sequential Access write time\t\t*\n");
	printf("*  Latancy time in msec = %lf\t\t*\n", ((dTotalTime*1000)/(KILO_BYTE*1000)));
	printf("*  Speed of Sequential write in Mb/Sec = %lf\t\t*\n", ((KILO_BYTE*1000)/(dTotalTime)));
	
	/* Random Process */
	dStartTime = clock();
	for(iLoopCounter = 0; iLoopCounter < 1000; iLoopCounter++)
	{
		iRandomNum = rand()%KILO_BYTE;
		memcpy(pcDestinationBuf+(iLoopCounter*KILO_BYTE)%(BUFSIZE - 1), pcSourceBuf+(iRandomNum%(BUFSIZE -1)), (sizeof(char)*KILO_BYTE));		

	}
	dEndTime = clock();
	dTotalTime = (double)dEndTime - dStartTime/CLOCKS_PER_SEC;
	printf("************************************************************\n*\t\t Random Access write time\t\t*\n");
	printf("*  Latancy time in msec = %lf\t\t*\n", ((dTotalTime*1000)/(KILO_BYTE*1000)));
	printf("*  Speed of Random write in Mb/Sec = %lf\t\t*\n", ((KILO_BYTE*1000*2)/(dTotalTime)));
}

void *memory_banchmark_megabyte_operation(void)
{
	printf("INSIDE MEGABYTES OPERATION:\n");
	char *pcDestinationBuf;
	char *pcSourceBuf;
	int iLoopCounter;
	double dStartTime, dEndTime, dTotalTime;
	int iRandomNum;
	
	pcDestinationBuf = (char *)malloc(BUFSIZE*sizeof(char ));
	pcSourceBuf = (char *)malloc(BUFSIZE*sizeof(char ));

	/* Sequential process */	
	dStartTime = clock();
	for(iLoopCounter = 0; iLoopCounter < 10; iLoopCounter++)
	{
		memcpy(pcDestinationBuf+(iLoopCounter * MEGA_BYTE), pcSourceBuf+ (iLoopCounter * MEGA_BYTE), (sizeof(char)*MEGA_BYTE));		
	}
	dEndTime = clock();
	dTotalTime = (double)dEndTime - dStartTime/CLOCKS_PER_SEC;
	printf("************************************************************\n*\t\t Sequential Access write time\t\t*\n");
	printf("*  Latancy time in msec = %lf\t\t*\n", ((dTotalTime*1000)/(MEGA_BYTE*10)));
	printf("*  Speed of Sequential write in Mb/Sec = %lf\t\t*\n", ((MEGA_BYTE*10)/(dTotalTime)));
	
	/* Random Process */
	dStartTime = clock();
	for(iLoopCounter = 0; iLoopCounter < 10; iLoopCounter++)
	{
		iRandomNum = rand()%MEGA_BYTE;
		memcpy(pcDestinationBuf+(iLoopCounter*MEGA_BYTE)%(BUFSIZE - 1), pcSourceBuf+(iRandomNum%(BUFSIZE -1)), (sizeof(char)*MEGA_BYTE));		

	}
	dEndTime = clock();
	dTotalTime = (double)dEndTime - dStartTime/CLOCKS_PER_SEC;
	printf("************************************************************\n*\t\t Random Access write time\t\t*\n");
	printf("*  Latancy time in msec = %lf\t\t*\n", ((dTotalTime*1000)/(MEGA_BYTE*10)));
	printf("*  Speed of Random write in Mb/Sec = %lf\t\t*\n", ((MEGA_BYTE*10*2)/(dTotalTime)));
}





int main()
{
	int iReadByteSize = 0;
	int iThreadCount = 0;
	char cTerminateChoice;
	pthread_t Thread[2];
	
	while(1)
	{	
		printf("Enter your choice\n");
		printf("1) Bytes_operation\n2) Kilobyte_operation\n3) megabyte_operation\n");
		scanf(" %d", &iReadByteSize);
		
		switch(iReadByteSize)
		{
			case 1:
			{
				int iThreadReturn_1, iThreadReturn_2;
				printf("Inside Byte Read Operation:\n");
				printf("How many thread you want '1' or '2':\n");
				scanf(" %d", &iThreadCount);
				switch(iThreadCount)
				{
					case 1:
						iThreadReturn_1 = pthread_create(&Thread[0], NULL, (void *)memory_banchmark_byte_operation, NULL);
						pthread_join(Thread[0], NULL);
						
						
						if (0 != iThreadReturn_1)
						{
							perror("Status:\n");
							exit(EXIT_FAILURE);
						}
						break;
					case 2:
						iThreadReturn_1 = pthread_create(&Thread[0], NULL, (void *)memory_banchmark_byte_operation, NULL);
						iThreadReturn_2 = pthread_create(&Thread[1], NULL, (void *)memory_banchmark_byte_operation, NULL);
						pthread_join(Thread[0], NULL);
						pthread_join(Thread[1], NULL);
						
						if (0 != iThreadReturn_1 || 0 !=iThreadReturn_2)
						{
							perror("Status:\n");
							exit(EXIT_FAILURE);
						}
						break;
				}
				break;
			}

			case 2:
			{
				int iThreadReturn_1, iThreadReturn_2;
				printf("Inside KiloByte Read Operation:\n");
				printf("How many thread you want '1' or '2':\n");
				scanf(" %d", &iThreadCount);
				switch(iThreadCount)
				{
					case 1:
						iThreadReturn_1 = pthread_create(&Thread[0], NULL, (void *)memory_banchmark_kilobyte_operation, NULL);
						pthread_join(Thread[0], NULL);

						if (0 != iThreadReturn_1)
						{
							perror("Status:\n");
							exit(EXIT_FAILURE);
						}
						break;
					case 2:
						iThreadReturn_1 = pthread_create(&Thread[0], NULL, (void *)memory_banchmark_kilobyte_operation, NULL);
						iThreadReturn_2 = pthread_create(&Thread[1], NULL, (void *)memory_banchmark_kilobyte_operation, NULL);
						pthread_join(Thread[0], NULL);
						pthread_join(Thread[1], NULL);

						if (0 != iThreadReturn_1 || 0 !=iThreadReturn_2)
						{
							perror("Status:\n");
							exit(EXIT_FAILURE);
						}
						break;
				}
				break;
			}
		
			case 3:
			{
				int iThreadReturn_1, iThreadReturn_2;
				printf("Inside MegaByte Read Operation:\n");
				printf("How many thread you want '1' or '2':\n");
				scanf(" %d", &iThreadCount);
				switch(iThreadCount)
				{
					case 1:
						iThreadReturn_1 = pthread_create(&Thread[0], NULL, (void *)memory_banchmark_megabyte_operation, NULL);
						pthread_join(Thread[0], NULL);

						if (0 != iThreadReturn_1)
						{
							perror("Status:\n");
							exit(EXIT_FAILURE);
						}
						break;
					case 2:
						iThreadReturn_1 = pthread_create(&Thread[0], NULL, (void *)memory_banchmark_megabyte_operation, NULL);
						iThreadReturn_2 = pthread_create(&Thread[1], NULL, (void *)memory_banchmark_megabyte_operation, NULL);
						pthread_join(Thread[0], NULL);
						pthread_join(Thread[1], NULL);

						if (0 != iThreadReturn_1 || 0 !=iThreadReturn_2)
						{
							perror("Status:\n");
							exit(EXIT_FAILURE);
						}
						break;
				}
				break;
			}
		}
		printf("Enter your choice for terminate the program:\nYES = 'y'\tNO = 'n'\n");
		scanf(" %c", &cTerminateChoice);
		if('n' == cTerminateChoice)
		{
			break;
		}
	}
	return 0;

}
	

