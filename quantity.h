#ifndef QUANTITY_H
#define QUANTITY_H
#include <string>
#include <vector>

using namespace std;

// Опережающее объявление
class QuantityImpl;
class QuantityIter;
class Quantity
{
	virtual vector<int> get ( ) = 0;
	public:
	Quantity();
	Quantity( QuantityImpl* p);
	virtual ~Quantity( );
	virtual void add ( int i ) = 0;
	virtual void remove ( int pos ) = 0;
	virtual int find ( int i ) = 0;
	protected:
	QuantityImpl * pimpl;
};

class QuantityVector : public Quantity
{
	vector<int> get ( );
	public:
	friend class QuantityIter;
	QuantityIter *createIterator();
	QuantityVector(vector<int> vec);
	void add ( int i );
	void remove ( int pos );
	int find ( int i );
};

class QuantityImpl
{
	vector<int> v;
	virtual vector<int> geti ( ) = 0;
	public:
	virtual ~QuantityImpl( ) {}
	virtual void addi ( int i ) = 0;
	virtual void removei ( int pos ) = 0;
	virtual int findi ( int i ) = 0;
	friend class FirstQuantity;
	friend class SecondQuantity;
	friend class QuantityVector;
	friend QuantityImpl * chooseStructure(vector<int> vec_);
};
class FirstQuantity : public QuantityImpl
{
	vector<int> geti ( );
	public:
	FirstQuantity();
	~FirstQuantity();
	void addi ( int i );
	void removei ( int pos );
	int findi ( int i );
};
class SecondQuantity : public QuantityImpl
{
	vector<int> geti ( );
	public:
	SecondQuantity();
	~SecondQuantity();
	void addi ( int i );
	void removei ( int pos );
	int findi ( int i );
};

#endif