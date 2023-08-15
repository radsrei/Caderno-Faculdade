//faça um programa em que lê array contendo 10 números inteiros positovos.
// Para cada número lido do array o programa precisa apontar se o número lido é primo ou não
let lista = [1,2,3,4,5,6,7,8,9,10] 
let div = 0;
let rest = 0;
let tam = lista.length
for (let index = 0; index < tam; index++) {
    let element = lista[index];//setar o valor de teste do array
    for (let j = 0; j <= element; j++) {
        rest = element / j
        if(element%j == 0){//faz divisão pela lista de valores
            div++
        }
    }
    if(div==2 || element == 1){
        console.log(element + ' primo')
    }else{
        console.log(element + ' não é primo')
    }
    div = 0
}
