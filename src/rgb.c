#include "rgb.h"
#include "error.h"
#include "libft.h"

static void values_to_rgb(int *values, t_rgb *rgb)
{
	if (values[0] < 0 || values[0] > 255 || values[1] < 0 || values[1] > 255 ||
		values[2] < 0 || values[2] > 255)
		user_error_and_exit("RGB values out of range");
	rgb->r = (uint8_t)values[0];
	rgb->g = (uint8_t)values[1];
	rgb->b = (uint8_t)values[2];
}

void string_to_rgb(const char *string, t_rgb *rgb)
{
	int values[3] = {0};
	int char_count = 0;
	int i = 0;

	while (*string != '\0' && i < 3)
	{
		while (*string >= '0' && *string <= '9')
		{
			if (char_count > 3)
				user_error_and_exit("RGB values out of range");
			values[i] = values[i] * 10 + (*string - '0');
			++string;
			char_count++;
		}
		char_count = 0;
		if (*string != '\0' && *string != ',')
			user_error_and_exit("Unexpected character in RGB values");
		if (*string == ',')
			++string;
		++i;
	}
	if (i != 3 || *string != '\0')
		user_error_and_exit("Format error in RGB values");
	values_to_rgb(values, rgb);
}
