/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countchar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgaribot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 09:33:52 by fgaribot          #+#    #+#             */
/*   Updated: 2019/01/15 15:25:48 by fgaribot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_countchar(char const *s, char c)
{
	int i;

	if (!s)
		return (0);
	i = 0;
	while (s[i] != c && s[i] != '\0')
		i++;
	return (i);
}
