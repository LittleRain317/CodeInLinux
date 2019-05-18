import java.util.Scanner;
public class ScoreLevel
{
	public static void main(String[] args)
	{
		System.out.println("请输入成绩:");
		Scanner sc = new Scanner(System.in);
		double score = sc.nextDouble();
		switch ((int)score / 10)
		{
			case 0:
			case 1:
			case 2:
			case 3:
			case 4:
			case 5:
				System.out.println("不及格!");
				break;
			case 6:
				System.out.println("及格!");
				break;
			case 7:
				System.out.println("中!");
				break;
			case 8:
				System.out.println("良!");
				break;
			case 9:
				System.out.println("优!");
				break;
			case 10:
				System.out.println("满分!");
				break;
		}
	}
}
