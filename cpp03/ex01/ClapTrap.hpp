// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   ClapTrap.hpp                                       :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: maurodri <maurodri@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2025/02/06 01:54:34 by maurodri          #+#    #+#             //
//   Updated: 2025/02/07 23:07:11 by maurodri         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef _CLAPTRAP_HPP
# define _CLAPTRAP_HPP

# include <string>

// It will be called ClapTrap and will have the following private attributes initialized
// to the values specified in brackets:
// • Name, which is passed as parameter to a constructor
// • Hit points (10), represent the health of the ClapTrap
// • Energy points (10)
// • Attack damage (0)
// Add the following public member functions so the ClapTrap looks more realistic:
// • void attack(const std::string& target);
// • void takeDamage(unsigned int amount);
// • void beRepaired(unsigned int amount);
// When ClapTrack attacks, it causes its target to lose <attack damage> hit points.
// When ClapTrap repairs itself, it gets <amount> hit points back. Attacking and repairing
// cost 1 energy point each. Of course, ClapTrap can’t do anything if it has no hit points
// or energy points left.
// In all of these member functions, you have to print a message to describe what hap-
// pens. For example, the attack() function may display something like (of course, without
// the angle brackets):
// ClapTrap <name> attacks <target>, causing <damage> points of damage!
// The constructors and destructor must also display a message, so your peer-evaluators
// can easily see they have been called.
// Implement and turn in your own tests to ensure your code works as expected.


class ClapTrap
{
	
protected:
	std::string name;
	int hitPoints;
	int energyPoints;
	int attackDamage;

	virtual int initialHitPoints();
	virtual int initialEnergyPoints();
	virtual int initialAttackDamage();

	bool active() const;
	bool alive() const;
	virtual void announce() const;

public:
	ClapTrap();
	ClapTrap(std::string name);
	ClapTrap(const ClapTrap &other);
	virtual ClapTrap &operator=(const ClapTrap &other);
	virtual ~ClapTrap();
	
	virtual void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
};

#endif
