#include "main.h"
/**
 * execute_command - execte function
 * @command:command
 */
extern char **environ;
void execute_command(const char *command)
{
	char *args[32], *path_to_exec, *path, *token, **env;
	int argCount = 0;

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
	else if (argCount == 1 && strcmp(args[0], "alias") == 0)
		list_aliases();
	else if (argCount >= 2 && strcmp(args[0], "alias") == 0)
		define_aliases(argCount, args);
	if (strchr(args[0], '/') != NULL)
	{
		if (execve(args[0], args, NULL) == -1)
		{
			perror(args[0]);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		path = getenv("PATH");
		if (path == NULL)
			path = "/bin:/usr/bin"; /*Default PATH if not set*/
		path_to_exec = search_path(args[0], path);
		if (path_to_exec != NULL)
		{
			if (execve(path_to_exec, args, NULL) == -1)
			{
				perror(args[0]);
				free(path_to_exec);
				exit(EXIT_FAILURE);
			}
			free(path_to_exec);
		}
		else
		{
			fprintf(stderr, "%s: command not found\n", args[0]);
			exit(EXIT_FAILURE);
		}
	}
}
