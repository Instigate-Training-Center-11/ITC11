public class RunTests {
    public static void main(String[] args) {
        try {
            TestCalculator.test();
        } catch (Exception ex) {
            System.out.println(ex.toString());
        }
    }
}
