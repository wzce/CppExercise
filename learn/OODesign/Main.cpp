#include<string>
#include<iostream>
#include<memory>
#include"book.h"
using namespace std;

void printTotal(  Quote &quote,int num){
	cout <<"isbn: "<<quote.getIsbn()<<  " , sold: " << num << "  , total_price: " << quote.net_price(num) << endl;
}

 
int main(){
	Quote q("quote",30);
	BulkQuote bq("bulk_quote", 30);
	//printTotal(q,2);
	//printTotal(q,2);
	//printTotal(q,2);
	int aaa = 34343;

	int x = 0;
	int x = 0;

	Quote * de1 =new Quote("de1", 100);
	BulkQuote * de2 = new BulkQuote("de2", 200);


	BookList list;
	list.addBook(make_shared<Quote>(*de1));
	list.addBook(make_shared<BulkQuote>(*de2));

	list.showAllBook();
	cout << "---------------------------------" << endl;
	list.addBook(de1);
	list.addBook(de2);

	list.show();
	return 1;
}