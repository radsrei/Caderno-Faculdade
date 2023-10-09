const readline = require('readline');

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

function calcularDesc(total) {
  return total * 0.05;
}

const listaCarne = ['File Duplo', 'Alcatra', 'Picanha'];

rl.question('Digite o tipo de carne (1-File Duplo, 2-Alcatra ou 3-Picanha): ', (tipoCarne) => {
  rl.question('Digite a quantidade em Kg: ', (quantidadeKg) => {
    rl.question('A compra foi feita no cartão Tabajara? (S para Sim, N para Não): ', (pagamentoCartao) => {
      const carne = parseInt(tipoCarne);
      const quantidade = parseFloat(quantidadeKg);

      let precoPorKg;
      switch (carne) {
        case 1:
          precoPorKg = (quantidade <= 5) ? 24.9 : 25.8;
          break;
        case 2:
          precoPorKg = (quantidade <= 5) ? 25.9 : 26.8;
          break;
        case 3:
          precoPorKg = (quantidade <= 5) ? 36.9 : 37.8;
          break;
        default:
          console.log('Tipo de carne inválido');
          rl.close();
          return;
      }
      const precoTotal = quantidade * precoPorKg;

      let desconto = 0;
      if (pagamentoCartao.toLowerCase() === 's') {
        desconto = calcularDesc(precoTotal);
      }

      const valorAPagar = precoTotal - desconto;

      console.log('Cupom Fiscal:');
      console.log(`Tipo de Carne: ${listaCarne[carne - 1]}`);
      console.log(`Quantidade: ${quantidadeKg} Kg`);
      console.log(`Preço Total: R$ ${precoTotal.toFixed(2)}`);
      console.log(`Tipo de Pagamento: ${pagamentoCartao}`);
      console.log(`Desconto: R$ ${desconto.toFixed(2)}`);
      console.log(`Valor a Pagar: R$ ${valorAPagar.toFixed(2)}`);

      rl.close();
    });
  });
});
