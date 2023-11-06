import entrdados from 'readline-sync' 
import connect from './bd.js'

const PARAMETRO_CONVERSOR = 1000

let result = 0
let consumoAgua = 0
let vlrConsumo = 0.00
let litros = entrdados.questionFloat("Informe o consumo em litros de agua ")
let respRelogio = entrdados.question("Informe o nome do responsavel pelo Relogio ")
let numRelogio = entrdados.questionInt("Informe o numero do relogio ")
let anoConsumo = entrdados.questionInt("Informe o ano de consumo " )
let mesConsumo = 0
while (mesConsumo < 1 || mesConsumo > 12) {
  try {
    mesConsumo = entrdados.questionInt("Informe o mes de Consumo ")
    if (mesConsumo < 1 || mesConsumo > 12)
      throw new Error ("Mês Inválido!")
  } catch (e) {
    console.log(e.message)
  }
}

let convLitrosMetros3 = (consLitro) => {
  return consumoAgua = consLitro / PARAMETRO_CONVERSOR
}

let calcConsumo = () => {
  if (consumoAgua < 21 ) {
    vlrConsumo = consumoAgua * 1.6
  }
  else if (consumoAgua > 20 && consumoAgua < 51) {
    vlrConsumo = consumoAgua * 2.8
  } else {
    vlrConsumo = consumoAgua * 4.2
  }

  if (vlrConsumo < 100 ) 
    vlrConsumo = vlrConsumo - (vlrConsumo * 0.05)
  if (vlrConsumo > 200)
  vlrConsumo = vlrConsumo + (vlrConsumo * 0.10)
  return vlrConsumo
}

async function insereRelogio(numRelogio) {
  const con = await connect();
  const row = await con.query('SELECT * from relogio WHERE numero_relogio = ?', [numRelogio])
  const resp = row[0].length 
  if (resp <= 0) {
    console.log("relógio não cadastrado, cadastrando....")  
    const sql = 'INSERT INTO relogio(numero_relogio,nome_responsavel) VALUES (?,?);'
    const values = [numRelogio, respRelogio]
    return await con.query(sql, values)
  }  
}

async function insereConsumo() {
  const con = await connect();
  const sql = 'INSERT INTO consumo(ano_consumo,mes_consumo,numero_relogio,qtde_consumo,vlr_consumo) VALUES(?,?,?,?,?);'
  const valcons = [anoConsumo, mesConsumo, numRelogio, consumoAgua,vlrConsumo]
  return await con.query(sql, valcons)
}

convLitrosMetros3(litros)
calcConsumo(vlrConsumo)
insereRelogio(numRelogio)
insereConsumo()

console.log("Responsável pelo Relógio:",respRelogio)
console.log("Numero do Relógio", numRelogio)
console.log("Consumo de Água em ms3", consumoAgua, "Vlr do Consumo ",vlrConsumo )
console.log("Ano e mês do consumo", anoConsumo, mesConsumo)

console.log("Lançamento de consumo de água efetuado....!")


