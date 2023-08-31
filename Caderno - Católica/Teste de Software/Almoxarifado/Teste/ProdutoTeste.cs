namespace Teste
{
    /*
     Eu, como almoxarife, preciso cadastrar produtos para que sejam
    consumidos pelos funcion�rios da empresa

    Crit�rios de Aceite:
    - Um novo produto deve ter obrigatoriamente um codigo �nico, nome, saldo 0, custo 0 e unidade de medida
    - As unidades de medida s�o: Pc, kg, m, g, l, cx
    - Um produto pode ter uma descri��o
    - Um produto pode ter um c�digo de barras EAN
    */
    public class ProdutoTeste
    {

        [Fact]//Testado apenas uma vez
        public void CriarObjeto()
        {
            // Arrange - prepara cen�rio
            int codigo = 1;
            string nome = "Mouse", medida = "PC";
            float saldo = 0, custo = 0;

            // Act - execu��o
            Produto prod = new Produto(codigo, nome, medida, saldo, custo);

            // Assert - resultado
            Assert.Equal(codigo, prod.Codigo);
            Assert.Equal(nome, prod.Nome);
            Assert.Equal(medida, prod.Medida);
            Assert.Equal(custo, prod.Custo);
            Assert.Equal(saldo, prod.Saldo);
        }

        // C�digo �nico, nome, saldo 0, custo 0 e unidade de medida
        [Theory]//Passa v�rias possibilidades de vari�veis
    }

    public class Produto
    {
        public Produto(int codigo, string nome, string medida, float saldo, float custo)
        {
            Codigo = codigo;
            Nome = nome;
            Medida = medida;
            Saldo = saldo;
            Custo = custo;
        }

        public int Codigo { get; }
        public string Nome { get; }
        public string Medida { get; }
        public float Saldo { get; }
        public float Custo { get; }
    }
}