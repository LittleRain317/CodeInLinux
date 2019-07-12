import java.lang.Math;
public class test3 {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		double[] arr = new double[10];
		arr[9] = 5.8;
		System.out.println("该数组前两个元素和为:" + (arr[0] + arr[1]));
		double sum = 0.0;
		for (int i = 0; i != 10; ++i)
			sum += arr[i];
		double min = arr[0];
		for (int i = 1; i != 10; ++i)
			if (arr[i] < min)
				min = arr[i];
		int index = (int)(Math.random() * 10);
		System.out.println(index + "上元素为:" + arr[index]);
		double[] arr2 = {3.5, 5.5, 4.52, 6.6};
	}

}
