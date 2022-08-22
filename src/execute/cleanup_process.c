/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup_process.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 00:15:41 by vgoncalv          #+#    #+#             */
/*   Updated: 2022/08/21 00:15:44 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <execute/execute.h>

void	cleanup_process(void)
{
	int	fd;

	fd = open(HDOC_TMPFILE, O_RDONLY | O_CREAT);
	if (fd < 0)
		return ;
	while (fd > STDERR_FILENO)
		close(fd--);
	unlink(HDOC_TMPFILE);
}
