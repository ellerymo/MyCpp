#include<iostream>
#define INC 10
#define DEFUALT 10
using namespace std;
typedef int DataType;
class SeqList
{
	friend ostream& operator<<(ostream &os, SeqList seq);
private:
	DataType * _pseq;
	int _size;
	int _capacity;
public:
	SeqList(int capacity = DEFUALT)
		:_pseq(new DataType[capacity]), _capacity(capacity), _size(0)
	{}
	SeqList(SeqList &seq)
	{
		_capacity = seq._capacity;
		_pseq = new DataType[_capacity];
		_size = seq._size;
		memcpy(_pseq,seq._pseq,_size*(sizeof(DataType)));
	}
	SeqList& operator =(const SeqList& seq)
	{
		if (this != &seq)
		{
			delete[] _pseq;
			_capacity = seq._capacity;
			_size = seq._size;
			_pseq = new DataType[seq._capacity];
			memcpy(_pseq, seq._pseq, _size*(sizeof(DataType)));
		}
		return *this;
	}
	~SeqList()
	{
		if (_pseq == NULL)
		{
			delete[] _pseq;
			_pseq = NULL;
		}
	}
public:
	DataType operator[](int index)
	{
		return _pseq[index];
	}
	void CheckCapacity()
	{
		if (_size == _capacity)
		{
			SeqList tmp(*this);
			delete[] _pseq;
			_pseq = new DataType[_capacity + INC];
			memcpy(_pseq, tmp._pseq, _size);
			_capacity += INC;
		}
	
	}
	void Insert(int pos, const DataType &d)
	{
		CheckCapacity();
		for(int i = _size; i > pos;i--)
		{
			_pseq[i] = _pseq[i - 1];
		}
		_pseq[pos] = d;
		_size++;
	}
	void PopBack()
	{
		if (_size > 0)
			_size--;
		else
			cout << "The list is Empty!!!" << endl;
	}
	void PopFront()
	{
		if (_size > 0)
		{
			for (int i = 0; i < _size - 1; i++)
			{
				_pseq[i] = _pseq[i + 1];
			}
			_size--;
		}
		else
			cout << "The list is Empty!!!" << endl;
	}
	void Remove(const DataType &d)
	{ 
		int pos = 0;
		int count = _size;
		DataType *ptr = _pseq;
		while ((ptr[pos] != d )&&(count --))
		{
			ptr++;
		}
		if (ptr[pos] == d)
		{
			for (int i = pos; i < _size; i++)
			{
				_pseq[i] = _pseq[i + 1];
			}
			_size--;
		}
		else
			cout << "Cant Find The Data!" << endl;
	}
	void Reverse()
	{
		DataType *left = _pseq;
		DataType *right = _pseq+(_size - 1);
		while (right > left)
		{
			DataType tmp = *right;
			*right = *left;
			*left = tmp;
			right--;
			left++;
		}
	}
	int Find(DataType d)
	{
		int pos = 0;
		int count = _size;
		DataType *ptr = _pseq;
		while ((ptr[pos] != d) && (count--))
		{
			ptr++;
		}
		if (ptr[pos] == d)
			return pos;
		else
			cout << " Cant Find The Data! " << endl;
	}
};
ostream& operator<<(ostream &os, SeqList seq)
{
	for (int i = 0; i < seq._size; i++)
	{
		cout << seq._pseq[i] << " ";
	}
	cout << endl;
	return os;
}
int main()
{
	SeqList seq1;
	SeqList seq2;
	SeqList seq3;
	seq1.Insert(0, 1);
	seq1.Insert(1, 2);
	seq1.Insert(2, 3);
	seq1.Insert(3, 4);
	seq1.Insert(4, 5);
	seq1.Insert(5, 6);

	seq2.Insert(0, 7);
	seq2.Insert(1, 8);
	seq2.Insert(2, 9);
	seq2.Insert(3, 10);
	seq2.Insert(4, 11);
	seq2.Insert(5, 12);

	seq3 = seq1;
	cout << "原始数据" << endl;
	cout <<"Seq1:"<< seq1;
	cout <<"Seq2:"<< seq2;
	cout <<"Seq3:"<< seq3;
	cout << "尾删 Seq1 和 Seq2" << endl;
	seq1.PopBack();
	seq2.PopBack();
	cout << "Seq1:" << seq1;
	cout << "Seq2:" << seq2;
	cout << "头删" << endl;
	seq1.PopFront();
	seq2.PopFront();
	cout << "Seq1:" << seq1;
	cout << "Seq2:" << seq2;
	cout << "插入数据" << endl;
	seq1.Insert(2, 4);
	cout << "Seq1:" << seq1;
	cout << "逆序" << endl;
	seq2.Reverse();
	cout << "Seq2:" << seq2;
	getchar();
	return 0;
}