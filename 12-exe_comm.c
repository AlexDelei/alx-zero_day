#include "main.h"
/**
 * execute_command - execte function
 * @command:command
 */
void execute_command(const char *command)
{
	char *args[32], *token, **env;
	int argCount = 0, success = 1;

	env = environ;
	token = strtok((char *)command, " \t\n");
	while (token != NULL && argCount < 31)
	{
		args[argCount] = token;
		argCount++;
		token = strtok(NULL, " \t\n");
	}
	args[argCount] = NULL;
	if (argCount == 1 && strcmp(args[0], "exit") == 0)
	{
		exit(0);
	}
	else if (argCount == 1 && strcmp(args[0], "env") == 0)
	{
		while (*env)
		{
			printf("%s\n", *env);
			env++;
		}
	}
	else if (argCount > 0)
	{
		if (strcmp(args[argCount - 1], "&&") == 0)
		{
			args[argCount - 1] = NULL;
			if (success)
			{
				success = execute_single_command(args);
			}
		}
		else if (strcmp(args[argCount - 1], "||") == 0)
		{
			args[argCount - 1] = NULL;
			if (!success)
			{
				success = execute_single_command(args);
			}
		}
		else
			success = execute_single_command(args);
	}
}
