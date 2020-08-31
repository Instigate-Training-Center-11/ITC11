public class TestCalculator {
    private static void testSum() throws Exception {
        if (Calculator.sum(-3, 3) != 0 || Calculator.sum(0, 3) != 3) {
            System.out.println("Method sum not working!");
        }
    }

    private static void testMultiply() throws Exception {
        if(Calculator.multiply(0, 1) != 0 || Calculator.multiply(1,1) != 1) {
            System.out.println("Method multiply not working!");
        }
    }

    private static void testRemainder() throws Exception {
        if(Calculator.remainder(5, 2) != 1 || Calculator.remainder(1,1) != 0) {
            System.out.println("Method remainder not working!");
        }
    }

    private static void testSubtract() throws Exception {
        if(Calculator.subtract(5, 2) != 3 || Calculator.subtract(1,1) != 0) {
            System.out.println("Method subtract not working!");
        }
    }

    public static void test() throws Exception{
        testSum();
        testMultiply();
        testRemainder();
        testSubtract();
    }
}
