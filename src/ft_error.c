/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_error.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: tbruinem <tbruinem@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/30 22:24:38 by tbruinem       #+#    #+#                */
/*   Updated: 2019/12/30 22:24:38 by tbruinem      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int		ft_error(int error)
{
	static char	*error_msg[10] = {
		[ERR_ARG] = "Please (only) supply a scene file.",
		[ERR_FILE] = "Please supply a valid file.",
		[ERR_MEM] = "Not enough memory.",
		[ERR_NORMAL] = "One or more of the given orientation vectors are not and can not be normalized.",
		[ERR_TYPE] = "Please supply a file with the extension: ",
	};

	write(1, "Error\n", ft_strlen("Error\n"));
	write(1, error_msg[error], ft_strlen(error_msg[error]));
	if (error == ERR_TYPE)
		write(1, FILE_TYPE, ft_strlen(FILE_TYPE));
	write(1, "\n", 1);
	return (error);
}
