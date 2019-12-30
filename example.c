/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   example.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: tbruinem <tbruinem@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/30 10:48:11 by tbruinem       #+#    #+#                */
/*   Updated: 2019/12/30 10:48:15 by tbruinem      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>

int main(void)
{
  void *mlx;
  void *window;

  mlx = mlx_init();
  window = mlx_new_window(mlx, 1000, 1000, "Title");

  mlx_loop(mlx);
  return (0);
}
