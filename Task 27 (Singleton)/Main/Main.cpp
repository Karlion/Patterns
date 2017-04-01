#include"../Task 27 (Singleton)/Singleton.h"
using namespace std;
void main(){
	Singleton *example = Singleton::Get();
	cout << example->getCheck() << std::endl;
	system("pause");
}