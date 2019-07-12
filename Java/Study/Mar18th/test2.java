
public class test2 {

	/**
	 * @param args
	 */
	public static int[] remove(int[] ary, int index)
	{
		if (index >= ary.length)
		{	
			System.out.println("下标错误!");
			return null;
		}
		int[] arr = new int[ary.length - 1];
		for (int i = 0; i != index; ++i)
			arr[i] = ary[i];
		for (int j = index; j < arr.length; ++j)
		{
			arr[j] = ary[j + 1];
		}
		return arr;
	}
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int[] arr = {2, 3, 4, 5, 6};
		int[] result = remove(arr, 1);
		for (int i = 0; i < result.length; ++i)
			System.out.println(result[i]);
	}

}
