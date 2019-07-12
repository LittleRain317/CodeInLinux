
public class test1 {

	/**
	 * @param args
	 */
	public static long f(int n)
	{
//		if (1 == n || 2 == n)
//			return 1L;
//		else
//			return f(n - 1) + f(n - 2);
		if (1 == n || 2 == n)
			return 1L;
		long last = 1L;
		long next = 1L;
		long sum = 0L;
		for (int i = 3; i <= n; ++i)
		{	
			sum = last + next;
			last = next;
			next = sum;
		}
		return next;
	}
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		System.out.println("黄金比例:" + ((double)f(45) / f(46)));
	}
}
