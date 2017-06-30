/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tettouat <tettouat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/04 17:36:11 by tettouat          #+#    #+#             */
/*   Updated: 2015/06/08 14:56:37 by tettouat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/socket.h>
#include <fcntl.h>
#include <netinet/in.h>
#include <unistd.h>
#include "../libft/libft.h"
#include <stdlib.h>
#include "server.h"
#include "stream.h"
#include "protocol.h"
#include <sys/param.h>
#include <sys/wait.h>
#include <sys/resource.h>

int		setup_sock(struct sockaddr_in *srvaddr, int port)
{
	int	srvfd;
	int	yes;

	yes = 1;
	if ((srvfd = socket(AF_INET, SOCK_STREAM, 0)) < 0
		|| setsockopt(srvfd, SOL_SOCKET, SO_REUSEADDR, &yes, sizeof(int)) < 0)
	{
		ft_putendl("Socket error");
		return (-1);
	}
	ft_bzero(srvaddr, sizeof(*srvaddr));
	srvaddr->sin_family = AF_INET;
	srvaddr->sin_addr.s_addr = htonl(INADDR_ANY);
	srvaddr->sin_port = htons(port);
	if (bind(srvfd, (struct sockaddr *)srvaddr, sizeof(*srvaddr)) < 0)
	{
		ft_putendl("Bind error");
		return (-1);
	}
	if (listen(srvfd, 5) < 0)
		return (-1);
	return (srvfd);
}

void	send_failure(t_stream *stream, char *msg)
{
	if (!write_s8(stream, ERR))
		ft_putendl("ERR");
	if (!write_string(stream, msg, msg == NULL ? 0 : ft_strlen(msg)))
		ft_putendl("ERR");
}

void	handle(int clifd)
{
	t_stream	stream;
	int8_t		cmd;
	t_state		state;

	getcwd(state.rootdir, MAXPATHLEN);
	state.running = 1;
	state.id = clifd;
	create_stream(clifd, &stream);
	while (state.running && read_s8(&stream, &cmd))
	{
		if (!ft_isalpha(cmd))
			handle_fail(&stream, &state);
		else
		{
			ft_putstr("Handling cmd : ");
			ft_putchar(ft_toupper(cmd));
			ft_putstr(" ");
			ft_putendl("");
			handle_cmd(cmd, &stream, &state);
		}
	}
}

int		handle_cli(int srvfd, int clifd)
{
	int		pid;

	if ((pid = fork()) == 0)
	{
		ft_putendl("Connection accepted");
		close(srvfd);
		handle(clifd);
		close(clifd);
		ft_putendl("Connection closed");
		return (0);
	}
	else if (pid < 0)
		ft_putendl("Fork error");
	else
		close(clifd);
	return (1);
}

int		main(int argc, char **argv)
{
	int					fd[2];
	socklen_t			clilen;
	struct sockaddr_in	srv;
	struct sockaddr_in	cliaddr;
	int					i;

	i = argc > 1 ? ft_atoi(argv[1]) : 3000;
	if ((fd[0] = setup_sock(&srv, i)) < 0)
	{
		ft_putendl("An error has occured while creating the server");
		return (1);
	}
	display_port(i);
	while ((clilen = sizeof(cliaddr)))
	{
		if ((fd[1] = accept(fd[0], (struct sockaddr*)&cliaddr, &clilen)) < 0)
		{
			ft_putendl("Accept error");
			return (1);
		}
		if (handle_cli(fd[0], fd[1]) == 0)
			return (0);
	}
	close(fd[0]);
	return (0);
}
