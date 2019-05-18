public class TestO {
    public static void main(String[] args) {
        O o=new O(0,5);
        System.out.println("原始坐标为：");
        o.print();
        o.moveLeft();
        System.out.println("调用moveLeft方法后的坐标：");
        o.print();
        o.moveRight();
        System.out.println("调用moveRight方法后的坐标：");
        o.print();
    }
}
