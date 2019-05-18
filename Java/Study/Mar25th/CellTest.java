package oopday02;

public class CellTest {

	public static void main(String[] args) {
		Cell c=new Cell(5);
		System.out.println(c.getCellInfo());
		Cell[] cells=new Cell[]{
				new Cell(1,2),
				new Cell(2,3),
				new Cell(1,4),
				new Cell(5,6)};
		
		Cell cc=new Cell(3,6);
		c.drop();
		int[][] arr=new int[3][];
		arr[0]=new int[2];
		arr[1]=new int[3];
		arr[2]=new int[2];
		arr[1][1]=100;
		int[][] arr1=new int[3][4];
		
		
		arr[1][1]=100;
		
		printWall(cc);

	}
	public static void printWall(Cell c){
		for(int i=0;i<20;i++){
			for(int j=0;j<10;j++){
				if(i==c.row&&j==c.col){
					System.out.print("* ");
				}else{
					System.out.print("- ");
				}
				
			}
			System.out.println();
		}
	}

}
