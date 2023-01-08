#include <stdio.h>
#include <string.h>

struct Car {
	char model[20];
	int year;
	int price;
};//end loop
void addNum( struct Car c );
int main(){
	struct Car c1,*c;
	strcpy (c1.model,"Tesla Model Y");
    c1.year = 2022;
	c1.price = 2990000;
	c = &c1;
	addNum(c1);
	return 0;
}//end loop
void addNum(struct Car c) {
	printf(" model: %s\n ",c.model);
	printf("year : %d\n ",c.year);
	printf("price: %d\n",c.price);
}//end loop