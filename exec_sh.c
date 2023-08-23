#include "shell.h"
/**
 * _execute - executes a cmd with its entire path variables.
 * @data: a pointer to the program's data
 * Return: If sucess returns zero, otherwise, return -1.
 */
int _execute(dat_t *data)
{
	int ret = 0, status;
	pid_t pid;

	/* check for program in built ins */
	ret = bn_list(data);
	if (ret != -1)/* if program was found in built ins */
		return (ret);

	/* check for program file system */
	ret = search_prog(data);
	if (ret)
	{/* if program not found */
		return (ret);
	}
	else
	{/* if program was found */
		pid = fork(); /* create a child process */
		if (pid == -1)
		{ /* if the fork call failed */
			perror(data->args);
			exit(EXIT_FAILURE);
		}
		if (pid == 0)
		{
			ret = execve(data->toks[0], data->toks, data->env);
			if (ret == -1)
				perror(data->args), exit(EXIT_FAILURE);
		}
		else
		{/* I am the father, I wait and check the exit status of the child */
			wait(&status);
			if (WIFEXITED(status))
				errno = WEXITSTATUS(status);
			else if (WIFSIGNALED(status))
				errno = 128 + WTERMSIG(status);
		}
	}
	return (0);
}
