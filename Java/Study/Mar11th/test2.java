public class test2
{
	public static long GetANumberAboutNine(int n)
	{
		String num = "";
		for (int i = 0; i < n; ++i)
			num += "9";
		return Long.parseLong(num);
	}
	public static void main(String[] args)
	{
		long sum = 0L;
		for (int i = 1; i <= 10; ++i)
			sum += GetANumberAboutNine(i);
		System.out.println(sum);
	}
}
