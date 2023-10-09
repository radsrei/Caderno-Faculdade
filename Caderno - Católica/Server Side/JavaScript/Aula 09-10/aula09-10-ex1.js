const readline = require('readline');

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

function lerEntrada() {
    rl.question('Diga número de alunos: ', (alunosQtd) => {
        rl.question('Diga quantos chocolates: ', (chocolateQtd) => {
            const alunos = parseFloat(alunosQtd);
            const chocolate = parseFloat(chocolateQtd);
             try {
                if (alunos > chocolate ){
                    throw new Error ("Qtd de alunos maior que de chocolate ")
                }
                else if (chocolate%alunos != 0){
                    throw new Error ("Qtd de chocolate não atende a todos os alunos descarte " + (chocolate - alunos) + " chocolates")
                }else{
                    console.log("Qtd de chocolate por aluno: " + chocolate/alunos)
                }
             }catch (error){
                console.error("Error: " + error.message)
             }finally{
                console.log("Fim de programa")
             }
        rl.close();
        })
    });
}

lerEntrada();