#include "iostream";
using namespace std;
int main()

{ 
	double a, b, c;
	char key;
	
	cin >> a;
	cin >> key;
	cin >> b;
	switch (key)
	{
	case '+': c = a + b; cout << c; break;
	case '-': c = a - b; cout << c; break;
	case '*': c = a * b; cout << c; break;
	case '/': {
		if (b !=0) {
			c = a / b;  cout << c;
		}
		else { cout << " div 0"; }
		 } break;

	default: cout << " 404 \n";
		break;


	}
	return 0;
}