class Porta
{
	boolean aberta;
	String cor;
	double dimensaoX, dimensaoY, dimensaoZ;
	
	void abre()
	{
		this.aberta = true;	
	} 
	
	void fecha()
	{
		this.aberta = false;
	}
	void pinta(String s)
	{
		cor = s;
	}
	boolean estaAberta()
	{
		return this.aberta;
	}
	
	public static void main(String[] args)
	{
		Porta p1 = new Porta();

		p1.fecha();
		p1.dimensaoX = 1;
		p1.dimensaoY = 2.5;
		p1.dimensaoZ = 0.03;

		if (p1.aberta == true){
		       	System.out.print("A porta está aberta.");
		}else  {
			System.out.print("A porta está fechada.");
		}

	}

}
