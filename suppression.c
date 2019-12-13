#include <string.h>
#include "suppression.h"
void validsuppression(int v, char Validation[50])
{
	if (v==1)
	{
		strcpy(Validation,"Suppression non établie ! ");
	}
	else
	{
		strcpy(Validation,"Suppression réussite ! ");
	}
}
