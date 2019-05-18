public class Average {
	public static void main(String[] args) {
		int N = Integer.parseInt(args[0]);
		double sum = 0;
		int i = 1;
		while (i <= N) {
			sum += Integer.parseInt(args[i]);
			i++;
		}
		double avg = sum / N;
		System.out.println("Average:" + avg);
	}
}
