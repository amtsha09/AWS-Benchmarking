#include <stdio.h>
#include <pthread.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define BYTE 1
#define ZERO 0

char *pcBuffer = NULL;
FILE *fp;
double Start_t, End_t, Total_t;


void *disk_banchmark_read_byte(void)
{

	int iStartLoop;
	int iFileOperationRet = ZERO;
	int iRandomNum = ZERO;
	int j;
/* Allocated the memory to a buffer */
	pcBuffer = (char *)malloc(BYTE * sizeof(char ));
	memset(pcBuffer, '\0', sizeof(pcBuffer));
/* open a file */
	fp = fopen("myfile.txt","a+");
	if(NULL == fp)
	{
		printf("file is not present:\n");
		exit(EXIT_FAILURE);
	}
/************************************************************* Sequential Access *************************************************/
	{	
		char c;
/* Start time of read proess ****************************************/
		Start_t = clock();
		for(iStartLoop = 0; iStartLoop < BYTE; iStartLoop++)
		{
			c = fgetc(fp);	
			*(pcBuffer + iStartLoop) = c;
		}
/* End time of read process */
		End_t = clock();	
/* total time for read operation */
		Total_t = (double)End_t-Start_t/CLOCKS_PER_SEC;
		printf("************************************************************\n*\t\t Sequential Access read time\t\t*\n");
		printf("*  Latancy time in msec = %lf\t\t*\n", (Total_t*1000)/((BYTE*4)+1));
		printf("*  Speed of Sequential read in Mb/Sec = %lf\t\t*\n", ((BYTE*4)+1)/(Total_t));
		
/* Start time of write proess *****************************************/
		fseek(fp, 0L, SEEK_END);
		Start_t = clock();
		for(iStartLoop = 0; iStartLoop < BYTE; iStartLoop++)
		{
				c = *(pcBuffer + iStartLoop);
				fputc(c ,fp);
		}
/* End time of read process */
		End_t = clock();        

/* total time for write operation */
		Total_t = (double)End_t-Start_t/CLOCKS_PER_SEC;
		printf("************************************************************\n*\t\t Sequential Access write time\t\t*\n");
		printf("*  Latancy time in msec = %lf\t\t*\n", (Total_t*1000)/((BYTE*4)+1));
		printf("*  Speed of Sequential write in Mb/Sec = %lf\t\t*\n", ((BYTE*4)+1)/(Total_t));
	}

/************************************************************ Random Access **************************************************************8*/
	{
		int SizeOfFile = 0;
		char c;
/* find the size of a file */
		fseek(fp, 0L, SEEK_END);
		SizeOfFile = ftell(fp);
		
/* set to again previous position */
		fseek(fp, 0L, SEEK_SET);

/* clear the buffer for new data for random process */
		memset(pcBuffer, '\0', sizeof(pcBuffer));
		
/* Start time of read proess ************************************************/
		Start_t = clock();
		for(iStartLoop = 0; iStartLoop < BYTE; iStartLoop++)
		{

			iRandomNum = rand()%BYTE;
			fseek (fp, iRandomNum, SEEK_SET);
			c = fgetc(fp);
			*(pcBuffer + iStartLoop) = c;
			
		}
/* End time of read process */
		End_t = clock();

/* total time for read operation */
		Total_t = (double)End_t-Start_t/CLOCKS_PER_SEC;

		printf("************************************************************\n*\t\t Random Access read time\t\t*\n");
		printf("*  Latancy time in msec = %lf\t\t*\n", (Total_t*1000)/((BYTE*6)+1));
		printf("*  Speed of Random read in Mb/Sec = %lf\t\t*\n", ((BYTE*6)+1)/(Total_t));
	
/* write operation for random access ****************************************/
		Start_t = clock();
                for(iStartLoop = 0; iStartLoop < BYTE; iStartLoop++)
                {

                        iRandomNum = rand()%BYTE;
			fseek (fp, iRandomNum, SEEK_SET);
			c = *(pcBuffer + iStartLoop);
			fputc(c,fp);
                }
/* End time of read process */
                End_t = clock();

/* total time for read operation */
                Total_t = (double)End_t-Start_t/CLOCKS_PER_SEC;
                printf("************************************************************\n*\t\t Random Access write time\t\t*\n");
		printf("*  Latancy time in msec = %lf\t\t*\n", (Total_t*1000)/((BYTE*6)+1));
		printf("*  Speed of Random write in Mb/Sec = %lf\t\t*\n", ((BYTE*6)+1)/(Total_t));
	}
}



int main()
{

	pthread_t Thread[2];
	int iChoice, iThreadReturn_1, iThreadReturn_2;
	char cTerminateChoice;
	
	
	while(1)
	{
		printf("Enter your choice for thread:\n");
		printf("1)Press 1 for number of thread is one\n2)Press 2 for number of thread two:\n");
		scanf(" %d", &iChoice);
		switch (iChoice)
		{
			case 1:
				iThreadReturn_1 = pthread_create(&Thread[0], NULL, (void *)disk_banchmark_read_byte, NULL);
				if(0 != iThreadReturn_1)
				{
					perror("Status:\n");
					exit(EXIT_FAILURE);
				}
				pthread_join(Thread[0], NULL);
				break;
			case 2:
					
				iThreadReturn_1 = pthread_create(&Thread[0], NULL, (void *)disk_banchmark_read_byte, NULL);
				iThreadReturn_2 = pthread_create(&Thread[1], NULL, (void *)disk_banchmark_read_byte, NULL);
				
				if(0 != iThreadReturn_1 || 0 != iThreadReturn_2)
				{
					perror("Status:\n");
					exit(EXIT_FAILURE);
				}
				pthread_join(Thread[0], NULL);
				pthread_join(Thread[1], NULL);
				break;

			default:
				break;
		}
		printf("if you want to continue press 'y' else 'n':\n");
		scanf(" %c", &cTerminateChoice);
		if('n' == cTerminateChoice)
		{
			break;
		}
	}
	free(pcBuffer);
	return 0;	
}
