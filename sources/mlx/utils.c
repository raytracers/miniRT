/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcorreia <gcorreia@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 10:33:12 by gcorreia          #+#    #+#             */
/*   Updated: 2023/02/14 10:56:01 by gcorreia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/mini_rt.h"

/* void	pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
} */

/*void	pixel_put(mlx_image_t *img, int x, int y, uint32_t color)
{
    uint8_t	*dst;
    const int bytes_per_pixel = 4;  // Could be made a parameter or defined elsewhere

    if (x < 0 || x >= (int)img->width || y < 0 || y >= (int)img->height)
        return;

    dst = img->pixels + (y * img->width * bytes_per_pixel) + (x * bytes_per_pixel);
    *(uint32_t *)dst = color;
}*/

void	pixel_put(mlx_image_t *img, int x, int y, uint32_t color)
{
    uint8_t	*dst;
    const int bytes_per_pixel = 4;

    if (!img || !img->pixels) {
        log_msg("Error: Invalid image or pixel buffer in pixel_put");
        return;
    }

    if (x < 0 || x >= (int)img->width || y < 0 || y >= (int)img->height) {
        return; // Silent fail for out-of-bounds
    }

    size_t offset = (y * img->width * bytes_per_pixel) + (x * bytes_per_pixel);
    dst = img->pixels + offset;

    size_t total_size = img->width * img->height * bytes_per_pixel;
    if (offset + bytes_per_pixel > total_size) {
        log_msg("Error: Buffer overflow in pixel_put");
        return;
    }

    *(uint32_t *)dst = color;
}
