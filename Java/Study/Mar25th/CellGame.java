public class CellGame{
    public static void main(String[] args) {
        System.out.println("----------绘制Cell----------");
        Cell cell1 = new Cell(15,3);        
        printCell(cell1);
        System.out.println("----------右移 1 列----------");
        cell1.moveRight();
        printCell(cell1);
        System.out.println("----------右移 4 列----------");
        cell1.moveRight(4);
        printCell(cell1);
    }
    public static void printCell(Cell cell) {
        int totalRow = 20;
        int totalCol = 10;
        //打印场地
        for (int row = 0; row < totalRow; row++) {
            for (int col = 0; col < totalCol; col++) {
                if (cell.row == row && cell.col == col) {
                    //打印指定的格子
                    System.out.print("* ");
                } else {
                    System.out.print("- ");
                }
            }
            System.out.println();
        }
    }
}
