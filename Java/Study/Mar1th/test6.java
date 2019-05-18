import java.util.Scanner;
public class test6
{
	public static void main(String[] args)
	{
		System.out.println("请输入你的体重:(公斤)和身高(米)");
		Scanner sc = new Scanner(System.in);
		double weight = sc.nextDouble();
		double height = sc.nextDouble();
		double BMI = weight / (height * height);
		System.out.println("BMI的值为:" + BMI);
	}
}
