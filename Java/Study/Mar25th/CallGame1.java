import java.util.Scanner;
public class CellGame {
    public static void main(String[] args) {
        //创建格子并打印
        Cell cell1 = new Cell(3,3);        
        printCell(cell1);
        //游戏控制
        System.out.println("1 —— 下落，2——向左，3——向右，0 —— 退出");
        Scanner sc = new Scanner(System.in);
        int cmd = sc.nextInt();
        while (cmd != 0) {
            switch(cmd) {                
                case 1:
                    cell1.drop();
                    break;
                case 2:
                    cell1.moveLeft();
                    break;
                case 3:
                    cell1.moveRight();
                    break;
            }            
            printCell(cell1);
            System.out.println("1 —— 下落，2——向左，3——向右，0 —— 退出");
            cmd = sc.nextInt();
        }
        System.out.println("游戏结束");
        sc.close();
    }
    public static void printCell(Cell cell) {
        int totalRow = 20;
        int totalCol = 10;
        //打印格子的位置
        System.out.println("Cell的位置为：(" + cell.getCellInfo() + ")");
        for (int row = 0; row < totalRow; row++) {
            for (int col = 0; col < totalCol; col++) {
                if (cell.row == row && cell.col == col) {
                    System.out.print("* ");
                } else {
                    System.out.print("- ");
                }
            }
            System.out.println();
        }
    }
