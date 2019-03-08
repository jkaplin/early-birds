/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chford <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 10:20:20 by chford            #+#    #+#             */
/*   Updated: 2019/03/08 15:44:38 by chford           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

int		read_response(int new_sockfd)
{
	char	buffer[BUFF_SIZE + 1];
	int		ret;

	ret = read(new_sockfd, buffer, BUFF_SIZE);
		buffer[ret] = '\0';
	if (ret == -1)
		return (0);
	if (ret == 0)
		return (1);
	if (ft_strcmp(buffer, "ping") == 0)
		write(new_sockfd, "pong pong", 10);
	if (ft_strcmp(buffer, "disconnect") == 0)
	{
		write (new_sockfd, "Thanks for coming", 17);
		return (0);
	}
	else
		write (new_sockfd, "Other response", 14);
	return (1);
}

int		bind_socket(int sockfd)
{
	struct sockaddr_in	server_address;

	server_address.sin_family = PF_INET;
	server_address.sin_addr.s_addr = INADDR_ANY;
	server_address.sin_port = htons(PORT_NUMBER);
	if (bind(sockfd, (struct sockaddr *)&server_address, sizeof(server_address)) == 0)
		return (1);
	return (0);
}

int		main(int argc, char **argv)
{
	struct sockaddr_in	client_address;
	socklen_t			client_length;
	int					new_sockfd;
	int					sockfd;
	
	sockfd = -1;
	while (++sockfd < argc)
		if (ft_strcmp(argv[sockfd], "-D") == 0)
//			if ((daemon(1, 1)) == -1)
				return (1);
	if ((sockfd = socket(PF_INET, SOCK_STREAM, 0)) < 0)
		return (1);
	if (!(bind_socket(sockfd)))
		return (1);

	if (listen(sockfd, 3) < 0)
		return (1);
	client_length = sizeof(client_address);
	while (1)
	{
		if ((new_sockfd = accept(sockfd, (struct sockaddr *)
					&client_address, &client_length)) < 0)
		return (1);
		if (read_response(new_sockfd) == 0)
			break ;
	}
	close(new_sockfd);
	close(sockfd);
	return (0);
}
