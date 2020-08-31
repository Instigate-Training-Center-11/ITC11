package calcSimpleTest;

public class Calculator {

    public static int add(int num, int num2) {
        return num + num2;
    }
    public static int sub(int num, int num2) {
        return num - num2;
    }
    public static int mul(int num, int num2) {
        return num * num2;
    }
    public static double div(double num, double num2) {
        if (num2 == 0) {
            throw new IllegalArgumentException("You can't to divide by zero.");
        }
        return num / num2;
    }


}
