import java.util.Scanner;
public class test1
{
	public static void main(String[] args)
	{
		System.out.println("请输入n的值将计算1/1 + 1/2 + 1/3 + ... + 1/n的结果.");
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		double sum = 0.0;
		for (int i = 1; i <= n; ++i)
			sum += 1.0 / i;
		System.out.println("结果为:" + sum);
		
	}
}
