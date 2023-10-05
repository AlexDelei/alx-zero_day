#include "main.h"
/**
 * exec - Executes a command and waits for the child process
 * @arguments: Array of inputs by the user
 * Return: Exit status of the executed command
 */
int exec(char **arguments)
{
	pid_t pid;
	int exec_status, status = 0;

	pid = fork();

	if (pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0) /*Child process*/
	{
	exec_status = execve(arguments[0], arguments, environ);
	if (exec_status == -1)
	{
		perror("hsh");
		exit(126);
	}
	exit(0);
	}
	else /* Parent process*/
	{
		waitpid(pid, &status, 0);
		return (WEXITSTATUS(status));
	}
}
