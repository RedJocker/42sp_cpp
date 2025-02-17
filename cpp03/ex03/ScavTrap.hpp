// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   ScavTrap.hpp                                       :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: maurodri <maurodri@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2025/02/07 22:28:26 by maurodri          #+#    #+#             //
//   Updated: 2025/02/17 15:52:23 by maurodri         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef SCAV_TRAP_HPP
# define SCAV_TRAP_HPP

# include "ClapTrap.hpp"

// Because you can never have enough ClapTraps, you will now create a derived robot.
// It will be named ScavTrap and will inherit the constructors and destructor from Clap-
// Trap. However, its constructors, destructor and attack() will print different messages.
// After all, ClapTraps are aware of their individuality.
// Note that proper construction/destruction chaining must be shown in your tests.
// When a ScavTrap is created, the program starts by building a ClapTrap. Destruction is
// in reverse order. Why?
// ScavTrap will use the attributes of ClapTrap (update ClapTrap in consequence) and
// must initialize them to:
// • Name, which is passed as parameter to a constructor
// • Hit points (100), represent the health of the ClapTrap
// • Energy points (50)
// • Attack damage (20)
// ScavTrap will also have its own special capacity:
// void guardGate();
// This member function will display a message informing that ScavTrap is now in Gate
// keeper mode.

class ScavTrap : virtual public ClapTrap
{
	

protected:
	void announce() const;

	virtual int initialHitPoints();
	virtual int initialEnergyPoints();
	virtual int initialAttackDamage();
	
public:
	ScavTrap();
	ScavTrap(std::string name);
	ScavTrap(const ScavTrap &other);
	ScavTrap &operator=(const ScavTrap &other);
	~ScavTrap();
	virtual void attack(const std::string& target);
	void guardGate(void);
};

#endif
