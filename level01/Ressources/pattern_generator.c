#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int hex_to_ascii(const char *hex_sequence, char *ascii_sequence)
{
    size_t len = strlen(hex_sequence);
    size_t ascii_len = len / 2;

    for (size_t i = 0; i < ascii_len; ++i)
        sscanf(hex_sequence + len - 2 * (i + 1), "%2hhx", &ascii_sequence[i]);

    ascii_sequence[ascii_len] = '\0';
	if (ascii_sequence[0] == '\0')
		return -1;
	return 0;
}

void generate_pattern(char *pattern, int taille)
{
	int count = 0;

    for (char i = '0'; i <= '9'; i++)
	{
		for (char j = 'A'; j <= 'Z'; j++)
		{
        	pattern[count++] = j;
			pattern[count++] = i;
			if (count >= taille)
			{
				pattern[taille] = '\0';
				return;
			}

		}
    }
	pattern[taille] = '\0';
}

int main() {
    int taille = 0;
    char pattern[600] = {0};
	char toFindHexa[600] = {0};
	char toFindString[600] = {0};
	char *pos = NULL;

	printf("===> Pattern Genrator <===\n\n");
	while(1)
	{
		printf("Taille du pattern => ");
		if (scanf("%d", &taille) > 0)
		{
			if (taille > 600 || taille < 1)
				printf("La taille doit etre compris entre 1 et 600\n");
			else
				break ;
		}
		else
			return -1;
	}
    generate_pattern(pattern, taille);
    printf("\n=> Pattern <=\n\n%s\n", pattern);
	printf("\nValeur registre (0x........) => ");
	scanf("%s", toFindHexa);
	if (hex_to_ascii(toFindHexa, toFindString) == -1)
		return (printf("Offset introuvable\n"), -1);
	if ((pos = strstr(pattern, toFindString)) != NULL)
		printf("\n=> Offset <=\n\n     %ld\n\n", pos - pattern);
	else
		printf("Offset introuvable\n");
    return 0;
}