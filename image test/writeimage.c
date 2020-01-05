/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   writeimage.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: tbruinem <tbruinem@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/05 16:41:33 by tbruinem       #+#    #+#                */
/*   Updated: 2020/01/05 16:41:33 by tbruinem      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef WIDTH
# define WIDTH 800
#endif
#ifndef HEIGHT
# define HEIGHT 800
#endif

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
 
int main(int argc, char **input)
{
	int x;
	int y;
	int	fd;
	unsigned char color[4];

	y = 0;
//	if (argc < 2 || argc > 2)
//		return (0);
//	fd = open(input[1], O_CREAT, O_RDWR);
	printf("P6\n%d %d\n255\n", WIDTH, HEIGHT);
	while (y < WIDTH)
	{
		x = 0;
		while (x < HEIGHT)
		{
			printf("%c%c%c", 255, 255, 255);
			x++;
		}
		y++;
	}
//	close(fd);
	return (0);
}
