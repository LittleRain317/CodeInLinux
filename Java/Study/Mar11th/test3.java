import java.lang.Math;
public class test3
{
	public static void main(String[] args)
	{
		int [] deck= new int[52];
		for (int i = 0; i < 52; ++i)
			deck[i] = i;
		for (int i = 0; i < 52; ++i)
		{
			int temp = deck[i];
			int index = (int)(Math.random() * 52);
			deck[i] = deck[index];
			deck[index] = temp;
		}
		for (int i = 0; i < 4; ++i)
		{
			int color = deck[i] / 13;
			int num = deck[i] % 13 + 1;
			if (color == 0)
				System.out.println("是黑桃" + num);
			else if (color == 1)
				System.out.println("是红桃" + num);
			else if (color == 2)
				System.out.println("是方块" + num);
			else if (color == 3)
				System.out.println("是梅花" + num);
		}
	}
}
