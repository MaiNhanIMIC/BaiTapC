#include "SNT.h"

char KiemTra(int So)
{
	for (int i = 2; i < So; i++)
	{
		if (So%i == 0)
			return 0;
	}
	return 1;
}