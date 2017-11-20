/*
** EPITECH PROJECT, 2017
** my_atoi
** File description:
** Convert string into number (int)
*/

int my_atoi(char *str)
{
	int result = 0;
	for (int i = 0; str[i] != 0; i++)
		result = (result * 10) + (str[i] - '0');
	return (result);
}
