/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: risattou <risattou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 21:51:38 by risattou          #+#    #+#             */
/*   Updated: 2025/10/15 23:59:52 by risattou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>

int	Account::getNbAccounts( void ) 
{
    return _nbAccounts;
};

int	Account::getTotalAmount( void ) 
{
    return _totalAmount;
};

int	Account::getNbDeposits( void ) 
{
    return _totalNbDeposits;
};

int	Account::getNbWithdrawals( void ) 
{
    return _totalNbWithdrawals;
};

void	Account::displayAccountsInfos( void )
{
		_displayTimestamp();
		std::cout << "accounts:" << _nbAccounts <<
		";total:" << _totalAmount <<
		";deposits:" << _totalNbDeposits <<
		";withdrawals:" << _totalNbWithdrawals << std::endl;
};
Account::Account( int initial_deposit )
{
		_displayTimestamp();
		_accountIndex = _nbAccounts;
		_amount = initial_deposit;
		_nbDeposits = 0;
		_nbWithdrawals = 0;
		_nbAccounts++;
		_totalAmount += _amount;
		std::cout << "index:" << _accountIndex <<
		";amount:"<< _amount << ";created" << std::endl;
};

Account::~Account( void )
{
        _displayTimestamp();
        std::cout << "index:" << _accountIndex <<
        ";amount:"<< _amount << ";closed" << std::endl;
};


void	Account::makeDeposit( int deposit )
{
    _displayTimestamp();
    _nbDeposits++;
    _totalNbDeposits++;
    _totalAmount += deposit;
    std::cout << "index:" << _accountIndex <<
    ";p_amount:"<< _amount <<
    ";deposit:"<< deposit <<
    ";amount:"<< (deposit + _amount) <<
    ";nb_deposits:"<<_nbDeposits << std::endl;
    _amount += deposit;
}
bool	Account::makeWithdrawal( int withdrawal )
{
    _displayTimestamp();
    if (withdrawal < _amount)
    {
        _nbWithdrawals++;
        std::cout << "index:" << _accountIndex <<
        ";p_amount:" << _amount <<
        ";withdrawal:" << withdrawal <<
        ";amount:" << (_amount - withdrawal ) <<
        ";nb_withdrawals:" << _nbWithdrawals << std::endl;
        _amount -= withdrawal;
        _totalNbWithdrawals++;
        _totalAmount -= withdrawal;
        return 1;
    }
    std::cout << "index:" << _accountIndex <<
    ";p_amount:" << _amount <<
    ";withdrawal:refused" << std::endl;
    return 0;
}
int		Account::checkAmount( void ) const
{
    _displayTimestamp();
    std::cout << "[Cp:" << this->_accountIndex << ";" << std::endl;
    return 10;
}
void	Account::displayStatus( void ) const
{
    _displayTimestamp();
    std::cout << "index:" << _accountIndex <<
    ";amount:"<< _amount <<
    ";deposits:" << _nbDeposits <<
    ";withdrawals:" << _nbWithdrawals << std::endl;

};
