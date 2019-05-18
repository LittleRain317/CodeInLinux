import java.util.Scanner;
public class temperature
{
	public static void main(String[] args)
	{
		System.out.println("请输入一个华氏温度:");
		Scanner sc = new Scanner(System.in);
		double F = sc.nextDouble();
		System.out.println("对应的摄氏温度为:" + (5 / 9.0) * (F - 32));
	}
}
