/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chruhin <chruhin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 18:41:05 by chruhin           #+#    #+#             */
/*   Updated: 2024/04/01 16:00:31 by chruhin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(int argc, char *argv[])
{
	if (argc == 3)
	{
		int	N = atoi(argv[1]);
		if (!N || N <= 0 || N > MAX_N)
		{
			std::cerr << RED << INVD << RST << std::endl;
			return (1);
		}
		std::string str = argv[2];
		testZombieHorde(N, str);
	}
	else
		std::cerr << RED << USAGE << RST << std::endl;
	return 0;
}
