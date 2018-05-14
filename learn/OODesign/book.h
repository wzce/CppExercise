#include<string>
#include<vector>
#include<memory>
using namespace std;


class Quote{
protected:
	string isbn;
	double price=0.0;
public:
	Quote() = default;
	Quote(string isbn, double price) :isbn(isbn), price(price){}
	virtual ~Quote(){
		cout << " Quote destoried  " << endl;
	}
	string getIsbn()  ;
	virtual double net_price(int num) const;
	virtual void print() const{
		cout <<"Quote : "  << "isbn: " << isbn << " ,price:" << price << endl;
	};
};

string Quote::getIsbn()  {
	return isbn;
}

 double Quote::net_price(int num) const{
	return price*num;
}


 class BulkQuote:public Quote{
 private:
	 double discount;
 public:
	 BulkQuote() = default;
	 BulkQuote(string is, double price) :Quote(is,price){}
	 virtual ~BulkQuote(){
		 cout << " BulkQuote destoried  " << endl;
	 }
	 double net_price(int num) const;
	 virtual void print() const{
		 cout <<"BulkQuote: "<< "isbn: " << isbn << " ,price:" << price << ", discount:"<<discount<< endl;
	 };
 };

 double BulkQuote::net_price(int num) const{
	 return price*0.8*num;
 }

 class BookList{
 private:
	 vector<shared_ptr<Quote>> list;
	 vector<Quote *> ll;
 public:
	 void addBook(const shared_ptr<Quote> &q){
		 list.push_back(q);
	 }

	 void addBook(Quote *q){
		 ll.push_back(q);
	 };
	 void show(){
		 vector<Quote *>::iterator bg = ll.begin();

		 for (int i = 0; i < ll.size(); i++){
			 ll[i]->print();
		 }
	 }

	 void showAllBook(){
		 
		//list.back()->print();

		vector<shared_ptr<Quote>>::iterator bg = list.begin();
		
		for (int i = 0 ; i < list.size(); i++){
			list[i]->print();
		 }
	 }
 };