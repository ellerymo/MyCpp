#include"Bloom.h"

void testBitMap()
{
	BitMap<> bm(100);
	bm.Set(10);
	bm.Set(20);
	bm.Set(90);
	cout << "10:" << bm.test(10) << endl;
	cout << "20:" << bm.test(20) << endl;
	cout << "90:" << bm.test(90) << endl; 
	cout << "30:" << bm.test(30) << endl;

	bm.Reset(90);
	cout << "90:" << bm.test(90) << endl;

}
void testBloom()
{
	BloomFilter<> bloom(100);
	bloom.Set("Zhao");
	bloom.Set("Ji");
	bloom.Set("Hou");
	bloom.Set("Bai");
	bloom.Set("He");
	cout << "ÕÔÓ±ÄÈ£º" << bloom.Test("Zhao") << endl;
	cout << "¼ÍÁ¢ÐÂ£º" << bloom.Test("Ji") << endl;
	cout << "ºîÈï£º" << bloom.Test("Hou") << endl;
	cout << "ºÎÀ×£º" << bloom.Test("He") << endl;
	cout << "°×Ðõ£º" << bloom.Test("Bai") << endl;
	cout << "´ÞÓîÐù£º" << bloom.Test("CuiYuxuan") << endl;
}
int main()
{
	testBitMap();
	testBloom();
	getchar();
	return 0;
}