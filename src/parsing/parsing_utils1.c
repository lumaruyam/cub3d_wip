#include "cub3d.h"

int	is_void(char c)
{
	return (c == ' ' || c == '\t' || c == '\r' || c == '\v'
		|| c == '\f' || c == '\0' || c == '\n');
}
