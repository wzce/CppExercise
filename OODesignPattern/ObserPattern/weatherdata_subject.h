#include"subject.h"
#include"observer.h"
#include<list>

class WeatherDataSubject : public ISubject{
public:
	WeatherDataSubject(){}
	WeatherDataSubject(double t,double h,double p):temperature(t),humidity(h),presure(p){}
	virtual void register1(IObserver* obesever);
	virtual void remove(IObserver* obesever);
	virtual void notify();  // 通知观察者

private:
	double temperature;
	double humidity;
	double presure;
	list<IObserver * > obsercers;

};

 void WeatherDataSubject::register1(IObserver *observer){
	 obsercers.push_back(observer);
 }

 void WeatherDataSubject::remove(IObserver*obsever){
	 obsercers.remove(obsever);
 }

 void WeatherDataSubject::notify(){
	 auto it = obsercers.begin();
	 while (it != obsercers.end())
	 {
		 it->noify();
	 }
 }