#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <sys/time.h>
#include <string.h>


void update() {
    printf("\033[H\033[J");
}

void gotoxy(int x,int y) {
    printf("\033[%d;%dH",x,y);
}

int etat_cow (int i){
    if (i%2==0){
        return 0;
    }
    return 1;
}


void affiche_vache(){
	int x = 15;
    int y = 40;
    int etat;
	update();
	for (int i=0; i<40;i++){
        etat = etat_cow(i);
		if ( i >= 5 && i <= 29){
			etat = 1;
			// i++;
			if ( i >= 5 && i <= 8){
				x--;
			}
			else if ( i >= 26 && i <= 29){
				x++;
			}
			else if ( i > 8 && i <24){
				i++;
			}
		}
		gotoxy(16,30);
		printf(" _\n");
		gotoxy(17,30);
		printf("|_|\n");
		gotoxy(18,30);
		printf("|_|\n");
		gotoxy(19,30);
		printf("|_|\n");
	if (etat == 0){
		gotoxy(x,y-i);
		printf("^__^\n");
		gotoxy(x+1,y-i);
        	printf("(00)\\_______\n");
		gotoxy(x+2,y-i);
        	printf("(__)\\       )\\/\\\n");
		gotoxy(x+3,y-i);
		printf("    ||----w |\n");
		gotoxy(x+4,y-i);
		printf("    ||     ||\n");
        }
	else if (etat == 1){
		gotoxy(x,y-i);
		printf("^__^\n");
		gotoxy(x+1,y-i);
        	printf("(00)\\_______   /\n");
		gotoxy(x+2,y-i);
        	printf("(__)\\       )\\/\n");
		gotoxy(x+3,y-i);
		printf("    //----w \\\n");
		gotoxy(x+4,y-i);
                printf("   //        \\\n");
    }
	usleep(250000);
	update();
	}
	gotoxy(x,y-40);
	printf("^__^\n");
	gotoxy(x+1,y-40);
		printf("(--)\\_______\n");
	gotoxy(x+2,y-40);
		printf("(__)\\       )\\/\\\n");
	gotoxy(x+3,y-40);
	printf("    ||----w |\n");
	gotoxy(x+4,y-40);
	printf("    ||     ||\n");
    usleep(500000);
    update();
	gotoxy(x-2,y-40);
	printf("     < Phew! >\n");	
	gotoxy(x-1,y-40);
	printf("      /\n");
	gotoxy(x,y-40);
	printf("^__^\n");
	gotoxy(x+1,y-40);
		printf("(@@)\\_______\n");
	gotoxy(x+2,y-40);
		printf("(__)\\       )\\/\\\n");
	gotoxy(x+3,y-40);
	printf(" U  ||----w |\n");
	gotoxy(x+4,y-40);
	printf("    ||     ||\n");
}


