import entrdados from 'readline-sync' 

let chocolateDistr = () => {
    try {
        let qteChocolate = entrdados.questionInt("informe a quantidade de chocolate:")
        let numColegas = entrdados.questionInt("numero Colegas: ")
        if (qteChocolate < numColegas)
            throw new Error ("Quantidade de chocolate inferior para distribuição")
        if ((qteChocolate % numColegas) == 0) {
            console.log("distribuição homogênea!")
        } else {
            let falta =  numColegas - (qteChocolate % numColegas) 
            console.log(`Você precisa comprar ${falta} chocolate(s)`)
            console.log(`Cada colega Receberá ${(falta + qteChocolate)/numColegas}`) 
        }
    } catch (e) {
        console.log(e.message)
    }
}
chocolateDistr()

