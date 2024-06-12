#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <unistd.h>

#define NBMOTSMAX 1024

void update() {
    printf("\033[H\033[J");
}

void affiche_vache(char* phrase, char tongue){
	char signal[strlen(phrase)+1];
	for (int i = 0; phrase[i] != '\0'; i++){
		signal[i]= '-';
	}
	signal[strlen(phrase)] = '\0';
	if (isspace(tongue)){ tongue = ' ';}
        printf(
" %s\n\
<%s>\n\
 %s\n\
	\\    ^__^\n\
	 \\   (oo)\\_______\n\
	     (__)\\       )\\/\\\n\
	      %c  ||----w |\n\
	         ||     ||\n",signal, phrase, signal, tongue);
}

// int long_fich(FILE *f){ // Cette fonction renvoie le nombre de mots dans un fichier
// 	int count = 0;
// 	char c;
// 	while(fscanf(f, "%c", &c) != EOF){
//         count++;}
// 	fseek(f, 0, SEEK_SET);
// 	return count; 
// }

void readcow (FILE *f){ // Cette fonction affiche une vache qui lit un fichier
	// update();
	char c;
	char s[NBMOTSMAX];
	int i = 0;
	s[i++] = ' ';
	fscanf(f, "%c", &c) ;
	s[i++]=c;
	fscanf(f, "%c", &c) ;
	while (!feof(f)){
		update();
		s[i]=' ';
		s[i+1]='\0';
		affiche_vache(s,c);	
		sleep(1);
		s[i++]=c;
		fscanf(f, "%c", &c) ;
	}
}

void read_stdin(){ // Cette fonction affiche une vache qui lit l'entree standard stdin
	char c;
	char s[NBMOTSMAX];
	int i = 0;
	s[i++] = ' ';
	scanf("%c",&c);
	update();
	while(c !=EOF){
		if (c == '\n' ){
			i=0;
			s[i++] =' ';
		}
		else{
			s[i++]=c;
		}
		s[i]=' ';
		s[i+1]='\0';
		scanf("%c",&c);
		affiche_vache(s,c);
		sleep(1);
		if (c!='\n'){
			update();}	
	}
}

int main(int argc, char* argv[]){
	FILE *f;
	if (argc > 2){
		printf("Invalid arguments");
		return 1;
	}
	else if (argc == 2){
		f = fopen(argv[1],"r");
		if (f == NULL){
			printf("%s n'a pas pu être ouvert en lecture\n", argv[1]);
			return 1;
		}
		readcow(f);
		fclose(f);
	}

	else{
		read_stdin();
	}
    return 0;
}
