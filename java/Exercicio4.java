class Exercicio4{
	public static void main(String[] args)
	{	
		long resultado;
		for(int i=1;i<=20;i++)
		{	
			resultado = 1;
			for(int j=i; j>0;j--)
			{
				resultado = resultado * j;			
			}
			System.out.println("Fatorial de "+i+" : "+resultado);
		}
	
	}


}
