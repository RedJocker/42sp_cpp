// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Zombie.hpp                                         :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: maurodri <maurodri@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2025/01/17 19:46:04 by maurodri          #+#    #+#             //
//   Updated: 2025/01/17 20:14:40 by maurodri         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <string>
#endif

// First, implement a Zombie class. It has a string private attribute name.

class Zombie {
	std::string name;
public:
	// Add a member function void announce( void ); to the Zombie class. Zombies
	// announce themselves as follows:
	// <name>: BraiiiiiiinnnzzzZ...
	// Don’t print the angle brackets (< and >). For a zombie named Foo, the message
	// would be:
	// Foo: BraiiiiiiinnnzzzZ...
	void announce(void);
	Zombie(std::string name);
	~Zombie();
};

// Then, implement the two following functions:

// • Zombie* newZombie( std::string name );
// It creates a zombie, name it, and return it so you can use it outside of the function
// scope.
Zombie* newZombie( std::string name );
// • void randomChump( std::string name );
// It creates a zombie, name it, and the zombie announces itself.
void randomChump( std::string name );

// Now, what is the actual point of the exercise? You have to determine in what case
// it’s better to allocate the zombies on the stack or heap.
// Zombies must be destroyed when you don’t need them anymore. The destructor must
// print a message with the name of the zombie for debugging purposes.
