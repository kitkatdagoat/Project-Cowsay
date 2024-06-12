#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void affiche_vache(char *e, char *t, char *tail){
	printf(
"     ^__^\n\
     (%s)\\_______\n\
     (__)\\       )%s\n\
      %s  ||----w |\n\
         ||     ||\n",e,tail,t);
}

int strVint(char* c) {
    int len = strlen(c);
	int result =0;
    for (int i = 0; i < len; i++){
        result = result * 10 + ( c[i] - '0' );
    }
    return result;
}

int main(int argc, char**argv){
	char *eyes=malloc(10);
	char *tongue=malloc(10);
	char *tail=malloc(20);
	strcpy(eyes,"00");
	strcpy(tongue," ");
	strcpy(tail,"\\/\\");
	if (argc>=2){
		for (int i=1; i < argc; i++){
			if ((strcmp(argv[i], "-e")==0 || strcmp(argv[i], "--eyes")==0) && strcmp(eyes,"xx")!=0){
				strcpy(eyes,argv[i+1]);
			}
			else if (strcmp(argv[i], "-d")==0){
                strcpy(eyes,"xx");
				strcpy(tongue,"U");
			}
			else if (strcmp(argv[i], "-t")==0){
                strcpy(eyes,"--");
			}
			else if (strcmp(argv[i], "-b")==0){
                strcpy(eyes,"@@");
            }
			else if (strcmp(argv[i], "-s")==0){
                strcpy(eyes,"**");
            }
			else if (strcmp(argv[i], "-g")==0){
                strcpy(eyes,"$$");
            }
			else if (strcmp(argv[i], "-T")==0){
				tongue=argv[i+1];
			}
			else if (strcmp(argv[i], "--t")==0){
				int n = strVint(argv[i+1]);
				for (int j=0; j < n; j++){
					if (j%2==0){
						tail[j+1]='/';
					}
					else {
						tail[j+1]='\\';
					}
				}
				tail[n+1]='\0';
			}
		}
	}
	affiche_vache(eyes,tongue, tail);
	return 0;
}
