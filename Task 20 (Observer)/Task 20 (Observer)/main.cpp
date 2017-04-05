#include"Observer.h"

void main()
{
	Post Post ;

	SubObserver subRon(&Post, "Brooms", "Ron");
	SubObserver subHarry(&Post, "Brooms", "Harry");
	SubObserver subHermione(&Post, "Daily Prophet", "Hermione");
	SubObserver subLuna(&Post, "Quibbler", "Luna");

	Post.setNewspapersName("Brooms");
	Post.setNewspapersName("Daily Prophet");
	Post.setNewspapersName("Quibbler");

	system("pause");
}