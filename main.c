#include<string.h>
#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include<funktionen.h>
#include<math.h>

const char VERSIONSNR[] = "0.1";


int main(int argc, char* argv[]){
	int option, bereich=-1, anzahl=-1;
	char * endptr;
	while((option = getopt(argc, argv, "hvp:n:"))!=-1)
	switch(option)
	{
		case 'h':
			printf("Mit -p wird die Phase angegeben, mit -n die Anzahl samples\n");
			exit(0);
		case 'v':
			printf("Version %s\n", VERSIONSNR);
			exit(0);
		case 'p':
			printf("Phase %s\n", optarg);
			bereich = strtol(optarg, &endptr, 10);
			break;
		case 'n':
			printf("Anzahl Samples %s\n", optarg);
			anzahl = strtol(optarg, &endptr, 10);
			break;
		default:
			printf("Wrong Usage. Please try -h\n");
			exit(0);
	}
	if ((anzahl == -1) || (bereich == -1)){
		printf("Anzahl Samples und Phase -n und -p sind verpflichtend\n");
		exit(1);
	}

	const int tableSize = anzahl;
	const char *fileName = "wertetabelle.txt";

	FILE *file;
	file = fopen(fileName, "w");
	if (file == NULL){
		printf("unable to open file\n");
		exit(2);
	}
	for (int x=0; x < tableSize; x++){
		float t = x*bereich*M_PI/tableSize;
		fprintf(file, "%i\n", (int)(rectfct(t)+sinusfct(t)+triangfct(t)+sawtooth(t)));
	}
	fclose(file);
	return 0;
}

