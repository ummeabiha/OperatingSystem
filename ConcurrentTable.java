class TablePrinter extends Thread {
    private int table;

    public TablePrinter(int table) {
        this.table = table;
    }

    public void run() {
        for (int i = 1; i <= 10; i++) {
            System.out.println(Thread.currentThread().getName() + ": " + table + " * "
                    + i + " = " + (table * i));
        }
    }
}

public class ConcurrentTable {
    public static void main(String[] args) {
        TablePrinter table1Thread = new TablePrinter(2);
        TablePrinter table2Thread = new TablePrinter(5);
        table1Thread.start();
        table2Thread.start();
    }
}
