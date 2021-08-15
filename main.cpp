#include <string>
#include <vector>
#include <iostream>
#include "quantity.h"

using namespace std;

class QuantityIter
{
	QuantityVector &qv;
	int index = 0;
	public:
	QuantityIter(QuantityVector &qv_) : qv(qv_)
	{
		int index = 0;
	}
	void first()
	{
		index = 0;
	}
	void next()
	{
		if (index == qv.get().size() - 1){
			cout << " !End of cointainer! " << endl;
			return;
		}
		index++;
	}
	bool isDone()
	{
		return index == qv.get().size() - 1;
	}
	int currentItem()
	{
		return qv.get()[index];
	}
	void operator++()
	{
		if (index == qv.get().size() - 1){
			cout << " !End of cointainer! ";
			index = 0;
			return;
		}
		index++;
	}
	int operator *()
	{
		return qv.get()[index];
	}
};

int main()
{
	vector<int> vec = {1, 2};
	QuantityVector p = QuantityVector(vec);
	p.add(6);
	p.add(3);
	p.add(5);
	int pos = p.find(2);
	p.remove(pos);
	p.remove(0);
	p.add(8);

	QuantityIter itv1(p);
	cout << "Items: ";
	for (int i = 0; i < 10; ++i)
	{
		cout << *itv1 << ' ';
		++itv1;
	}
	cout << endl;
	//delete p;
	return 0;
}