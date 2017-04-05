#include<iostream>
#include<vector>
#include<string>

using namespace std;

class Post
{
private:
	vector<class Subscriber*> subs;
	string newspaperName;
public:
	void attach(Subscriber*);
	void setNewspapersName(string);
	string getName();
	void notify();
};

class Subscriber
{
private:
	Post*post;
	string name;
	string subscribed;
protected:
	Post *getPost(){ return post; };
	string getSubscribersName();
	string getSubscribedNewspaperName();
public:
	Subscriber(Post *_post, string _name, string _sub);
	virtual void update() = 0;
};

class SubObserver:public Subscriber
{
	public:
	SubObserver(Post*_post, string _name, string _sub) :Subscriber(_post, _name, _sub){};
	void update();
};


void Post::attach(Subscriber*sub)
{
	subs.push_back(sub);
}
void Post::setNewspapersName(string name)
{
	newspaperName = name;
	notify();
}
string Post::getName()
{
	return newspaperName;
}
void Post::notify()
{
	for (int i = 0; i < subs.size(); i++)
		subs[i]->update();
}

Subscriber::Subscriber(Post *_post, string _name, string _sub)
{
	post = _post;
	name = _name;
	subscribed = _sub;
	post->attach(this);
}
string Subscriber::getSubscribersName()
{
	return subscribed;
}

string Subscriber::getSubscribedNewspaperName()
{
	return name;
}

void SubObserver::update(){
	string onPost = getPost()->getName();
	string ordered = getSubscribedNewspaperName();
	if (onPost == ordered)
		cout << "Delivering " << onPost << " to " << getSubscribersName() << endl;
}