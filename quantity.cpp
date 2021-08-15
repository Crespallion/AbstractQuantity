#include "quantity.h"
#include <iostream>

//static int fc_counter = 1, fd_counter = 1,
//sc_counter = 1, sd_counter = 1;

using namespace std;

QuantityImpl * chooseStructure(vector<int> vec_){
	QuantityImpl * pimpl_;
	if (vec_.size() < 4){
		pimpl_ = new FirstQuantity();
		pimpl_->v = vec_;
		cout << "First structure" << endl;
	} else {
		pimpl_ = new SecondQuantity();
		pimpl_->v = vec_;
		cout << "Second structure" << endl;
	}
	return pimpl_;
}

Quantity::Quantity( )
{ }

Quantity::Quantity( QuantityImpl* p ) : pimpl(p)
{ }
Quantity::~Quantity( )
{
	delete pimpl;
}

QuantityVector::QuantityVector(vector<int> vec) : Quantity()
{
	pimpl = chooseStructure(vec);
}

void QuantityVector::add( int i )
{
	pimpl->addi( i);
	vector<int> vec = pimpl->geti();
	delete pimpl;
	pimpl = chooseStructure(vec);
}
void QuantityVector::remove( int pos )
{
	pimpl->removei( pos);
	vector<int> vec = pimpl->geti();
	delete pimpl;
	pimpl = chooseStructure(vec);
}
int QuantityVector::find( int i )
{
	return pimpl->findi(i);
}
vector<int> QuantityVector::get( )
{
	return pimpl->geti();
}

FirstQuantity::FirstQuantity(){
	//cout << "First constr " << fc_counter++ << endl;
}
FirstQuantity::~FirstQuantity(){
	//cout << "First destr " << fd_counter++ << endl;
}

void FirstQuantity::addi( int i )
{	
	cout << "Adding \"" << i <<"\" in first quantity."  << endl;
	v.push_back(i);
	cout << "Elements are: {";
	for (int position = 0; position < v.size()-1; ++position){
		cout << v[position] << ", ";
	}
	cout << v[v.size()-1] << "}" << endl;
};
void FirstQuantity::removei( int pos )
{
	cout << "Removing element number [" << pos <<"] in first quantity."  << endl;
	auto iter = v.cbegin();
	v.erase(iter + pos);
	cout << "Elements are: {";
	for (int position = 0; position < v.size()-1; ++position){
		cout << v[position] << ", ";
	}
	cout << v[v.size()-1] << "}" << endl;
};
int FirstQuantity::findi ( int i ){
	cout << "Finding \"" << i <<"\" in first quantity."  << endl;
	for (int pos = 0; pos < v.size(); ++pos){
		if (v[pos] == i) {
			cout << "Position is " << pos << endl; 
			return pos;
		}
	}
	return -1;
}
vector<int> FirstQuantity::geti ( ){
	return v;
}

SecondQuantity::SecondQuantity(){
	//cout << "Second constr " << sc_counter++ << endl;
}
SecondQuantity::~SecondQuantity(){
	//cout << "Second destr " << sd_counter++ << endl;
}

void SecondQuantity::addi( int i )
{
	cout << "Adding \"" << i <<"\" in second quantity."  << endl;
	v.push_back(i);
	cout << "Elements are: {";
	for (int position = 0; position < v.size()-1; ++position){
		cout << v[position] << ", ";
	}
	cout << v[v.size()-1] << "}" << endl;
};
void SecondQuantity::removei( int pos )
{
	cout << "Removing element number [" << pos <<"] in second quantity."  << endl;
	auto iter = v.cbegin();
	v.erase(iter + pos);
	cout << "Elements are: {";
	for (int position = 0; position < v.size()-1; ++position){
		cout << v[position] << ", ";
	}
	cout << v[v.size()-1] << "}" << endl;
};
int SecondQuantity::findi ( int i ){
	cout << "Finding \"" << i <<"\" in second quantity."  << endl;
	for (int pos = v.size()-1; pos > -1; --pos){
		if (v[pos] == i) {
			cout << "Position is " << pos << endl; 
			return pos;
		}
	}
	return -1;
}
vector<int> SecondQuantity::geti ( ){
	return v;
}