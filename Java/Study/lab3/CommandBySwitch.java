import java.util.Scanner;
public class CommandBySwitch
{
	public static void main(String[] args)
	{
		System.out.println("请输入一个命令:");
		Scanner sc = new Scanner(System.in);
		String command = sc.nextLine();
		System.out.println("输入的命令为:" + command);
	}
}
