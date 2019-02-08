/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_flag.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgaribot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 15:16:37 by fgaribot          #+#    #+#             */
/*   Updated: 2019/02/06 16:07:11 by fgaribot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		list_flag(char c)
{
	char	*flags;
	int		i;

	i = 0;
	flags = "0123456789.#+- |";
	while (flags[i] != c && flags[i] != '|')
		i++;
	if (flags[i] == c)
		return (1);
	return (0);
}