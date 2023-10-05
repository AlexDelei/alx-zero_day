#include "main.h"
/**
 * get_env - Get the content of a global variable
 * @global_var: Variable to extract from environ
 * Return: Pointer to the content of a variable, or NULL if fails
 */
char *get_env(char *global_var)
{
	int i = 0;
	const char cutter[] = "=";
	char *envdup, *env_tok, *env_tok_dup;

	if (global_var == NULL || environ == NULL)
		return (NULL);
	while (environ[i] != NULL)
	{
		envdup = stringdup(environ[i]);
		env_tok = strtok(envdup, cutter);

		if (stringcmp(env_tok, global_var) == 0)
		{
			env_tok = strtok(NULL, cutter);
			env_tok_dup = stringdup(env_tok);
			free(envdup);
			return (env_tok_dup);
		}
		free(envdup);
		i++;
	}

	return (NULL);
}
