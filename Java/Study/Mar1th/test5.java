import java.util.Scanner;
public class test5
{
	public static void main(String[] args)
	{
		System.out.println("请输入一个华氏温度:");
		Scanner sc = new Scanner(System.in);
		double fc = sc.nextDouble();
		System.out.println("对应的摄氏温度为:" + (5.0 / 9 * (fc - 32)));
	}
}
