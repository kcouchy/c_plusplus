/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcouchma <kcouchma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 14:07:11 by kcouchma          #+#    #+#             */
/*   Updated: 2024/07/29 11:38:28 by kcouchma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

#include <limits>

#define uintptr_t unsigned int*
#define INT_MAX std::numeric_limits<int>::max()

typedef struct	SData
{
	int				a;
	unsigned int	b;
}		Data;

class Serializer
{
	public:
		~Serializer(void);

		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);

	private:
		Serializer(void);
		Serializer(Serializer const &original);
		Serializer &operator=(Serializer const &original);
};

#endif