#include"GenList.h"
using namespace std;
int main()
{
	GenList glist1("(a,b,(c,d))");
	glist1.Print();
	cout<<"   Depth:"<<glist1.Depth()<<endl;
	GenList glist2("((a,b),(c,d),((a,c),(b,d)))");
	glist2.Print();
	cout << "   Depth:" << glist2.Depth() << endl;
	GenList glist3(glist2);
	glist3.Print();
	cout << "   Depth:" << glist3.Depth() << endl;
	getchar();
	return 0;
}