class MyThread extends Thread {
    public void run() {
        for (int i = 0; i < 5; i++) {
            System.out.println(Thread.currentThread().getName() + " Count: " + i);
        }
    }
}

public class ThreadPriority {
    public static void main(String[] args) {
        MyThread thread1 = new MyThread();
        MyThread thread2 = new MyThread();
        System.out.println("Default Priority of Thread 1: " + thread1.getPriority());
        System.out.println("Default Priority of Thread 2: " + thread2.getPriority());
        thread1.setPriority(Thread.MIN_PRIORITY);
        thread2.setPriority(Thread.MAX_PRIORITY);
        System.out.println("Updated Priority of Thread 1: " + thread1.getPriority());
        System.out.println("Updated Priority of Thread 2: " + thread2.getPriority());
        thread1.start();
        thread2.start();
    }
}
