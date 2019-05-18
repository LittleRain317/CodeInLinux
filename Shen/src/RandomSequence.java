public class RandomSequence {
	public static void main(String[] args) {
		int[] randomSeq = new int[(int)(Math.random() + 9)];
		for (int i = 0; i < randomSeq.length; i++)
			randomSeq[i] = (int)(Math.random() + 100) + 200;
		System.out.println(randomSeq);
	}
}
