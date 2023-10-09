const readline = require('readline');



const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

function lerEntrada() {
    rl.question('Digite o ano: ', (valorAno) => {
        const ano = parseFloat(valorAno);
        if (isBissexto(ano)) {
        console.log(`${ano} é um ano bissexto.`);
        } else {
        console.log(`${ano} não é um ano bissexto.`);
        }
    
        rl.close();
    });
}

function isBissexto(ano) {
  if ((ano % 4 === 0 && ano % 100 !== 0) || ano % 400 === 0) {
    return true;
  } else {
    return false;
  }
}


lerEntrada();