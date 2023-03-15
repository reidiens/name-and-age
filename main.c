#include "easy_inp.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	system("clear");
	char* firstn = (char*)malloc(STR_LEN_HIGH);
	char* fulln = (char*)malloc(STR_LEN_HIGH);
	char* lastn = (char*)malloc(STR_LEN_HIGH);
	int age;
	printf("What's your name?\n> ");
	strRes:
	switch (gstrunc(fulln)) {
		case 1 :
			sscanf(fulln, "%s %[^\n]s", firstn, lastn);
			firstn = realloc(firstn, strlen(firstn));
			lastn = realloc(lastn, strlen(lastn));
			free(fulln);
			printf("\nHow old are you, %s?\n> ", firstn);
			break;

		default : 
			printf("Maybe try actually typing something, yeah?\n> ");
			goto strRes;
	}

	intRes:
	switch (gint(&age)) {
		case 1 :
			printf("\nWow! You're %d years old!\n",age);
			break;

		case 0 :
			printf("There was an input error!\nMaybe try putting in a number this time?\n> ");
			goto intRes;
			break;

		default :
			printf("Maybe try typing something this time, huh?\n> ");
			goto intRes;
	}

	printf("\n\nSo,your first name is %s, and your last name is %s.\nYou're %d years old.\n", firstn, lastn, age);
	free(lastn); free(firstn);	

}
