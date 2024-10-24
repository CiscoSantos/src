class Conta{
//	private String titular;
//	private double saldo;
//	private int conta;

	private String titular;
	private int numeroConta;
	private String agencia;
	private double saldo;
	Data dataAbertura = new Data();
	private static int contador = 0;
	private int identificador;

	public Conta()
	{
		identificador = ++contador;
	}
	
	public Conta(String titular)
	{
		this.titular = titular;	
		identificador = ++contador;
	}
        public int getContador(){
                return this.contador;
        }

/*        public void addContador(){
                contador++;
        }*/

	public int getIdentificador(){
		return this.identificador;
	}

	public double getSaldo(){
		return this.saldo;
	}

	public void setSaldo(double sd){
		this.saldo = sd;
	}

	public String getTitular(){
		return this.titular;
	}

	public void setTitular(String titula){
		this.titular = titula;
	}
	
	public int getConta(){
		return this.numeroConta;
	}
	public void setConta(int cont){
		this.numeroConta = cont;	
	}
	
	public void setAgencia(String agenc){
		this.agencia = agenc;	
	}
	public String getAgencia(){
		return this.agencia;
	}

	public double calculaRendimento()
        {
                return this.saldo*0.1;
        }

	public void saca(double valor)
	{
		this.saldo -= valor;	
	}
	
	public void deposito(double valor)
	{
		this.saldo += valor;
	}
	
	public String recuperaDadosParaImpressao()
        {
                String dados = "Titular: " + this.titular;
                dados += "\nNumero: " + this.numeroConta;
                dados += "\nAgencia: " + this.agencia;
                dados += "\nSaldo: " + this.saldo;
                dados += "\nData de Abertura: " + this.dataAbertura.getData();
                dados += "\nRedimento: " + this.calculaRendimento();
                return dados;
        }
	

}

class Data{

        private int dia;
        private int mes;
        private int ano;

        public void setData(int d, int m, int a)
        {
                this.dia = d;
                this.mes = m;
                this.ano = a;

        }
        public String getData(){

                String data = this.dia+"/"+this.mes+"/"+this.ano;
                return data;
        }
}

class TestaConta{
	public static void main(String[] args)
	{
		Conta c1 = new Conta("João");
//		c1.setTitular("João");
		c1.setConta(123);
		c1.setAgencia("Porto");
		c1.setSaldo(1000);
		c1.dataAbertura.setData(20,1,1999);
//		System.out.println("Saldo: "+c1.saldo);

		c1.saca(200);
//		System.out.println("Saldo: "+c1.saldo);
		c1.deposito(500);
//		System.out.println("Saldo: "+c1.saldo);
//		System.out.println("Rendimento: "+c1.calculaRendimento());
		System.out.println(c1.recuperaDadosParaImpressao());				
		

		Conta c2 = new Conta("Danilo");
//		c2.setTitular("Danilo");
		c2.setSaldo(100);

		
		Conta c3 = new Conta("Danilo");
//		c3.setTitular("Danilo");
		c3.setSaldo(100);

		
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

		System.out.println("C1: "+c1.getIdentificador()+" - C2: "+c2.getIdentificador()+" - C3: "+c3.getIdentificador());
		System.out.println(c1.getContador());
	}
}

