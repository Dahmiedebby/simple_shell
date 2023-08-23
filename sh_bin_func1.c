#include "shell.h"

/**
 * bn_exit - exit the program with the status
 * @data: struct for the program's data
 * Return: 0 if sucess, or other number if its declared in the args
 */
int bn_exit(dat_t *data)
{
	int i;

	if (data->toks[1] != NULL)
	{
		for (i = 0; data->toks[1][i]; i++)
			if ((data->toks[1][i] < '0' || data->toks[1][i] > '9')
				&& data->toks[1][i] != '+')
			{
				errno = 2;
				return (2);
			}
		errno = _atoi(data->toks[1]);
	}
	freemor_data(data);
	exit(errno);
}

/**
 * bn_cd - change the current directory
 * @data: struct for the program's data
 * Return: 0 if sucess, or other number if its declared in the args
 */
int bn_cd(dat_t *data)
{
	char *_dirhom = _envpath("HOME", data), *_dirold = NULL;
	char _olddir[128] = {0};
	int errcode = 0;

	if (data->toks[1])
	{
		if (_strncmp(data->toks[1], "-", 0))
		{
			_dirold = _envpath("OLDPWD", data);
			if (_dirold)
				errcode = _setdir(data, _dirold);
			sh_print(_envpath("PWD", data));
			sh_print("\n");

			return (errcode);
		}
		else
		{
			return (_setdir(data, data->toks[1]));
		}
	}
	else
	{
		if (!_dirhom)
			_dirhom = getcwd(_olddir, 128);

		return (_setdir(data, _dirhom));
	}
	return (0);
}

/**
 * _setdir - set the work directory
 * @data: struct for the program's data
 * @nw_dir: path to be set as work directory
 * Return: 0 (sucess), or other number if its declared in the args
 */
int _setdir(dat_t *data, char *nw_dir)
{
	char s_olddir[156] = {0};
	int s_errcode = 0;

	getcwd(s_olddir, 156);

	if (!_strncmp(s_olddir, nw_dir, 0))
	{
		s_errcode = chdir(nw_dir);
		if (s_errcode == -1)
		{
			errno = 2;
			return (3);
		}
		_envsetpath("PWD", nw_dir, data);
	}
	_envsetpath("OLDPWD", s_olddir, data);
	return (0);
}

/**
 * bn_help - shows the env where the shell runs
 * @data: struct for the program's data
 * Return: 0 if sucess, or other number if its declared in the args
 */
int bn_help(dat_t *data)
{
	int i, len = 0;
	char *uchenna[6] = {NULL};

	uchenna[0] = HELP_MSG;

	if (data->toks[1] == NULL)
	{
		sh_print(uchenna[0] + 6);
		return (1);
	}
	if (data->toks[2] != NULL)
	{
		errno = E2BIG;
		perror(data->args);
		return (5);
	}
	uchenna[1] = HELP_EXIT_MSG;
	uchenna[2] = HELP_ENV_MSG;
	uchenna[3] = HELP_SETENV_MSG;
	uchenna[4] = HELP_UNSETENV_MSG;
	uchenna[5] = HELP_CD_MSG;

	for (i = 0; uchenna[i]; i++)
	{
		/*print the length of string */
		len = _strlen(data->toks[1]);
		if (_strncmp(data->toks[1], uchenna[i], len))
		{
			sh_print(uchenna[i] + len + 1);
			return (1);
		}
	}
	/*if there is no match, print error and return -1 */
	errno = EINVAL;
	perror(data->args);
	return (0);
}

/**
 * bn_alias - this adds, deletes or show aliases
 * @data: struct for the program's data
 * Return: 0 if sucess, or other number if its declared in the arguments
 */
int bn_alias(dat_t *data)
{
	int i = 0;

	/* if there are no arguments, print all environment */
	if (data->toks[1] == NULL)
		return (_printalias(data, NULL));

	while (data->toks[++i])
	{
		if (_countchars(data->toks[i], "="))
			_setalias(data->toks[i], data);
		else
			_printalias(data, data->toks[i]);
	}

	return (0);
}
