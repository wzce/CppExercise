
class IObserver{
public:
	virtual void update(const double temprature, const double humidity, const double presure) = 0;
};