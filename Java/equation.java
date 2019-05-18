import java.lang.Math;
import java.util.Scanner;
public class equation
{
	public static void main(String[] args)
	{
		double a = 0.0;
		double b = 0.0;
		double c = 0.0;
		System.out.println("请输入一元二次方程ax*2 + bx + c = 0中的a，b，c的值:");
		Scanner sc = new Scanner(System.in);
		a = sc.nextDouble();
		b = sc.nextDouble();
		c = sc.nextDouble();
		double delta = b * b - 4 * a * c;
		if (delta < 0)
			System.out.println("该方程无解!");
		else
			System.out.println("该方程其中一个解为:" + (-b + Math.sqrt(delta)) / (2 * a));
	}
}
