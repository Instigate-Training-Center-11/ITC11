package singleton;

//public class Singleton {
//    public static Singleton instance = new Singleton();
//    private Singleton() {}
//}


//with lazy initialization
public class LogManager {
    private static LogManager instance = null;
    private LogManager() {
        System.out.println("Created object!");
    }
    public static LogManager getInstance() {
        if(instance == null) {
            instance = new LogManager();
        }
        return instance;
    }

    public void errorLog(String str) {
        System.err.println(str);
    }

    public void warningLog(String str) {
        System.out.println("Warning :" + str);
    }

    public void infoLog(String str) {
        System.out.println(str);
    }
}

