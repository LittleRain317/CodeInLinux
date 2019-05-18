public class test7
{
	public static void main(String[] args)
	{
		long startTime = System.nanoTime();
		for (int i = 0; i < 10000; ++i)
			;
		long endTime = System.nanoTime();
		System.out.println("程序运行时间为:" + (endTime - startTime) + "ns");
	}
}
