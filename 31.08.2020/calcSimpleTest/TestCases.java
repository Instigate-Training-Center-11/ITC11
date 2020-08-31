package calcSimpleTest;

public class TestCases {
    public static void testAddition(int pos, int neg, int posNeg) {
        if (pos == 9) {
            System.out.println("Test for addition of positiv numbers passed");
        } else {
            System.out.println("Test addition of positiv numbers failed");
        }
        if (neg == -12) {
            System.out.println("Test for addition of negativ numbers passed");
        } else {
            System.out.println("Test for addition of negativ numbers failed");
        }
        if (posNeg == 1) {
            System.out.println("Test for addition of positiv and negativ numbers passed");
        } else {
            System.out.println("Test for addition of positiv and negativ numbers failed");
        }
    }

    public static void testSub(int pos, int neg, int posNeg) {
        if (pos == -1) {
            System.out.println("Test for sub of positiv numbers passed");
        } else {
            System.out.println("Test sub of positiv numbers failed");
        }
        if (neg == 6) {
            System.out.println("Test for sub of negativ numbers passed");
        } else {
            System.out.println("Test for sub of negativ numbers failed");
        }
        if (posNeg == -17) {
            System.out.println("Test for sub of positiv and negativ numbers passed");
        } else {
            System.out.println("Test for sub of positiv and negativ numbers failed");
        }
    }

    public static void testMul(int pos, int neg, int posNeg) {
        if (pos == 20) {
            System.out.println("Test for mult of positiv numbers passed");
        } else {
            System.out.println("Test mult of positiv numbers failed");
        }
        if (neg == 27) {
            System.out.println("Test for mult of negativ numbers passed");
        } else {
            System.out.println("Test for mult of negativ numbers failed");
        }
        if (posNeg == -72) {
            System.out.println("Test for mult of positiv and negativ numbers passed");
        } else {
            System.out.println("Test for mult of positiv and negativ numbers failed");
        }
    }

    public static void testDiv(double pos, double neg, double posNeg) {
        if (pos == 0.8) {
            System.out.println("Test for division of positiv numbers passed");
        } else {
            System.out.println("Test division of positiv numbers failed");
        }
        if (neg == 4) {
            System.out.println("Test for division of negativ numbers passed");
        } else {
            System.out.println("Test for division of negativ numbers failed");
        }
        if (posNeg == -9) {
            System.out.println("Test for division of positiv and negativ numbers passed");
        } else {
            System.out.println("Test for division of positiv and negativ numbers failed");
        }
    }
}
