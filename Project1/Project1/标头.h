class Purchse;
class Sale;
class Stock;

class Mediator
{
protected:
	Purchse *pu;
	Sale *sale;
	Stock *stock;
};
class Colle
{
public:
	Colle(Mediator x)
		:x(x){}
	Mediator x;
};
class Purchse :public Colle
{
	Purchse(Mediator x)
	:Colle(x){}
};
class Sale :public Colle
{};
class Stock :public Colle
{};

void Test()
{
	Mediator x;
	Purchse pur(x);

}