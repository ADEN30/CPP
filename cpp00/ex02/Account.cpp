#include "Account.hpp"

// Initialisation des variables statiques
int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

void Account::_displayTimestamp() {
  std::time_t result = std::time(NULL);

  std::cout << std::setfill('0') << "["
            << 1900 + std::localtime(&result)->tm_year << std::setw(2)
            << 1 + std::localtime(&result)->tm_mon << std::setw(2)
            << std::localtime(&result)->tm_mday << "_" << std::setw(2)
            << std::localtime(&result)->tm_hour << std::setw(2)
            << std::localtime(&result)->tm_min << std::setw(2)
            << std::localtime(&result)->tm_sec << "] " << std::flush;
}

// Constructeur par défaut privé
Account::Account(void)
    : _accountIndex(_nbAccounts), _amount(0), _nbDeposits(0),
      _nbWithdrawals(0) {
  _nbAccounts++;
  _displayTimestamp();
  std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";created"
            << std::endl;
}

// Constructeur avec dépôt initial
Account::Account(int initial_deposit)
    : _accountIndex(_nbAccounts), _amount(initial_deposit), _nbDeposits(0),
      _nbWithdrawals(0) {
  _displayTimestamp();
  std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";created"
            << std::endl;
  _nbAccounts++;
  _totalAmount += _amount;
}

// Destructeur
Account::~Account(void) {
  _displayTimestamp();
  std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";closed"
            << std::endl;
  _nbAccounts--;
  _totalAmount -= _amount;
}

int Account::getNbAccounts(void) { return _nbAccounts; }

int Account::getTotalAmount(void) { return _totalAmount; }

int Account::getNbDeposits(void) { return _totalNbDeposits; }

int Account::getNbWithdrawals(void) { return _totalNbWithdrawals; }
// Méthode statique pour afficher les informations des comptes
void Account::displayAccountsInfos(void) {
  _displayTimestamp();
  std::cout << "accounts:" << _nbAccounts << ";total:" << _totalAmount
            << ";deposits:" << _totalNbDeposits
            << ";withdrawals:" << _totalNbWithdrawals << std::endl;
}

// Méthode pour effectuer un dépôt
void Account::makeDeposit(int deposit) {
  _displayTimestamp();
  std::cout << "index:" << _accountIndex << ";p_amount:" << _amount
            << ";deposit:" << deposit << ";amount:" << (_amount + deposit)
            << ";nb_deposits:" << (_nbDeposits + 1) << std::endl;
  _amount += deposit;
  _nbDeposits++;
  _totalAmount += deposit;
  _totalNbDeposits++;
}

// Méthode pour effectuer un retrait
bool Account::makeWithdrawal(int withdrawal) {
  _displayTimestamp();
  std::cout << "index:" << _accountIndex << ";p_amount:" << _amount;

  if (_amount >= withdrawal) {
    std::cout << ";withdrawal:" << withdrawal
              << ";amount:" << (_amount - withdrawal)
              << ";nb_withdrawals:" << (_nbWithdrawals + 1) << std::endl;
    _amount -= withdrawal;
    _nbWithdrawals++;
    _totalAmount -= withdrawal;
    _totalNbWithdrawals++;
    return true;
  } else {
    std::cout << ";withdrawal:refused" << std::endl;
    return false;
  }
}

// Méthode pour vérifier le solde
int Account::checkAmount(void) const { return _amount; }

// Méthode pour afficher l'état du compte
void Account::displayStatus(void) const {
  _displayTimestamp();
  std::cout << "index:" << _accountIndex << ";amount:" << _amount
            << ";deposits:" << _nbDeposits << ";withdrawals:" << _nbWithdrawals
            << std::endl;
}
