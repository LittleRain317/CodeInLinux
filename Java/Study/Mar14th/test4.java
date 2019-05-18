
public class test4 {

	/**
	 * @param args
	 */
	public static int[] sumArray(int[] a, int[] b){
		int shortLength = 0;
		int longLength = 0;
		boolean aIsLong = false;
		boolean bIsLong = false;
		if (a.length > b.length)
		{
			shortLength = b.length;
			longLength = a.length;
			aIsLong = true;
		}
		else
		{
			shortLength = a.length;
			longLength = b.length;
			bIsLong = true;
		}
		int[] sum = new int[longLength];
		for (int i = 0; i != shortLength; ++i)
			sum[i] = a[i] + b[i];
		for (int i = shortLength; i != longLength; ++i)
		{
			if (aIsLong)
				sum[i] = a[i];
			else
				sum[i] = b[i];
		}
		return sum;
	}
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int[] a = {1, 2, 4};
		int[] b = {2, 4, 6, 8};
		int[] sum = sumArray(a, b);
		for (int i = 0; i != sum.length; ++i)
			System.out.println(sum[i]);
	}

}
