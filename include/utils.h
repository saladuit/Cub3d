
#ifndef UTILS_H
#define UTILS_H

#include <stdbool.h>
#include <stdlib.h>

bool is_valid_character(char c);
bool is_player(char c);
void print_str_table(char **table);
size_t max_col_len(char **map);
size_t row_len(char **map);

#endif
