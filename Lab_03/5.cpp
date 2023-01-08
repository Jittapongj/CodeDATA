
#include <stdio.h>
#include <string.h>

struct worldcub {
    char team[20];
	char score[20];
	char winner[40];	
};//end loop
void text(struct worldcub *wc);
int main(){
	struct  worldcub w;
	text(&w);
	printf("%s\n ",w.team);
	printf("Score %s\n",w.score);
	printf("The winner is %s",w.winner);
}
void text(struct worldcub *wc) {
	printf("Competing teams :");
	gets(wc->team);
	printf("Score :");
	gets(wc->score);
	printf("Who is winner :");
	gets(wc->winner);
}