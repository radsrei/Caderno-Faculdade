const readline = require('readline');

const linhas = 3;
const matrizIdade = new Array(linhas);
const matrizCidade = new Array(linhas);
const matrizOp = new Array(linhas);

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

function lerMatriz() {
  let linhaAtual = 0;

  function lerProximaLinha() {
    if (linhaAtual < linhas) {
      rl.question('Digite a idade: ', (valorIdade) => {
        matrizIdade[linhaAtual] = parseFloat(valorIdade);
        
        rl.question('Digite a cidade: ', (valorCidade) => {
          matrizCidade[linhaAtual] = valorCidade;
          
          rl.question('Digite a opinião de 1 a 3: ', (valorOp) => {
            matrizOp[linhaAtual] = parseFloat(valorOp);
            
            linhaAtual++;
            lerProximaLinha();
          });
        });
      });
    } else {
      rl.close();
      exibirMatriz();
      mdOtimo();
      contRegular();
      perRegular();
      perCidade();
    }
  }

  lerProximaLinha();
}

function exibirMatriz() {
  console.log("Matriz lida:");
  for (let i = 0; i < linhas; i++) {
    console.log(`Idade: ${matrizIdade[i]}, Cidade: ${matrizCidade[i]}, Opinião: ${matrizOp[i]}`);
  }
}

function mdOtimo() {
  let media = 0;
  let cont = 0;
  for (let i = 0; i < linhas; i++) {
    if (matrizOp[i] === 3) {
      media += matrizIdade[i];
      cont++;
    }
  }
  console.log(`Média das idades dos leitores com Opinião Ótimo: ${media / cont}`);
}

function contRegular() {
  let cont = 0;
  for (let i = 0; i < linhas; i++) {
    if (matrizOp[i] === 1) {
      cont++;
    }
  }
  console.log('Número de regulares: ' + cont);
}

function perRegular() {
  let cont = 0;
  for (let i = 0; i < linhas; i++) {
    if (matrizOp[i] === 2) {
      cont++;
    }
  }
  console.log('Valor de Porcentagem Bom: ' + (cont / linhas) * 100 + '%');
}

function perCidade() {
  const cidades = {};

  for (let i = 0; i < linhas; i++) {
    if (matrizCidade[i] in cidades) {
      cidades[matrizCidade[i]]++;
    } else {
      cidades[matrizCidade[i]] = 1;
    }
  }

  console.log('Porcentagem de pessoas em cada cidade:');
  for (const cidade in cidades) {
    const porcentagem = (cidades[cidade] / linhas) * 100;
    console.log(`${cidade}: ${porcentagem}%`);
  }
}

lerMatriz();
