namespace Teste
{
    /*
     Eu, como almoxarife, preciso cadastrar produtos para que sejam
    consumidos pelos funcionários da empresa

    Critérios de Aceite:
    - Um novo produto deve ter obrigatoriamente um codigo único, nome, saldo 0, custo 0 e unidade de medida
    - As unidades de medida são: Pc, kg, m, g, l, cx
    - Um produto pode ter uma descrição
    - Um produto pode ter um código de barras EAN
    */
    public class ProdutoTeste
    {

        [Fact]//Testado apenas uma vez
        public void CriarObjeto()
        {
            // Arrange - prepara cenário
            int codigo = 1;
            string nome = "Mouse", medida = "PC";
            float saldo = 0, custo = 0;

            // Act - execução
            Produto prod = new Produto(codigo, nome, medida, saldo, custo);

            // Assert - resultado
            Assert.Equal(codigo, prod.Codigo);
            Assert.Equal(nome, prod.Nome);
            Assert.Equal(medida, prod.Medida);
            Assert.Equal(custo, prod.Custo);
            Assert.Equal(saldo, prod.Saldo);
        }

        // Código único, nome, saldo 0, custo 0 e unidade de medida
        [Theory]//Passa várias possibilidades de variáveis
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