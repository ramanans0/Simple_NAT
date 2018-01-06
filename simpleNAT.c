// Suprith Ramanan

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXLEN 100

int main(int argc, char **argv){
	char ipstr[MAXLEN];
	char natstr[MAXLEN];
	char outstr[MAXLEN];
        if (argc > 3 || argc < 3){
		printf("Provide 2 file inputs\n");
                return -1;
	}
        FILE *ff, *fn, *fo;
	fn = fopen(argv[1], "r"); //argv[1] is NAT 
	ff = fopen(argv[2], "r"); //argv[2] is FLOW
	fo = fopen("OUTPUT", "w");
	if (fn == NULL || ff == NULL){
		printf("Error: unable to open file(s)\n");
		return -1;
	}
	int i = 0;
	int j = 0;
	int strlen = 0;
	int set = 0;
	int done = 0;
	int k = 0;
	while(fgets(ipstr, MAXLEN, ff)){
		printf(ipstr);
		i = 0;
		strlen = 0;
		while(ipstr[i] != NULL){
			printf("%c", ipstr[i]);
			i++;
			strlen++;
		}
		strlen = strlen - 2;
		printf("%d\n", strlen);
		j = 0;
		done = 0;
		while(fgets(natstr, MAXLEN, fn)){
			j = 0;
			set = 0;
			printf(natstr);	
			while (ipstr[j] != NULL && natstr[j] != ","){
				printf("%d\n", j);
				if(ipstr[j] != natstr[j]){
					set = 1;
					printf("err\n");
				}
				printf("%c\n", natstr[j]);
				j++;
			}
		//	printf("test");
			if(set == 0){
				k = 0;
				
				while(natstr[k] != ","){
				//	k++;
					outstr[k] = natstr[k];					
					k++;
				}
				outstr[k] = " ";
				k++;
				outstr[k] = "-";
                                k++;
				outstr[k] = ">";
                                k++;
				outstr[k] = " ";
                                k++;
                                while(natstr[k] != NULL){
                                	//k++;
                                        outstr[k] = natstr[k-4];
                                        k++;
                                }
				outstr[k] = "\n";
				fputs(outstr, fo);
				printf("%c", natstr[k]);
				done = 1;			
			}
			
				
			memset(outstr, 0, MAXLEN);
		}
		strlen = 0;
		fseek(fn, 0, SEEK_SET);		
	}
	fclose(ff);
	fclose(fn);
	fclose(fo);
        return 0;
}

