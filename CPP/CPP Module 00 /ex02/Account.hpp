// ************************************************************************** //
//                                                                            //
//                Account.hpp for GlobalBanksters United                //
//                Created on  : Thu Nov 20 19:43:15 1989                      //
//                Last update : Wed Jan 04 14:54:06 1992                      //
//                Made by : Brad "Buddy" McLane <bm@gbu.com>                  //
//                                                                            //
// ************************************************************************** //


#pragma once
#ifndef __ACCOUNT_H__
#define __ACCOUNT_H__

// ************************************************************************** //
//                               Account Class                                //
// ************************************************************************** //
#include <iostream>

#include <ctime>

class Account {


public:

	typedef Account		t;

	static int	getNbAccounts( void ){return _nbAccounts;};
	static int	getTotalAmount( void ){return _totalAmount;};
	static int	getNbDeposits( void ){return _totalNbDeposits;};
	static int	getNbWithdrawals( void ){return _totalNbWithdrawals;};
	static void	displayAccountsInfos( void ){
		_displayTimestamp();
		std::cout << "accounts:" << _nbAccounts <<
		";total:" << _totalAmount <<
		";deposits:" << _totalNbDeposits <<
		";withdrawals:" << _totalNbWithdrawals << std::endl;
	};

	Account( int initial_deposit ){
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
	~Account( void ){
		_displayTimestamp();
		std::cout << "index:" << _accountIndex <<
		";amount:"<< _amount << ";closed" << std::endl;
	};

	void	makeDeposit( int deposit )
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
	bool	makeWithdrawal( int withdrawal )
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
	int		checkAmount( void ) const
	{
		_displayTimestamp();
		std::cout << "[Cp:" << this->_accountIndex << ";" << std::endl;
		return 10;
	}
	void	displayStatus( void ) const
	{
		_displayTimestamp();
		std::cout << "index:" << _accountIndex <<
		";amount:"<< _amount <<
		";deposits:" << _nbDeposits <<
		";withdrawals:" << _nbWithdrawals << std::endl;

	};


private:

	static int	_nbAccounts;
	static int	_totalAmount;
	static int	_totalNbDeposits;
	static int	_totalNbWithdrawals;

	static void	_displayTimestamp( void ){
		std::time_t		now = std::time(0);
		std::tm*		tm = std::localtime(&now);
		std::cout << '[' << tm->tm_year + 1900  ;
		tm->tm_mon >= 9 ? std::cout << tm->tm_mon + 1 : std::cout << '0' << tm->tm_mday + 1;
		tm->tm_mday >= 10 ? std::cout << tm->tm_mday : std::cout << '0' << tm->tm_mday;
		std::cout << '_';
		tm->tm_hour >= 10 ? std::cout << tm->tm_hour : std::cout << '0' << tm->tm_hour;
		tm->tm_min >= 10 ? std::cout << tm->tm_min : std::cout << '0' << tm->tm_min;
		tm->tm_sec >= 10 ? std::cout << tm->tm_sec : std::cout << '0' << tm->tm_sec;
		std::cout << "] ";
	};

	int				_accountIndex;
	int				_amount;
	int				_nbDeposits;
	int				_nbWithdrawals;

	Account( void );

};



// ************************************************************************** //
// vim: set ts=4 sw=4 tw=80 noexpandtab:                                      //
// -*- indent-tabs-mode:t;                                                   -*-
// -*- mode: c++-mode;                                                       -*-
// -*- fill-column: 75; comment-column: 75;                                  -*-
// ************************************************************************** //


#endif /* __ACCOUNT_H__ */
