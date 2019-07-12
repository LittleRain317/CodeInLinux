import java.util.Scanner;
public class test1
{
	public static void main(String[] args)
	{
		System.out.println("请输入一个小数:");
		double num = 0.0;
		Scanner sc = new Scanner(System.in);
		num = sc.nextDouble();
		System.out.println("它的整数部分是:" + (int)num + "，它的小数部分是:" + (num - (int)num));
	}
}
