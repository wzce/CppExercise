// subject.h

class IObserver;

class ISubject{
public:
	virtual void registerObserver(IObserver* obesever) = 0;
	virtual void remove(IObserver* obesever) = 0;
	virtual void notify() = 0;  // ֪ͨ�۲���
	virtual void update(double temprature, double humidity, double presure)=0;
}
;
 