void affiche_toothless(){
    update();
        printf(
"                       _^____^_0_0_\n\
                        s ________3_)\n\
                         |   |\n\
                      _  |   |  _\n\
                       | |   | |\n\
                        \\|   |/            \\__/     /\n\
                    0_   |   |             (oo)____/\n\
                      \\__|   |             (--)    )\n\
                         / /\\\\                //__\\\\\n\
                        C_|  |_3             //    \\\\\n"
            );
	update();
	sleep(1);
	printf(
"                       _^____^_0_0_\n\
                        s ________3_)\n\
                         |   |   \\0\\0\n\
                      _  |   |  _\n\
                       | |   | |\n\
                        \\|   |/            \\__/     /\n\
                    0_   |   |             (oo)____/\n\
                      \\__|   |             (--)    )\n\
                         / /\\\\                //__\\\\\n\
                        C_|  |_3             //    \\\\\n"
            );
	update();
	sleep(1);
	printf(
"                       _^____^_0_0_\n\
                        s ________3_)\n\
                         |   |   \\0\\0\n\
                      _  |   |  _ \\0\\0\\0\\0\n\
                       | |   | |\n\
                        \\|   |/            \\__/     /\n\
                    0_   |   |             (oo)____/\n\
                      \\__|   |             (--)    )\n\
                         / /\\\\                //__\\\\\n\
                        C_|  |_3             //    \\\\\n"
            );
	update();
	sleep(1);
	printf(
"                       _^____^_0_0_\n\
                        s ________3_)\n\
                         |   |   \\0\\0\n\
                      _  |   |  _ \\0\\0\\0\\0\n\
                       | |   | |   \\0\\0\\0\\0\\0\n\
                        \\|   |/            \\__/     /\n\
                    0_   |   |             (xx)____/\n\
                      \\__|   |             (--)    )\n\
                         / /\\\\      Ack!__/   //__\\\\\n\
                        C_|  |_3             //    \\\\\n"
            );
	update();
	sleep(1);
    for (int i = 0; i<5;i++){
        update();
        printf(
"                        _^____^_0_0_\n\
                         s ________3_)\n\
                          |   |\n\
                       _  |   |  _\n\
                        | |   | |\n\
                         \\|   |/\n\
                     0_   |   |\n\
                       \\__|   |\n\
                          / /\\\\\n\
                         C_|  |_3\n"
            );
        update();
        usleep(250000);
        printf(
"                         ^____^\n\
                         s\\   \\\n\
                         | 0   0\n\
                         |  (-3-)\n\
                      __ |   | __\n\
                        \\|   |/\n\
                    0_   |   |\n\
                      \\__|   |\n\
                         // \\\\\n\
                        C_| |_3\n"
            );
        update();
        usleep(250000);
        printf(
"                         ^___^\n\
                         |   |\n\
                         0-_-0\n\
                       | |   | |\n\
                       | |   | |\n\
                        \\|   |/\n\
                         |   |  0\n\
                         |   |_/\n\
                         |   |\n\
                         || ||\n"
            );
        update();
        usleep(250000);
            printf(
"                       ^____^\n\
                       /   /s\n\
                      0   0 |\n\
                     (-c-)  |\n\
                     __ |   | __\n\
                       \\|   |/\n\
                        |   |   _0\n\
                        |   |__/\n\
                        // \\\\\n\
                       C_| |_3\n"
            );
        update();
        usleep(250000);
        printf(
"                 _0_0_^____^_\n\
                (_c________ s\n\
                       |   |\n\
                    _  |   |  _\n\
                     | |   | |\n\
                      \\|   |/\n\
                       |   |   _0\n\
                       |   |__/\n\
                       // \\\\\n\
                      C_| |_3\n"
            );
        update();
        usleep(250000);
            printf(
"                       ^____^\n\
                       /   /s\n\
                      0   0 |\n\
                     (-c-)  |\n\
                     __ |   | __\n\
                       \\|   |/\n\
                        |   |   _0\n\
                        |   |__/\n\
                        // \\\\\n\
                       C_| |_3\n"
            );
        update();
        usleep(250000);
        printf(
"                         ^___^\n\
                         |   |\n\
                         0-_-0\n\
                       | |   | |\n\
                       | |   | |\n\
                        \\|   |/\n\
                         |   |  0\n\
                         |   |_/\n\
                         |   |\n\
                         || ||\n"
            );
        update();
        usleep(250000);
        printf(
"                         ^____^\n\
                         s\\   \\\n\
                         | 0   0\n\
                         |  (-3-)\n\
                      __ |   | __\n\
                        \\|   |/\n\
                    0_   |   |\n\
                      \\__|   |\n\
                         // \\\\\n\
                        C_| |_3\n"
            );
        update();
        usleep(250000);
        printf(
"                        _^____^_0_0_\n\
                         s ________3_)\n\
                          |   |\n\
                       _  |   |  _\n\
                        | |   | |\n\
                         \\|   |/\n\
                     0_   |   |\n\
                       \\__|   |\n\
                          / /\\\\\n\
                         C_|  |_3\n"
            );
    }   
    
}


int main(int argc, char* argv[]) {
    if (argc != 2) {
        printf("Invalid arguments");
        return 1;
    }
    if (strcmp(argv[1],"-v")==0){
        affiche_vache();
    }
    else if (strcmp(argv[1],"-t")==0){
        affiche_toothless();
    }
    else {
        printf("Invalid arguments");
        return 1;
    }
    return 0;
}

