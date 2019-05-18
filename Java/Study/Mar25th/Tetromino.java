package oopday02;

public class Tetromino {
	Cell[] cells;
	Tetromino(){
		cells=new Cell[4];
	}
	void drop(){
		for(int i=0;i<cells.length;i++){
			cells[i].drop();
		}
	}
	void moveLeft(){
		for(int i=0;i<cells.length;i++){
			cells[i].moveLeft();
		}
	}
	void moveRight(){
		for(int i=0;i<cells.length;i++){
			cells[i].moveRight();
		}
	}
	void print(){
		for(int i=0;i<cells.length;i++){
			System.out.println(cells[i].getCellInfo());
		}
		
	}

}
