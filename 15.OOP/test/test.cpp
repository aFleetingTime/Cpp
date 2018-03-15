//派生类能否向基类转换依赖于当前代码块是否具备访问基类成员的权限。

class Base { public: int pub = 1; private: int priv = 2; protected: int prot = 3; };

class TestPub  : public Base { };
class TestPriv  : private Base { };
class TestProt  : protected Base { };

struct Pub : public Base
{
	friend void pubf(Base &&b);
	int func() { return pub + prot; }
};
struct Priv : private Base
{
	friend void privf(Base &&b);
	int func() { return pub + prot; }
};
struct Prot : protected Base
{
	friend void protf(Base &&b);
	int func() { return pub + prot; }
};

struct T1 : private TestPub { 
	void f(Base &&b) { 
		//TestPub以public继承Base，因此T1即可以访问Base也可以访问TestPub的成员。
		TestPub &&b1 = T1();	//ok
		Base &&b2 = TestPub();	//ok
	}
};		
struct T2 : private TestPriv { 
//			‘class Base Base::Base’ is inaccessible within this context
	void f(/*Base &&b*/) {	//TestPriv以private方式继承Base，T2无法使用Base类型。
		TestPriv &&b1 = T2();		//ok
		//Base b;					//error T2也不能定义Base对象
	}
};
struct T3 : private TestProt {
	void f(Base &&b) {
		//派生类可以访问TestProt以及TestProt以protected方式继承的Base的成员。
		TestProt &&b1 = T3();	//ok
		Base &&b2 = TestProt();	//ok
	}
};	//ok

void pubf(Base &&b)
{
	Base &&b1 = Pub();			//ok
	//Base &&b2 = Priv();		//error 此处基类-Base的引用需要访问Priv对象中的Base子对象部分，但是由于Priv继承Base的方式是private的，在该作用域下并不具备其访问权限。
	//Base &&b3 = Prot();		//error 原因同上，Prot对象的protected部分是受保护的。
}
void privf(Base &&b)
{
	Base &&b1 = Pub();			//ok Pub类是以public继承Base的，Pub可以在任何作用域下进行转换。
	Base &&b2 = Priv();			//ok 由于该函数被声明为Priv的友元，具备访问Priv对象的private成员的权限，因此这个派生类向基类的转换是正确的。
	//Base &&b3 = Prot();		//error
}
void protf(Base &&b)
{
	Base &&b1 = Pub();		//ok
	//Base &&b2 = Priv();	//error
	Base &&b3 = Prot();		//ok Prot类的成员或友元具备访问protected成员的权限
}

int main()
{
	Base &&b1 = Pub();		//ok

	//Priv和Prot分别以private和protected方式继承Base，用户代码无法访问Priv/Prot对象的Base部分。
	//Base &&b2 = Priv();	//error: ‘Base’ is an inaccessible base of ‘Priv’
	//Base &&b3 = Prot();	//error: ‘Base’ is an inaccessible base of ‘Prot’
	
	protf(Pub());			//ok
	//protf(Priv());		//error
	//protf(Prot());		//error
}
