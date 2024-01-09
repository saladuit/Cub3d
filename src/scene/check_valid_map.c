#include "error.h"
#include "scene.h"
#include "utils.h"

void check_valid_map(const char *string)
{
	size_t i = 0;
	size_t len = 0;
	bool found_player = false;

	while (string[i])
	{
		if (string[i] == '\n')
		{
			if (len <= 1)
				user_error_and_exit("Empty line in map");
			len = 0;
		}
		else if (is_valid_character(string[i]) == false)
		{
			user_error_and_exit("Invalid character in map");
		}
		else if (is_player(string[i]) == true)
		{
			if (found_player == true)
				user_error_and_exit("too many players in map");
			found_player = true;
		}
		len++;
		i++;
	}
	if (found_player == false)
		user_error_and_exit("No player in map");
}
