int _strlen(char *str)
{
	int len = 0;

	while (*str++)
		len++;

	return (len);
}
