//
// Created by thomas on 04/05/22.
//

int	verifyargs(char arguments[])
{
	int test;
	int i;

	i = 0;
	while (arguments[i])
	{
		test = ft_isdigit(arguments[i]);
		if (test == 0)
		{
			return (test);
		}
		i++;
	}
	return (test);
}

void	mainpushswap(int stacka[], int argcount)
{
	int	stackb[argcount - 1];

	stackb[0] = 1;
	ft_printf("%d\n", stacka[0]);
	ft_printf("%d\n", stacka[1]);
	ft_printf("%d\n", stacka[2]);
	stacka = simplifynumbers(stacka);
	ft_printf("%d\n", stacka[0]);
	ft_printf("%d\n", stacka[1]);
	ft_printf("%d\n", stacka[2]);
	ft_itoa(stackb[0]);
	return ;
}

void	startpushswap(int argcount, char *arguments[])
{
	int	i;
	int	stacka[argcount - 1];
	int	currentarg;

	i = 1;
	while (++i < argcount)
	{
		currentarg = verifyargs(arguments[i]);
		if (currentarg == 1)
		{
			stacka[i] = ft_atoi(arguments[i]);
		}
		else
		{
			ft_printf("Error\n");
			return ;
		}
	}
	mainpushswap(stacka, argcount);
	return ;
}
