package singleton;

public class Main {
    public static void main(String[] args) {
        //We have two instance but one object
        LogManager logManager1 = LogManager.getInstance();
        LogManager logManager2 = LogManager.getInstance();
        logManager1.errorLog("error");
        logManager1.warningLog("warning");
        logManager1.infoLog("info");
    }
}
