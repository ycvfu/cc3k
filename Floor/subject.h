#ifndef SUBJECT_H
#define SUBJECT_H
#include <vector>
struct Info;
class Observer;

class Subject {
	std::vector<Observer*> observers;

	public:
		void attach(Observer *o);
		void notifyObservers();
		virtual Info getInfo() const = 0;
		virtual ~Subject() = default;
};

#endif
