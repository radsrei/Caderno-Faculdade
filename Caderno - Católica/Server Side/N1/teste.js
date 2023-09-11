const readline = require('readline');

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

// Usando o método question para obter entrada do usuário
rl.question('Digite algo: ', (resposta) => {
  console.log('Você digitou: ' + resposta);
  rl.close(); // Feche a interface de leitura após obter a resposta
});
