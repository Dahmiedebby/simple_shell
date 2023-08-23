#include "shell.h"

/**
 * main - this checks the programs
 * @argc: arg count
 * @argv: arg vector
 * @env: number of values received from the command line
 *
 * Return: zero on succes.
 */
int main(int argc, char *argv[], char *env[])
{
	dat_t data_struct = {NULL}, *data = &data_struct;
	char *prompt = "";

	init_data(data, argc, argv, env);

	signal(SIGINT, sh_ctrl_c);

	if (isatty(STDIN_FILENO) && isatty(STDOUT_FILENO) && argc == 1)
	{/* We are in the terminal, interactive mode */
		errno = 2;
		prompt = PROMPT_MSG;
	}
	errno = 0;
	uche(prompt, data);
	return (0);
}

/**
 * sh_ctrl_c - print the prompt in a new line
 * when the signal SIGINT (ctrl + c) is send to the program
 * @UNUSED: see the prototype
 */
void sh_ctrl_c(int opr UNUSED)
{
	sh_print("\n");
	sh_print(PROMPT_MSG);
}

/**
 * init_data - initializes the struct with the data of the program
 * @data: pointer to the structure of data
 * @argv: array of arguments pased to the program execution
 * @env: environ pased to the program execution
 * @argc: number of values received from the command line
 */
void init_data(dat_t *data, int argc, char *argv[], char **env)
{
	int i = 0;

	data->av = argv[0];
	data->lin = NULL;
	data->args = NULL;
	data->counter = 0;
	/* define the file descriptor to be read*/
	if (argc == 1)
		data->fd = STDIN_FILENO;
	else
	{
		data->fd = open(argv[1], O_WRONLY);
		if (data->fd == -1)
		{
			she_print(data->av);
			she_print(": 0: Can't open ");
			she_print(argv[1]);
			she_print("\n");
			exit(127);
		}
	}
	data->toks = NULL;
	data->env = malloc(sizeof(char *) * 50);
	if (env)
	{
		for (; env[i]; i++)
		{
			data->env[i] = _strdup(env[i]);
		}
	}
	data->env[i] = NULL;
	env = data->env;

	data->ls_alias = malloc(sizeof(char *) * 20);
	for (i = 0; i < 20; i++)
	{
		data->ls_alias[i] = NULL;
	}
}
/**
 * uche - infinite loop that shows the prompt
 * @prompt: printed
 * @data: struct to shell data.
 */
void uche(char *prompt, dat_t *data)
{
	int error_code = 0, str_len = 0;

	while (++(data->counter))
	{
		sh_print(prompt);
		error_code = str_len = _getline(data);

		if (error_code == EOF)
		{
			freemor_data(data);
			exit(errno);
		}
		if (str_len >= 1)
		{
			_expalias(data);
			_expvar(data);
			 tokenize(data);
			if (data->toks[0])
			{
				error_code = _execute(data);
				if (error_code != 0)
					sh_printerror(error_code, data);
			}
			free_data(data);
		}
	}
}
