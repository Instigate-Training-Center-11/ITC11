package singleton;

public class SingletonMain {
    public static void main(String[] args) {
        LogManager manager = LogManager.getInstance();
        manager.error();
        manager.warning();
        manager.info();
    }
}
