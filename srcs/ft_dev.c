#include "mini.h"

int		ft_test(char *str)
{
	int				i;
	struct dirent	*fichierlu[2];
	DIR				*rep;

	i = 0;
	rep = NULL;
	if (str == NULL || !(rep = opendir(str)))
		return (0);
	while ((fichierlu[0] = readdir(rep)) != NULL)
		i++;
	closedir(rep);
	return (i);
}

int is_in(char *path, char *commande)
{
	DIR *rep;
	struct dirent	*fichierlu[ft_test(path) + 1];
	int i;

	i = 0;
	if (!(rep = opendir(path)))
		return (-1);
//	while(commande[i] != 0 &&  commande[i] != ' ' && commande[i] != '\n')
//		i++;
//	commande[i] = 0;
//	i = 0;
//	if(ft_strcmp("env", commande) == 0)
//	{
//		ft_putstr("oui");
//		return(0);
//	}
	while ((fichierlu[i] = readdir(rep)) != NULL)
	{
		if(ft_strncmp(fichierlu[i]->d_name, commande, ft_strlen(fichierlu[i]->d_name)) == 0)
		{
			closedir(rep);
			return (1);
		}
		i++;
	}
	closedir(rep);
	return(0);
}

void ft_dev2(char *str, pid_t id)
{
	char **tab;
	int i;
	char str2[42];
	char *str3;

	i = 0;
	if(is_in("/usr/bin/", str) && id == 0)
	{
		tab = ft_strsplit(str, ' ');
		str2[0] = '/';
		str2[1] = 'u';
		str2[2] = 's';
		str2[3] = 'r';
		str2[4] = '/';
		str2[5] = 'b';
		str2[6] = 'i';
		str2[7] = 'n';
		str2[8] = '/';
		int b = 9;
		i = 0;
		while (ft_isalnum(str[i]))
		{
			str2[b] = str[i];
			i++;
			b++;
		}
		str2[b] = '\0';
		execve(str2, tab, NULL);
		ft_libre(tab);
		return ;
	}
}

void ft_dev(char *str, pid_t id)
{
	//char *tab[4] = {"ls", "-a", "-l", NULL};
	char **tab;
	int i;
	char str2[42];
	char *str3;

	i = 0;
	if(is_in("/bin/", str) && id == 0)
	{
		tab = ft_strsplit(str, ' ');
		str2[0] = '/';
		str2[1] = 'b';
		str2[2] = 'i';
		str2[3] = 'n';
		str2[4] = '/';
		int b = 5;
		i = 0;
		while (ft_isalnum(str[i]))
		{
			str2[b] = str[i];
			i++;
			b++;
		}
		str2[b] = '\0';
		//ft_putstr(tab[1]);
		execve(str2, tab, NULL);
		ft_libre(tab);
	}
	ft_dev2(str, id);
}