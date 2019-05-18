package oopday02;

public class TJTest {

	public static void main(String[] args) {
		T t=new T(2,5);
		t.drop();
		//printWall(t);
		J j=new J(5,6);
		printWall(j);
	}
	/*public static void printWall(J t){
		for(int i=0;i<20;i++){
			for(int j=0;j<10;j++){
				for(int k=0;k<t.cells.length;k++)
				if(i==t.cells[k].row&&j==t.cells[k].col){
					System.out.print("* ");
					break;
				}else if(k==t.cells.length-1){
					System.out.print("- ");
				}
				
			}
			System.out.println();
		}
	}*/
	/*public static void printWall(T t){
		for(int i=0;i<20;i++){
			for(int j=0;j<10;j++){
				boolean flag=false;//1假设打-
				for(int k=0;k<t.cells.length;k++){
				if(i==t.cells[k].row&&j==t.cells[k].col){
					flag=true;//2修改为打*
					break;
				}
			}
			if(flag){//3判断得结果
				System.out.print("* ");
			}else {
				System.out.print("- ");
			}
			
		}
			System.out.println();
		}
	}
}*/
public static void printWall(Tetromino t){
	for(int i=0;i<20;i++){
		for(int j=0;j<10;j++){
			 if(t.cells[0].row==i&&t.cells[0].col==j  
					 || 
				t.cells[1].row==i&&t.cells[1].col==j
				     ||
				t.cells[2].row==i&&t.cells[2].col==j  
					 || 
				t.cells[3].row==i&&t.cells[3].col==j){
				 System.out.print("* ");
			 }else{
				 System.out.print("- ");
			 }
			 
	}
		System.out.println();
	}
}
}
