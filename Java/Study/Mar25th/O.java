public class O {
    Cell[] cells;// 属性,用来存储一个方块的四个格子的坐标
    publicO() {
        this(0, 0);
    }
    public O(int row, int col) {
        cells = new Cell[4];
        // 按顺时针方向初始化Cell
        cells[0] = new Cell(row, col);
        cells[1] = new Cell(row, col + 1);
        cells[2] = new Cell(row + 1, col);
        cells[3] = new Cell(row + 1, col + 1);
    }
    public void print() {
        String str = "";
        for (int i = 0; i < cells.length - 1; i++) {
            str += "(" + cells[i].getCellInfo() + "), ";
        }
        str += "(" + cells[cells.length - 1].getCellInfo() + ")";
        System.out.println(str);
    }
    public void drop() {
        for (int i = 0; i < cells.length; i++) {
            cells[i].row++;
        }
    }
    public void moveLeft() {
        for (int i = 0; i < cells.length; i++) {
            cells[i].col--;
        }
    }
    public void moveRight() {
       for (int i = 0; i < cells.length; i++) {
            cells[i].col++;
        }
    }
}
