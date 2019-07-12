import java.util.Scanner;
public class BMI
{
	public static void main(String[] args)
	{
		System.out.println("请输入你的体重(公斤)及身高(米):");
		Scanner sc = new Scanner(System.in);
		double weight = sc.nextDouble();	
		double height = sc.nextDouble();
		System.out.println("你的BMI值为:" + weight / (height * height));
	}
}
