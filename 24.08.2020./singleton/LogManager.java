package singleton;

public class LogManager {
    private static LogManager instance = null;
    private LogManager() {
        System.out.println("The object is created");
    }
    public static LogManager getInstance() {
        if (instance == null) {
            instance = new LogManager();
        }
            return instance;
        }

    public void error() {
        System.err.println("Error message");
    }

    public void warning() {
        System.out.println("Some warning");
    }

    public void info() {
        System.out.println("Some information");
    }
}
