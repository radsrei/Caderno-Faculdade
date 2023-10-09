const readline = require('readline');

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

let custo = 0;
function lerEntrada() {
    rl.question('Diga o valor: ', (consumoValor) => {
        const consumo = parseFloat(consumoValor);
        if(consumo >= 20){
            custo = consumo * 1.6;
        }else if(consumo>21 && consumo<=50){
            custo = consumo * 2.8;
        }else if(consumo>50){
            custo = consumo * 4.2;
        }
    rl.close();
    });
}

lerEntrada();