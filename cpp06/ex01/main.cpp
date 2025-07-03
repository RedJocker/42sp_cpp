// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   main.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: maurodri <maurodri@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2025/02/03 15:58:31 by maurodri          #+#    #+#             //
//   Updated: 2025/07/03 02:04:59 by maurodri         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include <iostream>
#include "Serializer.hpp"

int main(void)
{

	Data data("some data");

	std::cout << data.data() << std::endl;
	const uintptr_t intptr_data = Serializer::serialize(&data);
	std::cout << "0x" << std::hex << intptr_data << std::dec << std::endl;

	const Data* ptr = Serializer::deserialize(intptr_data);
	std::cout << ptr << std::endl;
	std::cout << ptr->data() << std::endl;
	
	return 0;
}
