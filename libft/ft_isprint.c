/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fosuna-g <fosuna-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 12:40:51 by fernando          #+#    #+#             */
/*   Updated: 2023/11/29 16:15:42 by fosuna-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isprint(int c)
{
	return (c >= 32 && c <= 126);
}

/* int main(void)
{
	char    c;
	
	c = '9';
	if (ft_isprint(c))
		write(1, "True\n", 5);
	else
		write(1, "False\n", 6);
	return (0);
} */
