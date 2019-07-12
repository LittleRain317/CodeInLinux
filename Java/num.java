import java.util.Scanner;
public class num
{
	public static void main(String[] args)
	{
		Scanner sc = new Scanner(System.in);
		System.out.println("请输入一个double型数:");
		double number = sc.nextDouble();
		System.out.println("这个数的整数部分为:" + (int)number);
		System.out.println("这个数的小数部分为:" + (number - (int)number));
	}
}
