/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   minirt_enum.h                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: tbruinem <tbruinem@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/06 17:00:45 by tbruinem       #+#    #+#                */
/*   Updated: 2020/01/14 20:38:39 by tbruinem      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_ENUM_H
# define MINIRT_ENUM_H

enum	e_errors
{
	ERR_ARG = 1,
	ERR_TYPE,
	ERR_FILE,
	ERR_NORMAL,
	ERR_MEM,
	ERR_RANGE,
	ERR_ID,
};

enum	e_collision
{
	C_SPH,
	C_PLN,
	C_SQR,
	C_CYL,
	C_TRI,
};

enum	e_id
{
	ERROR = -1,
	SPH,
	PLN,
	SQR,
	CYL,
	TRI,
	RES,
	AMB,
	CAM,
	LIGHT,
};

typedef enum		e_event_code
{
	MOUSE_PRESS_CODE = 4,
	MOUSE_MOVE_CODE = 6,
	KEY_PRESS_CODE = 2,
	KEY_RELEASE_CODE = 3,
	RED_BUTTON_CODE = 17,
}					t_event_code;

typedef enum		e_ft_mlx_hooks
{
	NO_EVENT_HOOK = 0,
	MOUSE_PRESS_HOOK = 1,
	MOUSE_MOVE_HOOK = 2,
	KEY_PRESS_HOOK = 4,
	RED_BUTTON_HOOK = 8,
}					t_ft_mlx_hooks;

typedef enum		e_mouse_code
{
	LEFT_CLICK = 1,
	RIGHT_CLICK = 2,
	SCROLL_UP = 4,
	SCROLL_DOWN = 5,
}					t_mouse_code;

typedef enum		e_key_code
{
	A = 0,
	S = 1,
	D = 2,
	Z = 6,
	X = 7,
	W = 13,
	ZOOM_IN = 69,
	ZOOM_OUT = 78,
	SPACE = 49,
	ESCAPE = 53,
	NUM_LOCK_9 = 92,
	NUM_LOCK_8 = 91,
	NUM_LOCK_7 = 89,
	NUM_LOCK_6 = 88,
	NUM_LOCK_5 = 87,
	NUM_LOCK_4 = 86,
	NUM_LOCK_3 = 85,
	NUM_LOCK_2 = 84,
	NUM_LOCK_1 = 83,
	NUM_LOCK_0 = 82,
	RIGHT_ARROW = 124,
	LEFT_ARROW = 123,
	UP_ARROW = 126,
	DOWN_ARROW = 125,
}					t_key_code;

#endif
