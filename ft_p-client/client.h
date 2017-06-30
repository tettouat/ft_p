/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tettouat <tettouat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/04 17:30:22 by tettouat          #+#    #+#             */
/*   Updated: 2015/06/04 17:46:08 by tettouat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_H
# define CLIENT_H

int		handle_cd(t_stream *stream, char *line, char **cmd);
int		handle_get(t_stream *stream, char *line, char **cmd);
int		handle_ls(t_stream *stream, char *line, char **cmd);
int		handle_put(t_stream *stream, char *line, char **cmd);
int		handle_pwd(t_stream *stream, char *line, char **cmd);
int		handle_quit(t_stream *stream, char *line, char **cmd, int *running);

#endif
