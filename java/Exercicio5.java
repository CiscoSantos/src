class Exercicio5{
	public static void main(String[] args){

		int fibo_1=0;
		int fibo_2=1;
		while(fibo_2 < 100)
		{	
			System.out.println(fibo_2);
			int temp = fibo_2;
			fibo_2 = fibo_2 + fibo_1;
			fibo_1 = temp;
		}
	
	
	}



}
