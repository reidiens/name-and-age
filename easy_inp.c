#include "easy_inp.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

const int STR_LEN_HIGH = 512;
const int STR_LEN_LOW = 128;

int gstrunc(char* str) {
	fgets(str, STR_LEN_HIGH, stdin);
	
	// if last character in string is nl, replace nl with EOF
	if ((strlen(str) > 1) && (str[strlen(str) - 1] == '\n')) {
		str[strlen(str) - 1] = '\0';
		
		// if last character in string is blank, replace blank with EOF
		if (str[strlen(str) - 1] == 0x20)
			str[strlen(str) - 1] = '\0';
		return 1;
	}
	
	// if nothing was input but a nl, return 0
	else if (strlen(str) <= 1)
		return 0;
}


int gint(int* num_int) {
	char* num_hold = (char*)malloc(STR_LEN_LOW);
	fgets(num_hold, STR_LEN_LOW, stdin);
	
	// if something was inputted, check if it was integer 
	if (strlen(num_hold) > 1) {

		// if input was integer, return 1. if not, return 0
		switch (sscanf(num_hold, "%d", num_int)) {
			case 1 :
				return 1;
				break;

			default :
				return 0;
		}
	}
	
	// if nothing was input, return -1
	else {
		return -1;
	}
	free(num_hold);
}
