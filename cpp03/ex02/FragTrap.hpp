// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   FragTrap.hpp                                       :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: maurodri <maurodri@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2025/02/07 22:28:26 by maurodri          #+#    #+#             //
//   Updated: 2025/02/11 21:49:00 by maurodri         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef FRAG_TRAP_HPP
# define FRAG_TRAP_HPP

# include "ClapTrap.hpp"

// Now, implement a FragTrap class that inherits from ClapTrap. It is very similar to
// ScavTrap. However, its construction and destruction messages must be different. Proper
// construction/destruction chaining must be shown in your tests. When a FragTrap is
// created, the program starts by building a ClapTrap. Destruction is in reverse order.
// Same things for the attributes, but with different values this time:
// • Name, which is passed as parameter to a constructor
// • Hit points (100), represent the health of the ClapTrap
// • Energy points (100)
// • Attack damage (30)
// FragTrap has a special capacity too:
// void highFivesGuys(void);

class FragTrap : public ClapTrap
{
	

protected:
	void announce() const;

	virtual int initialHitPoints();
	virtual int initialEnergyPoints();
	virtual int initialAttackDamage();
	
public:
	FragTrap();
	FragTrap(std::string name);
	FragTrap(const FragTrap &other);
	FragTrap &operator=(const FragTrap &other);
	~FragTrap();
	virtual void attack(const std::string& target);
	void highFivesGuys(void);
};

#endif
