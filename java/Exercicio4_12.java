class TestaConta{
	public static void main(String[] args)
	{
		Conta c1 = new Conta();
		c1.titular = "João";
		c1.numero = 123;
		c1.agencia = "Porto";
		c1.saldo = 1000;
		c1.dataAbertura.setData(20,1,1999);
//		System.out.println("Saldo: "+c1.saldo);

		c1.saca(200);
//		System.out.println("Saldo: "+c1.saldo);
		c1.deposito(500);
//		System.out.println("Saldo: "+c1.saldo);
//		System.out.println("Rendimento: "+c1.calculaRendimento());
		System.out.println(c1.recuperaDadosParaImpressao());				
		

		Conta c2 = new Conta();
		c2.titular = "Danilo";
		c2.saldo = 100;

		
		Conta c3 = new Conta();
		c3.titular = "Danilo";
		c3.saldo = 100;

		
		if(c2 == c3 ){
			System.out.println("iguais");
		} else {
			System.out.println("diferentes");
		}

		Conta c4 = c2;
		
		if(c2 == c4 ){
			System.out.println("iguais");
		} else {
			System.out.println("diferentes");
		}
	}
}



class Conta{
	String titular;
	int numero;
	String agencia;
	double saldo;
	Data dataAbertura = new Data();
	
	void saca(double valor)
	{
		this.saldo -= valor;	
	}
	void deposito(double valor)
	{
		this.saldo += valor;
	}
	double calculaRendimento()
	{
		return this.saldo*0.1;	
	}
	String recuperaDadosParaImpressao()
	{
		String dados = "Titular: " + this.titular;
		dados += "\nNumero: " + this.numero;
		dados += "\nAgencia: " + this.agencia;
		dados += "\nSaldo: " + this.saldo;
		dados += "\nData de Abertura: " + this.dataAbertura.getData();
		dados += "\nRedimento: " + this.calculaRendimento();
		return dados;
	
	}
}

class Data{

	int dia;
	int mes;
	int ano;

	void setData(int d, int m, int a)
	{
		this.dia = d;
		this.mes = m;
		this.ano = a;	
	
	}
	String getData(){
	
		String data = this.dia+"/"+this.mes+"/"+this.ano;
		return data;
	}
}
