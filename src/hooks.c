/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababdoul <ababdoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 12:21:20 by ababdoul          #+#    #+#             */
/*   Updated: 2025/02/01 15:05:57 by ababdoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"


int handle_keypress(int keycode, t_game *game)
{
    int moved;

    moved = 0;
    if (keycode == KEY_ESC)
    {
        mlx_destroy_window(game->mlx, game->win); // Destroy the window
        exit(0); // Exit the program
    }
    if (keycode == KEY_W || keycode == KEY_UP)
        moved = move_player(game, 0, -1);
    else if (keycode == KEY_S || keycode == KEY_DOWN)
        moved = move_player(game, 0, 1);
    else if (keycode == KEY_A || keycode == KEY_LEFT)
        moved = move_player(game, -1, 0);
    else if (keycode == KEY_D || keycode == KEY_RIGHT)
        moved = move_player(game, 1, 0);
    
    if (moved)
    {
        game->moves++;
        printf("Moves: %d\n", game->moves);
        render_game(game);
    }
    return (0);
}

int handle_close(t_game *game)
{
    mlx_destroy_window(game->mlx, game->win); // Destroy the window
    exit(0); // Exit the program
    return (0);
}

void setup_hooks(t_game *game)
{
    mlx_hook(game->win, 2, 1L<<0, handle_keypress, game);
    mlx_hook(game->win, 17, 1L<<17, handle_close, game);
    mlx_loop_hook(game->mlx, render_game, game);
}

