// EXPRESS API SETUP
import express from 'express'
const app = express()

const PORT = process.env.PORT || 8000

// conexão mysql
import { createConnection } from 'mysql2'

const connection = createConnection({
    host: 'localhost',
    user: 'root',
    database: 'hardware'
})

app.get('/teste', (req, res) => {
    res.send('Conexão')
})

// Listar componente (select)
app.get('/hardware', (req, res) => {

    let query = `SELECT * FROM componente;`

    connection.query(query, (falha, retorno, campos) =>
    {
        console.log(falha)
        console.log(retorno)
        console.log(campos)

        if(falha == null){
            res.json(retorno)
        }else{
            res.send('FAIL')
        }
    })
})

// Criar componente (create)
app.get('/insert/:nome/:desc', (req, res) => {

    let query = `INSERT INTO componente (nome_comp,desc_comp) VALUES("${req.params.nome}", "${req.params.desc}");`

    connection.query(query, (falha, retorno, campos) =>{
        console.log(falha)
        console.log(retorno)
        console.log(campos)

        if(falha == null){
            res.json(retorno)
        }else{
            res.send('FAIL')
        }
    })
})

// update entrada
app.get('/update/:cod/:nome/:desc', (req, res) => {

    let query = `UPDATE componente SET nome_comp = "${req.params.nome}", desc_comp = "${req.params.desc}" WHERE cod_comp = ${req.params.cod};`

    connection.query(query, (falha, retorno, campos) => {
        console.log(falha)
        console.log(retorno)
        console.log(campos)

        if(falha == null){
            res.json(retorno)
        }else{
            res.send('FAIL')
        }
    })
})

// delete de linha
app.get('/delete/:cod', (req, res) => {

    let query = `DELETE FROM componente WHERE cod_comp = ${req.params.cod};`

    connection.query(query, (falha, retorno, campos) => {
        console.log(falha)
        console.log(retorno)
        console.log(campos)

        if(falha == null){
            res.json(retorno)
        }else{
            res.send('FAIL')
        }
    })
})

// pesquisa por nome
app.get('/find/:nome', (req, res) => {

    let query = `SELECT * FROM componente WHERE nome_comp = "${req.params.nome}";`

    connection.query(query, (falha, retorno, campos) => {
        console.log(falha)
        console.log(retorno)
        console.log(campos)

        if(falha == null){
            res.json(retorno)
        }else{
            res.send('FAIL')
        }
    })
})


app.listen(PORT, () => {
    console.log(`Na porta ${PORT}`)
})