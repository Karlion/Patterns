#include <string>

using namespace std;

class Payment
{
	string client;
	int paymentType;
	double sum;

public:
	string fixed;
	string controlled;

	Payment(int pt, double sum, string clientName) : paymentType(pt), sum(sum), client(clientName){}

	string getClient();
	int getPaymentType();
	int getSum();
	double payedPercent(double percent);
	double getBonuses(double bonus);
};

string Payment::getClient() {
	return client;
}

int Payment::getPaymentType() {
	return paymentType;
}

int Payment::getSum() {
	return sum;
}

double Payment::payedPercent(double percent) {
	sum *= 1 - percent / 100.;
	return sum*percent / 100.;
}

double Payment::getBonuses(double bonus) {
	sum *= 1 + bonus / 100.;
	return sum*(bonus / 100.);
}