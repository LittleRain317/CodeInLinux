import java.util.Scanner;
public class AgeRange
{
	public static void main(String[] args)
	{
		System.out.println("请输入年龄:");
		int age = 0;
		Scanner sc = new Scanner(System.in);
		age = sc.nextInt();
		if (age < 0 || age > 110)
		{
			System.out.println("年龄过小或过大!");
		}
		else
			System.out.println("输入的年龄为:" + age);
	}
}
