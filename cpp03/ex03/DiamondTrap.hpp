// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   DiamondTrap.hpp                                    :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: maurodri <maurodri@student.42sp...>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2025/02/17 15:08:24 by maurodri          #+#    #+#             //
//   Updated: 2025/02/17 17:23:04 by maurodri         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef DIAMOND_TRAP_HPP
# define DIAMOND_TRAP_HPP

# include <string> 
# include "FragTrap.hpp"
# include "ScavTrap.hpp"

// In this exercise, you will create a monster: a ClapTrap that’s half FragTrap, half
// ScavTrap. It will be named DiamondTrap, and it will inherit from both the FragTrap
// AND the ScavTrap. This is so risky!
// The DiamondTrap class will have a name private attribute. Give to this attribute
// exactly the same variable’s name (not talking about the robot’s name here) than the one
// in the ClapTrap base class.
// To be more clear, here are two examples.
// If ClapTrap’s variable is name, give the name name to the one of the DiamondTrap.
// If ClapTrap’s variable is _name, give the name _name to the one of the DiamondTrap.
// Its attributes and member functions will be picked from either one of its parent classes:
// • Name, which is passed as parameter to a constructor
// • ClapTrap::name (parameter of the constructor + "_clap_name" suffix)
// • Hit points (FragTrap) (100)
// • Energy points (ScavTrap) (50)
// • Attack damage (FragTrap) (30)
// • attack() (Scavtrap)
// C++ - Module 03 Inheritance
// In addition to the special functions of both its parent classes, DiamondTrap will have
// its own special capacity:
// void whoAmI();
// This member function will display both its name and its ClapTrap name.
// Of course, the ClapTrap subobject of the DiamondTrap will be created once, and only
// once. Yes, there’s a trick.

class DiamondTrap : public FragTrap, public ScavTrap 
{

	std::string name;

protected:
	
	virtual int initialHitPoints();
	virtual int initialEnergyPoints();
	virtual int initialAttackDamage();

	virtual void announce() const;
public:
  	DiamondTrap();
	DiamondTrap(std::string name);
	DiamondTrap(const DiamondTrap &other);
	virtual DiamondTrap &operator=(const DiamondTrap &other);
	virtual ~DiamondTrap();

	virtual void attack(const std::string& target);
	void whoAmI();
};


#endif
