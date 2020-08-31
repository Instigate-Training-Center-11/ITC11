package calcSimpleTest;

public class MainClassTest {

    public static void main(String[] args) {
        int pos = Calculator.add(4, 5);
        int neg = Calculator.add(-3, -9);
        int posNeg = Calculator.add(-8, 9);

        int posSub = Calculator.sub(4, 5);
        int negSub = Calculator.sub(-3, -9);
        int posNegSub = Calculator.sub(-8, 9);

        int posMul = Calculator.mul(4, 5);
        int negMul = Calculator.mul(-3, -9);
        int posNegMul = Calculator.mul(-8, 9);

        double posDiv = Calculator.div(4, 5);
        double negDiv = Calculator.div(-36, -9);
        double posNegDiv = Calculator.div(-81, 9);

        //See an example for div by zero bellow please.
        //double posNegDiv = Calculator.div(-81, 0);

        TestCases.testAddition(pos, neg, posNeg);
        TestCases.testSub(posSub, negSub, posNegSub);
        TestCases.testMul(posMul, negMul, posNegMul);
        TestCases.testDiv(posDiv, negDiv, posNegDiv);
    }
}