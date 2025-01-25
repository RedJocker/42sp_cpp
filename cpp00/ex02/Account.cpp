// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Account.cpp                                        :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: maurodri <maurodri@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2025/01/17 16:22:54 by maurodri          #+#    #+#             //
//   Updated: 2025/01/25 15:05:22 by maurodri         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Account.hpp"
#include <ctime>
#include <iostream>

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

void	Account::_displayTimestamp(void)
{
	const size_t SIZE = 25;
	char time_str[SIZE];
	
	std::time_t result = std::time(nullptr);
	std::strftime(time_str, SIZE, "[%Y%m%d_%H%M%S]", std::localtime(&result));
	std::cout << time_str;
}

int Account::getNbAccounts()
{
	return _nbAccounts;
}

int Account::getTotalAmount(void)
{
	return _totalAmount;
}

int Account::getNbDeposits(void)
{
	return _totalNbDeposits;
}

int Account::getNbWithdrawals(void)
{
	return _totalNbWithdrawals;
}

void Account::displayAccountsInfos(void)
{
	Account::_displayTimestamp();
	std::cout << " accounts:"<< getNbAccounts() << ";"
			  << "total:" << getTotalAmount() << ";"
			  << "deposits:" << getNbDeposits() << ";"
			  << "withdrawals:" << getNbWithdrawals() << std::endl;
	return;
}

Account::Account(int initial_deposit) :
	_accountIndex(Account::_nbAccounts),
	_amount(initial_deposit),
	_nbDeposits(0),
	_nbWithdrawals(0)
{
	Account::_nbAccounts++;
	Account::_totalAmount += initial_deposit;
	Account::_displayTimestamp();
	std::cout << " index:"<< _accountIndex << ";"
			  << "amount:" << _amount << ";"
			  << "created" << std::endl;
	return ;
}

Account::~Account(void)
{
	Account::_displayTimestamp();
	std::cout << " index:"<< _accountIndex << ";"
			  << "amount:" << _amount << ";"
			  << "closed" << std::endl;
	return ;
}

void Account::makeDeposit(int deposit)
{
	const int previous_amount = this->_amount;

	this->_nbDeposits++;
	this->_amount += deposit;
	Account::_totalAmount += deposit;
	Account::_totalNbDeposits++;
	Account::_displayTimestamp();
	std::cout << " index:" << _accountIndex << ";"
			  << "p_amount:" << previous_amount << ";"
			  << "deposit:" << deposit << ";"
			  << "amount:" << _amount << ";"
			  << "nb_deposits:" << _nbDeposits
			  << std::endl;
	return ;
}

bool Account::makeWithdrawal(int withdrawal)
{
	const int new_amount = this->_amount - withdrawal;
	Account::_displayTimestamp();
	if (new_amount < 0)
	{
		std::cout << " index:" << _accountIndex << ";"
				  << "p_amount:" << this->_amount << ";"
				  << "withdrawal:refused"
				  << std::endl;
		return false;
	}

	this->_nbWithdrawals++;
	Account::_totalNbWithdrawals++;
	
	std::cout <<  " index:" << _accountIndex << ";"
			  << "p_amount:" << this->_amount << ";"
			  << "withdrawal:" << withdrawal << ";"
			  << "amount:" << new_amount << ";"
			  << "nb_withdrawals:" << 1
		<< std::endl;
	
	this->_amount -= withdrawal;
	Account::_totalAmount -= withdrawal;
	return true;
}

int Account::checkAmount(void) const
{
	return 0;
}

void Account::displayStatus(void) const
{
	Account::_displayTimestamp();
	std::cout << " index:"<< _accountIndex << ";"
			  << "amount:" << _amount << ";"
			  << "deposits:" << _nbDeposits << ";"
			  << "withdrawals:" << _nbWithdrawals
			  << std::endl;
	
	return ;
}
