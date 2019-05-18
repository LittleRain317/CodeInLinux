
public class test5 {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int[][] score = new int[5][4];
		score[0][0] = 80;
		score[0][1] = 75;
		score[0][2] = 78;
		score[0][3] = 93;
		score[1][0] = 67;
		score[1][1] = 87;
		score[1][2] = 98;
		score[1][3] = 65;
		score[2][0] = 86;
		score[2][1] = 72;
		score[2][2] = 60;
		score[2][3] = 76;
		score[3][0] = 76;
		score[3][1] = 80;
		score[3][2] = 76;
		score[3][3] = 63;
		score[4][0] = 82;
		score[4][1] = 70;
		score[4][2] = 90;
		score[4][3] = 67;
		int sumScoreOfStudent = 0;
		int maxScoreOfStudent = 0;
		int maxScoreOfStudentIndex = 0;
		int maxScoreOfSubject = 0;
		int maxScoreOfSubjectIndex = 0;
		int i = 0;
		int j = 0;
		for (i = 0; i != 5; ++i)
		{	
			sumScoreOfStudent = 0;
			for (j = 0; j != 4; ++j)
			{	
				sumScoreOfStudent += score[i][j];
			}
			if (maxScoreOfStudent < sumScoreOfStudent)
			{	
				maxScoreOfStudent = sumScoreOfStudent;
				maxScoreOfStudentIndex = i + 1;
			}
			System.out.println("第" + (i + 1) + "名同学的总成绩为:" + sumScoreOfStudent);
		}
		System.out.println("总成绩最高胡行号为:" + maxScoreOfStudentIndex + " 成绩为:" + maxScoreOfStudent);
		for (i = 0; i != 4; ++i)
		{	
			maxScoreOfSubject = 0;
			maxScoreOfSubjectIndex = 0;
			for (j = 0; j != 5; ++j)
			{
				if (maxScoreOfSubject < score[j][i])
				{
					maxScoreOfSubject = score[j][i];
					maxScoreOfSubjectIndex = j + 1;
				}
			}
			System.out.println("科目" + (i + 1) + " 中最高分为:" + maxScoreOfSubject + " 在第" + maxScoreOfSubjectIndex + "行");
		}
	}
}
