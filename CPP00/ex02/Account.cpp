
#include "Account.hpp"
#include <iostream>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit) : _amount(initial_deposit), _nbDeposits(0), _nbWithdrawals(0) {
	this->_accountIndex = Account::_nbAccounts++;
	Account::_totalAmount += this->_amount;
	std::cout << "Account " << this->_accountIndex << " created with balance: " << this->_amount << std::endl;
}

Account::~Account() {
	std::cout << "Account " << this->_accountIndex << " closed with balance: " << this->_amount << std::endl;
}

void Account::makeDeposit(int deposit) {
	this->_amount += deposit;
	this->_nbDeposits++;
	Account::_totalAmount += deposit;
	Account::_totalNbDeposits++;

	std::cout << "Account " << this->_accountIndex << " deposit: " << deposit << ", current balance: " << this->_amount << std::endl;
}

bool Account::makeWithdrawal(int withdrawal) {
	if (this->_amount >= withdrawal) {
		this->_amount -= withdrawal;
		this->_nbWithdrawals++;
		Account::_totalAmount -= withdrawal;
		Account::_totalNbWithdrawals++;

		std::cout << "Account " << this->_accountIndex << " withdrawal: " << withdrawal << ", current balance: " << this->_amount << std::endl;
		return true;
	} 
	else {
		std::cout << "Account " << this->_accountIndex << " withdrawal failed: insufficient funds" << std::endl;
		return false;
	}
}

void Account::displayStatus() const {
	std::cout << "Account " << this->_accountIndex << " balance: " << this->_amount << std::endl;
}

void Account::displayAccountsInfos() {
	std::cout << "Total accounts: " << Account::_nbAccounts << ", total balance: " << Account::_totalAmount 
				<< ", total deposits: " << Account::_totalNbDeposits << ", total withdrawals: " << Account::_totalNbWithdrawals << std::endl;
}
