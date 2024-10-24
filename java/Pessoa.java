class Pessoa{
	public static void main(String[] args)
	{
		Pessoa p1 = new Pessoa();
		p1.nome = "Joao";
		p1.idade = 20;
		p1.fazAniversario();
		p1.fazAniversario();
		p1.fazAniversario();
		System.out.println("Idade de "+p1.nome+" é: "+p1.idade);
	}
		
	
	String nome;
	int idade;

	void fazAniversario()
	{
		this.idade++;	
	}
	
}
