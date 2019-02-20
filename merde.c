/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merde.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgaribot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 18:28:09 by fgaribot          #+#    #+#             */
/*   Updated: 2019/02/20 18:38:06 by fgaribot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	test2(char **s)
{
	char *s2;

	s2 = "chat";
	printf("%s", *s);
	*s = s2;
}

void	test(char **s)
{
	test2(&*s);
}

int main()
{
	char *str;

	str = "chien";
	test(&str);
	printf("%s", str);
}
