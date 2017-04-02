#include <iostream>
#include <string>

class Colleague;
class Mediator;
class ConcreteMediator;
class ConcreteColleague1;
class ConcreteColleague2;

class Mediator
{
public:
	virtual void Send(std::string const& message, Colleague *colleague) = 0;
};

class Colleague
{
protected:
	Mediator* mediator_;

public:
	Colleague(Mediator *mediator) :mediator_(mediator)
	{
	}
};

class ConcreteColleague1 :public Colleague
{
public:
	ConcreteColleague1(Mediator* mediator) :Colleague(mediator)
	{
	}

	void Send(std::string const& message)
	{
		mediator_->Send(message, this);
	}

	void Notify(std::string const& message)
	{
		std::cout << "Colleague1 gets message '" << message << "'" << std::endl;
	}
};

class ConcreteColleague2 :public Colleague
{
public:
	ConcreteColleague2(Mediator *mediator) :Colleague(mediator)
	{
	}

	void Send(std::string const& message)
	{
		mediator_->Send(message, this);
	}

	void Notify(std::string const& message)
	{
		std::cout << "Colleague2 gets message '" << message << "'" << std::endl;
	}
};

class ConcreteMediator :public Mediator
{
protected:
	ConcreteColleague1      *m_Colleague1;
	ConcreteColleague2      *m_Colleague2;
public:
	bool getmess1 = false, getmess2 = false;
	void SetColleague1(ConcreteColleague1 *c)
	{
		m_Colleague1 = c;
	}

	void SetColleague2(ConcreteColleague2 *c)
	{
		m_Colleague2 = c;
	}

	virtual void Send(std::string const& message, Colleague *colleague)
	{
		if (colleague == m_Colleague1)
		{
			m_Colleague2->Notify(message);
			this->getmess2 = true;
		}
		else if (colleague == m_Colleague2)
		{
			m_Colleague1->Notify(message);
			this->getmess1 = true;
		}
	}
};