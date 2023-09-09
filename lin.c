#include "main.h"
/**
 *search_path - finds path of file
 *@cmd:command
 *@path:pathfinder
 *Return: NULL
 */
char *search_path(const char *cmd, const char *path)
{
	char *path_copy, *token;
	char path_with_cmd[1024];

	path_copy = strdup(path);
	token = strtok(path_copy, ":");
	while (token != NULL)
	{
		snprintf(path_with_cmd, sizeof(path_with_cmd), "%s/%s", token, cmd);
		if (access(path_with_cmd, X_OK) == 0)
		{
			free(path_copy);
			return (strdup(path_with_cmd));
		}
		token = strtok(NULL, ":");
	}
	free(path_copy);
	return (NULL);
}
/**
 * main - prints users command
 *
 * Return: 0
 */
int main(void)
{
	while (1)
	{
		char *line = NULL, *args[32], *env[] = {NULL}, *token, *path_to_exec, *path;
		size_t len = 0;
		ssize_t read;
		int argCount = 0, status;
		pid_t child_pid;

		printf(":) ");
		fflush(stdout);
		read = getline(&line, &len, stdin);
		if (read == -1)
		{
			perror("getline");
			continue;
		}
		if (line[len - 1] == '\n')
		{
			line[len - 1] = '\0';
		}
		if (strlen(line) == 0)
		{
			free(line);
			continue;
		}
		child_pid = fork();
		if (child_pid == -1)
		{
			perror("fork");
		}
		else if (child_pid == 0)
		{
			token = strtok(line, " \t\n");
			while (token != NULL && argCount < 31)
			{
				args[argCount] = token;
				argCount++;
				token = strtok(NULL, " \t\n");
			}
			args[argCount] = NULL;
			if (strchr(args[0], '/') != NULL)
			{
				if (execve(args[0], args, env) == -1)
				{
					perror(args[0]);
					exit(EXIT_FAILURE);
				}
			}
			else
			{
				path = getenv("PATH");
				if (path == NULL)
				{
					path = "/bin:/usr/bin";
				}
				path_to_exec = search_path(args[0], path);
				if (path_to_exec != NULL)
				{
					if (execve(path_to_exec, args, env) == -1)
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
		else
		{
			waitpid(child_pid, &status, 0);
		}
		free(line);
	}
	return (0);
}
