#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "shift.h"

char *shift_left(char *string)
{
	if(strlen(string) == 1)
	{
		//nothing to shift
		return string;
	}
	
	char temp;
	for(int i=0; i< (int) strlen(string)-1; i++)
	{
		temp = string[i];
		string[i] = string[i + 1];
		string[i + 1] = temp;
	}
		
	return string;
}

