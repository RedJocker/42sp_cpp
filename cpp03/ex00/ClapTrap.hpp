// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   ClapTrap.hpp                                       :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: maurodri <maurodri@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2025/02/06 01:54:34 by maurodri          #+#    #+#             //
//   Updated: 2025/03/24 19:01:22 by maurodri         ###   ########.fr       //
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
	std::string name;
	int hitPoints;
	int energyPoints;
	int attackDamage;

	bool active() const;
	bool alive() const;
	void announce() const;
	
	const static int INITIAL_HIT_POINTS = 10;
	const static int INITIAL_ENERGY_POINTS = 10;
	const static int INITIAL_ATTACK_DAMAGE = 0;
public:
	ClapTrap();
	ClapTrap(std::string name);
	ClapTrap(const ClapTrap &other);
	ClapTrap &operator=(const ClapTrap &other);
	~ClapTrap();
	
	void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
};

#endif
