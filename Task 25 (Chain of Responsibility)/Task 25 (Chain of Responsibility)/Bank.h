#include "Payment.h"

class Bank
{
	Bank* next;
public:
	Bank();
	void setNext(Bank* n);
	void add(Bank* n);

	virtual void handle(Payment* p) = 0;
};

class Fix : public Bank
{
public:
	void handle(Payment* p);
};


class Control : public Bank
{
public:
	void handle(Payment* p);
};


class TakePercent : public Bank
{
public:
	void handle(Payment* p);
};


class GiveBonus : public Bank
{
public:
	void handle(Payment* p);
};

Bank::Bank() : next(nullptr) {};

void Bank::setNext(Bank* n) {
	next = n;
}

void Bank::add(Bank* n) {
	if (next) next->add(n);
	else next = n;
}

void Bank::handle(Payment* p) {
	next->handle(p);
}

void Fix::handle(Payment* p)
{
	if (p->getPaymentType() == 1) p->fixed = "Normal";
	if (p->getPaymentType() == 2) p->fixed = "Internal";
	if (p->getPaymentType() == 3) p->fixed = "State";
	if (p->getPaymentType() == 4) p->fixed = "Preferential";
	Bank::handle(p);
}

void Control::handle(Payment* p)
{
	if (p->getPaymentType() == 1) p->controlled = "Normal";
	if (p->getPaymentType() == 2) p->controlled = "Internal";
	if (p->getPaymentType() == 3) p->controlled = "State";
	if (p->getPaymentType() == 4) p->controlled = "Preferential";

	Bank::handle(p);
}

void TakePercent::handle(Payment* p)
{
	if (p->getPaymentType() == 1) p->payedPercent(5);
	if (p->getPaymentType() == 2) p->payedPercent(4);
	if (p->getPaymentType() == 3) p->payedPercent(3);
	if (p->getPaymentType() == 4) p->payedPercent(2);
	Bank::handle(p);
}

void GiveBonus::handle(Payment* p)
{
	if (p->getPaymentType() == 1) p->getBonuses(2);
	if (p->getPaymentType() == 2) p->getBonuses(3);
	if (p->getPaymentType() == 3) p->getBonuses(4);
	if (p->getPaymentType() == 4) p->getBonuses(5);
}