// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Character.hpp                                      :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: maurodri <maurodri@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2025/03/23 23:16:46 by maurodri          #+#    #+#             //
//   Updated: 2025/03/24 00:06:12 by maurodri         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef CHARACTER_H
# define CHARACTER_H

#include "ICharacter.hpp"

// The Character possesses an inventory of 4 slots,
// which means 4 Materias at most.
// The inventory is empty at construction.
// They equip the Materias in the first empty slot
// they find. This means,
// in this order: from slot 0 to slot 3. In case they try to add
// a Materia to a full inventory,
// or use/unequip an unexisting Materia, don’t do anything
// (but still, bugs are forbidden).
// The unequip() member function must NOT delete the
// Materia!
// The use(int, ICharacter&) member function will have to use the Materia at the
// slot[idx], and pass the target parameter to the AMateria::use function.
// Your Character must have a constructor
// taking its name as a parameter. Any copy
// (using copy constructor or copy assignment operator)
// of a Character must be deep.
// During copy, the Materias of a Character must be deleted
// before the new ones are added
// to their inventory. Of course,
// the Materias must be deleted when a Character is destroyed.
class Character : public ICharacter
{
	std::string name;
	AMateria *inventory[4] = {0};

public:

	Character();
	Character(std::string name);
	Character(const Character &other);
	virtual Character &operator=(const Character &other);
	virtual ~Character();

	virtual std::string const & getName() const;
	virtual void equip(AMateria* m);
	virtual void unequip(int idx);
	virtual void use(int idx, ICharacter& target);
};

#endif
