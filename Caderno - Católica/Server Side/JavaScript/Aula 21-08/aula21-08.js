//declaração de função
function quadrado (numero){
    return numero * numero
}
console.log(quadrado(2))

//função "anônima"
let quadrado = function (numero){
    return numero * numero;
}
let res = quadrado(3)
console.log(res)

//Chamada de função
let fatorial = function fac(n){
    return n < 2 ? 1 : n * fac(n-1)
}
console.log(fatorial(4));

//Chamada de função por parametro de chamada
function map(f,a){
    let result =[];
    let = i
    for (let i = 0; i != a.length; i++) {
        result[i] = f(a[i]);      
    }
    return result;
}
console.log(map(function (x) {return x*x}, [0,1,2,5,10]))

//Função Recursiva
function fatorial(n){
    if ((n == 0) || (n == 1)){
        return 1;
    }else{
        return (n * fatorial(n-1));
    }
}

//Variáveis globais e variáveis internas