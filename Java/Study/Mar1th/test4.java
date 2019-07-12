import java.lang.Math;
import java.util.Scanner;
public class test4
{
	public static void main(String[] args)
	{
		System.out.println("请输入一元二次方程ax*2+bx+c=0中,a,b,c的值:");
		double a = 0.0;
		double b = 0.0;
		double c = 0.0;
		Scanner sc = new Scanner(System.in);
		a = sc.nextDouble();
		b = sc.nextDouble();
		c = sc.nextDouble();
		double deta = b * b - 4 * a * c;
		double result = (-b + Math.sqrt(deta)) / 2 * a;
		System.out.println("其中一个根结果为:" + result);
	}
}
