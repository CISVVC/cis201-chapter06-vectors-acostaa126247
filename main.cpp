/*
* File: main.cpp
* Developer: Angel Acosta
* Email: acostaa126247@student.vvc.edu
* Description: A bank statement if 1 months worth of withdrawels and deposits.
*/
#include <iostream>
#include <string>
#include <vector>

class Transaction
{
public:
   Transaction();
   void read();
   int get_day();
   double get_amount();
   void print() const;
private:
   int day;
   double amount;
   std::string description;
};

Transaction::Transaction()
{
   day = 0;
   amount = 0.0;
}

double Transaction::get_amount()
{
    return amount;
}

int Transaction::get_day()
{
    return day;
}

void Transaction::read()
{
    std::cout << "day: ";
    std::cin >> day;
    std::cout << "amount: ";
    std::cin >> amount;
    std::cin.ignore();
    std::cout << "description: ";
    std::getline(std::cin,description);
}

void Transaction::print() const
{
    std::cout << "day:" << day << std::endl;
    std::cout << "amount:" << amount << std::endl;
    std::cout << "description:" << description << std::endl;
}

void print_transactions(const std::vector<Transaction> t)
{
    for(int i=0;i<t.size();i++)
        t[i].print(); // prints out what lays in the vector!~!
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

int MAX_DAY = 30;

class Statement
{
public:
   Statement();
   void read();
   void compute_balances();
   double get_average_daily_balance();
   double get_minimum_daily_balance();
private:
   std::vector<Transaction> transactions;
   std::vector<double> daily_balances;
};

Statement::Statement()
{
}

void Statement::read()
{
    std::cout << "Enter transactions " << std::endl;
      std::cout << "[Day] [Amount] [Description]" <<std::endl;
   bool more = true;
   while(more)
   {
      Transaction t;
      t.read();
      
      char response;
      std::cout <<"continue? y|Y: ";
      std::cin >> response;
      if(response != 'Y' && response != 'y')
         more = false;
      else
        transactions.push_back(t);
         
   }
   compute_balances();
}

void Statement::compute_balances()
{
    double balance = 0; int j = 0;
    for(int i = 1; i <= MAX_DAY; i++) 
    { 
	    while (j < transactions.size() && transactions[j].get_day() == i) 
	    { 
	        balance = balance + transactions[j].get_amount();
	        j++; 
	    }
	    daily_balances.push_back(balance); 
        
    }
    const double INTEREST = 0.05;
    std::cout << "Minimum daily balance interest: " << get_minimum_daily_balance() * INTEREST << std::endl; 
    std::cout << "Average daily balance interest: " << get_average_daily_balance() * INTEREST << std::endl;
  
}

double Statement::get_average_daily_balance()
{
    double sum = 0;
    for(int i = 0; i < daily_balances.size(); i++) 
    sum = sum + daily_balances[i]; 
    return sum / MAX_DAY;
}

double Statement::get_minimum_daily_balance()
{
    double min = daily_balances[0];
    for (int i = 1; i < daily_balances.size(); i++) 
    if (daily_balances[i] < min) 
    min = daily_balances[i]; 
    return min;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

int main()
{
    
  Statement p1;
   p1.read();
   
   return 0;
}

