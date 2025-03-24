// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   main.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: maurodri <maurodri@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2025/02/03 15:58:31 by maurodri          #+#    #+#             //
//   Updated: 2025/03/24 12:13:24 by maurodri         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "IMateriaSource.hpp"
#include "Ice.hpp"
#include "MateriaSource.hpp"
#include <iostream>
#include "Cure.hpp"
#include "Character.hpp"
#include <cassert>
#include <sstream>

void testMateriaSourceCopyDoesNotLeak()
{
	IMateriaSource *srcOriginal = new MateriaSource();
	srcOriginal->learnMateria(new Ice());
	srcOriginal->learnMateria(new Cure());
	MateriaSource srcCopy = *static_cast<MateriaSource*>(srcOriginal);
	AMateria* tmp;

	tmp = srcOriginal->createMateria("ice");
	assert(tmp->getType() == "ice");
	delete tmp;
	tmp = srcCopy.createMateria("ice");
	assert(tmp->getType() == "ice");
	delete tmp;

	tmp = srcOriginal->createMateria("cure");
	assert(tmp->getType() == "cure");
	delete tmp;
	tmp = srcCopy.createMateria("cure");
	assert(tmp->getType() == "cure");
	delete tmp;

	delete srcOriginal;

	tmp = srcCopy.createMateria("ice");
	assert(tmp->getType() == "ice");
	delete tmp;
	tmp = srcCopy.createMateria("cure");
	assert(tmp->getType() == "cure");
	delete tmp;
}

void testCharacterCopyDoesNotLeak()
{
	std::stringstream ss;
	//redirect cout to ss
	std::basic_streambuf<char>* old_buf = std::cout.rdbuf(ss.rdbuf());

	IMateriaSource *srcOriginal = new MateriaSource();
	srcOriginal->learnMateria(new Ice());
	srcOriginal->learnMateria(new Cure());

	AMateria *tmp;

	ICharacter *me = new Character("me");
	assert(me->getName() == "me");

	tmp = srcOriginal->createMateria("ice");
	assert(tmp->getType() == "ice");
	me->equip(tmp);
	ss.str(""); // clear ss
	me->use(0, *me);
	assert(ss.str() == "* shoots an ice bolt at me *\n");

	tmp = srcOriginal->createMateria("cure");
	assert(tmp->getType() == "cure");
	me->equip(tmp);
	ss.str(""); // clear ss
	me->use(1, *me);
	assert(ss.str() == "* heals me’s wounds *\n");

	Character meCopy = *static_cast<Character *>(me);

	ss.str(""); // clear ss
	me->use(0, *me);
	assert(ss.str() == "* shoots an ice bolt at me *\n");
	ss.str(""); // clear ss
	meCopy.use(0, *me);
	assert(ss.str() == "* shoots an ice bolt at me *\n");
	ss.str(""); // clear ss
	me->use(1, *me);
	assert(ss.str() == "* heals me’s wounds *\n");
	ss.str(""); // clear ss
	meCopy.use(1, *me);
	assert(ss.str() == "* heals me’s wounds *\n");

	std::cout.rdbuf(old_buf); // restore cout
	delete srcOriginal;
	delete me;
}

void testLearnMoreThan4DoesNotLeak()
{
	IMateriaSource *src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Ice());
	src->learnMateria(new Ice());
	src->learnMateria(new Ice());
	src->learnMateria(new Ice());
	src->learnMateria(new Ice());

	delete src;

	IMateriaSource *src2 = new MateriaSource();
	src2->learnMateria(new Cure());
	src2->learnMateria(new Cure());
	src2->learnMateria(new Cure());
	src2->learnMateria(new Cure());
	src2->learnMateria(new Cure());
	src2->learnMateria(new Cure());

	delete src2;
}

void testEquipMoreThan4DoesNotLeak()
{
	IMateriaSource *src = new MateriaSource();
	src->learnMateria(new Ice());

	ICharacter *me = new Character("me");

	me->equip(src->createMateria("ice"));
	me->equip(src->createMateria("ice"));
	me->equip(src->createMateria("ice"));
	me->equip(src->createMateria("ice"));
	me->equip(src->createMateria("ice"));
	me->equip(src->createMateria("ice"));

	delete src;
	delete me;
}

void testUseEmptyDoesNotCrash()
{

	ICharacter *me = new Character("me");

	me->use(0, *me);
	me->use(1, *me);
	me->use(2, *me);
	me->use(3, *me);
	me->use(4, *me);
	me->use(5, *me);
	delete me;
}


void testCreateNonLearntReturnsNull()
{
	IMateriaSource *src = new MateriaSource();
	AMateria *tmp;

	tmp = src->createMateria("ice");
	assert(tmp == 0);
	src->learnMateria(new Ice());
	tmp = src->createMateria("ice");
	assert(tmp != 0);
	delete tmp;

	tmp = src->createMateria("cure");
	assert(tmp == 0);
	src->learnMateria(new Cure());
	tmp = src->createMateria("cure");
	assert(tmp != 0);
	delete tmp;

	tmp = src->createMateria("fire");
	assert(tmp == 0);

	delete src;
}


int	main(void)
{
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	ICharacter* me = new Character("me");
	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	ICharacter* bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);
	delete bob;
	delete me;
	delete src;

	testMateriaSourceCopyDoesNotLeak();
	testCharacterCopyDoesNotLeak();
	testLearnMoreThan4DoesNotLeak();
	testEquipMoreThan4DoesNotLeak();
	testUseEmptyDoesNotCrash();
	testCreateNonLearntReturnsNull();
	return 0;
}
