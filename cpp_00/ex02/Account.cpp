#include "Account.hpp"
#include <iostream>
#include <iomanip>
#include <ctime>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit) : _amount(initial_deposit), _nbDeposits(0), _nbWithdrawals(0)
{
    _displayTimestamp();
    _accountIndex = _nbAccounts;
    std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";created" << std::endl;
    _nbAccounts++;
    _totalAmount += initial_deposit;
}

Account::~Account()
{
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";closed" << std::endl;
    _nbAccounts--;
    _totalAmount -= _amount;
}

int Account::getNbAccounts(void)
{
    return (_nbAccounts);
}

int Account::getTotalAmount(void) { return (_totalAmount); }
int Account::getNbDeposits(void) { return (_totalNbDeposits); }
int Account::getNbWithdrawals(void) { return (_totalNbWithdrawals); }

void Account::displayAccountsInfos(void)
{
    _displayTimestamp();
    std::cout << "accounts:" << getNbAccounts() << ";total:" << getTotalAmount()
              << ";deposits:" << getNbDeposits() << ";withdrawals:" << getNbWithdrawals()
              << std::endl;
}

void Account::makeDeposit(int deposit)
{
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";p_amount:" << _amount
              << ";deposit:" << deposit << ";amount:" << _amount + deposit
              << ";nb_deposits:" << _nbDeposits + 1 << std::endl;
    _totalNbDeposits++;
    _nbDeposits++;
    _amount += deposit;
    _totalAmount += deposit;
}

bool Account::makeWithdrawal(int withdrawal)
{
    _displayTimestamp();
    if (withdrawal > _amount)
    {
        std::cout << "index:" << _accountIndex << ";p_amount:" << _amount
                  << ";withdrawal:refused" << std::endl;
        return (false);
    }
    else
    {
        std::cout << "index:" << _accountIndex << ";p_amount:" << _amount
                  << ";withdrawal:" << withdrawal << ";amount:" << _amount - withdrawal
                  << ";nb_withdrawals:" << _nbWithdrawals + 1 << std::endl;
        _totalNbWithdrawals++;
        _nbWithdrawals++;
        _amount -= withdrawal;
        _totalAmount -= withdrawal;
        return (true);
    }
}

int Account::checkAmount(void) const
{
    return (_amount);
}

void Account::displayStatus(void) const
{
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";amount:" << _amount
              << ";deposits:" << _nbDeposits << ";withdrawals:" << _nbWithdrawals
              << std::endl;
}

void Account::_displayTimestamp(void)
{
    std::time_t now = std::time(0);
    std::tm *timeinfo = std::localtime(&now);

    std::cout << "[" << (timeinfo->tm_year + 1900)
              << std::setfill('0') << std::setw(2) << (timeinfo->tm_mon + 1)
              << std::setfill('0') << std::setw(2) << timeinfo->tm_mday
              << "_"
              << std::setfill('0') << std::setw(2) << timeinfo->tm_hour
              << std::setfill('0') << std::setw(2) << timeinfo->tm_min
              << std::setfill('0') << std::setw(2) << timeinfo->tm_sec
              << "] ";
}

Account::Account(void) {}