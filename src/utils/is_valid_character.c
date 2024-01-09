
#include "utils.h"

bool is_valid_character(char c)
{
	if (c == ' ' || c == '0' || c == '1' || c == 'N' || c == 'S' || c == 'E' ||
		c == 'W')
		return (true);
	return (false);
}
