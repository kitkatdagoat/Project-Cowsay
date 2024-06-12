#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define BYEBYELIFE 0
#define LIFESUCKS 1
#define LIFEROCKS 2

int stock = 5;
int fitness = 5;

void affiche_vache(int etat){
	char e[3] = "00";
    char t[3] = " ";
    char words[50];  
    char signal[50];
	if (etat==BYEBYELIFE){
		strcpy(e,"xx");
		strcpy(t, "U");
		strcpy(words,"Je suis MORT!!!");
	}
	else if (etat==LIFESUCKS){
		strcpy(e,"@@");
		strcpy(words,"Je suis pas bon!");
	}
	else if (etat==LIFEROCKS){
		strcpy(words,"Let's GOOOOO!!!!");
	}
	for (int i=0; i<strlen(words)+2; i++){
		signal[i]='-';
	}
        printf(
" %s\n\
< %s >\n\
 %s\n\
	\\    ^__^\n\
	 \\   (%s)\\_______\n\
	     (__)\\       )\\/\\\n\
	      %s  ||----w |\n\
	         ||     ||\n",signal, words, signal, e, t);
}

int stock_update(int lunchfood){
	time_t t;
	srand((unsigned) time(&t));
	int crop;
	crop = rand() % 7;
	crop -= 3;
	while (((stock - lunchfood)+crop > 10) || ((stock - lunchfood)+crop < 0)){
		crop = rand() % 7;
        	crop -= 3;
	}
	return (stock - lunchfood)+crop;;
}

int fitness_update(int lunchfood){
        time_t t;
        srand((unsigned) time(&t));
        int digestion;
        digestion = rand() % 4;
        digestion = -digestion;
        fitness = (fitness+lunchfood)+digestion;
        if (fitness > 10) {
            fitness=10;
        }
        else if (fitness < 0){
            fitness = 0;
        }
        return fitness;;
}


int etat_vache(int fitness){
	if (fitness == 0 || fitness == 10){
		return BYEBYELIFE;
	}
	else if ((fitness >=1 && fitness <=3) || (fitness >=7 && fitness <= 9)){
		return LIFESUCKS;
	}
	//else if ((fitness >=4 && fitness <= 6)){
	return LIFEROCKS;
	//}
}


void update () { printf ("\033[H\033[J");}
int main(){
	int time = 0;
	int etat;
	int lunchfood;
	etat = etat_vache(fitness);
	while (etat != BYEBYELIFE){
		update();
		affiche_vache(etat);
		//printf("Fitness: %d\n", fitness);
		printf("Stock: %d\n", stock);
		printf("Nourriture? (<=%d) ", stock);
		scanf("%d", &lunchfood);
		while (lunchfood > stock || lunchfood <0 ){
			printf("Veuillez retaper, svp ");
			scanf("%d", &lunchfood);
		}
		fitness = fitness_update(lunchfood);
		stock = stock_update(lunchfood);
		etat = etat_vache(fitness);
		time++;
	}
	affiche_vache(etat);
	printf("La vache a %d ans", time);
	return 0;
}
