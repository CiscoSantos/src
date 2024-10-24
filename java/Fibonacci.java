
class Fibonacci{
 	public static void main (String[] args){
 	Fibonacci fibonacci = new Fibonacci();
     	for (int i = 1; i <= 10; i++) {
	int resultado = fibonacci.calculaFibonacci(i);
	System.out.println(resultado);
     	}
 	}
     int calculaFibonacci(int n)
     {
     	return 	(n <= 1) ? n : calculaFibonacci(n-1)+calculaFibonacci(n-2);
     }
}
