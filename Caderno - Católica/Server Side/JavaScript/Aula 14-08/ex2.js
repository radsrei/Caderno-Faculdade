//escreva um programa que gera números entre 1 e 999 e mostra aqueles que divididos por 11 resultam em resto 5
let x = 0;
for (let i = 0; i < 1000; i++) {
    x = i%11
    if(x === 5){
        console.log(i);
    }
}

let j = 0;
while (j < 1000){
    x = j%11
    if(x === 5){
        console.log(j);
    }
    j++
}