const readline = require('readline');

const linhas = 5;
const nota = new Array(linhas);


const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

function lerMatriz() {
  let linhaAtual = 0;

  function lerProximaLinha() {
    if (linhaAtual < linhas) {
      rl.question('Digite a nota: ', (valorNota) => {
        nota[linhaAtual] = parseFloat(valorNota);
        linhaAtual++;
        lerProximaLinha();
      });
    } else {
      rl.close();
      mostraResult();
    }
  }

  lerProximaLinha();
}
function mostraResult() {
  console.log("Resultado do Candidato:");
    if (nota[0]>=7 && nota[1]>=7 && nota[2]>=7 && nota[3]>=7 && nota[4]>=7) {
      console.log("Aprovação tipo A");
    }else if (nota[0]>=7 && nota[1]>=7 && nota[3]>=7 && (nota[4]>=7 || nota[2]>=7)) {
      console.log("Aprovação tipo B");
    }else if (nota[0]>=7 && nota[1]>=7 && (nota[3]>=7 || nota[2]>=7)) {
      console.log("Aprovação tipo C");
    }else{
      console.log("Reprovado");
    }

    
    // console.log(`Idade: ${matrizIdade[i]}, Cidade: ${matrizCidade[i]}, Opinião: ${matrizOp[i]}`);

}

lerMatriz();