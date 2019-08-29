int& fun()
{
	int b = 10;
	int &a = b;
	return a;
}
int main()
{
	int a = fun();
	return 0;
}
