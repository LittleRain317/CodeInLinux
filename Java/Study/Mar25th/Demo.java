package oopday02;

public class Demo {
	public static void main(String[] args) {
		Aoo o=new Aoo();
		String name="zhangsan";
		
	}

}
class Aoo{
	int a;
	void say(){}
	void say(String name){return;}
	void say(int age){}
	void say(String name,int age){}
	void say(int age,String name){}
	//void say(String address){}
}
class Boo extends Aoo{
	int b;
}
class Coo extends Boo{
	int c;
}