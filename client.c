/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chford <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/08 11:06:02 by chford            #+#    #+#             */
/*   Updated: 2019/03/08 15:16:19 by chford           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "server.h"
#include <netdb.h>
#include <arpa/inet.h>

int		main(int argc, char **argv)
{
	struct sockaddr_in	server_address;
	char				buffer[BUFF_SIZE + 1];
	int					sockfd;
	int					ret;

	if (argc != 2)
		return (1);
	if ((sockfd = socket(PF_INET, SOCK_STREAM, 0)) == -1)
		return (1);
	server_address.sin_family = PF_INET; 
	server_address.sin_addr.s_addr = inet_addr(LOCALHOST); 
	server_address.sin_port = htons(PORT_NUMBER);
	if (connect(sockfd, (struct sockaddr *)&server_address, sizeof(server_address)))
		return (1);
	write(sockfd, argv[1], ft_strlen(argv[1]));
	ret = read(sockfd, buffer, BUFF_SIZE);
	buffer[ret] = '\0';
	write(1, "Response from server:\n", 22);
	write(1, buffer, ft_strlen(buffer));
	write(1, "\n", 1);
	if (ret == -1)
		return (1);
	return (0);
}
