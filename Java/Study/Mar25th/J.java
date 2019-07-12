package oopday02;

public class J extends Tetromino{
	
	J(){
		this(0,0);
	}
	J(int row,int col){
		//cells=new Cell[4];
		super();
		cells[0]=new Cell(row,col);
		cells[1]=new Cell(row+1,col);
		cells[2]=new Cell(row+2,col);
		cells[3]=new Cell(row+2,col-1);			
	}
	

}
