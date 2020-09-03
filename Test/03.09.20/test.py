import unittest 
import calculator
  
class Calculate(unittest.TestCase): 

    def test_sum_1(self):
        self.assertEqual(calculator.sum(2,5), 7)

    def test_sum_2(self):
        self.assertEqual(calculator.sum(5.7,-88), -82.3)
      
    def test_minus_1(self):
        self.assertEqual(calculator.minus(2,5), -3)

    def test_minus_2(self):
        self.assertEqual(calculator.minus(1,99999999999999999999999), -99999999999999999999998)
  
    def test_bazmap_1(self):
        self.assertEqual(calculator.bazmap(2,5), 10)

    def test_bazmap_2(self):
        self.assertEqual(calculator.bazmap(999999999999999999999999,122222222222222222), 122222222222222221999999877777777777777778)

    def test_tokos_1(self):
        self.assertEqual(calculator.tokos(2,5), 2)

    def test_tokos_2(self):
        self.assertEqual(calculator.tokos(20,5), 0)
    
