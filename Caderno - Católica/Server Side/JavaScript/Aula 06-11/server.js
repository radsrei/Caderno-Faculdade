import express from "express";
import cors from "cors";
import db from './config/database.js';

import Curso from './models/curso_model.js'
import Professor from "./models/professor_model.js";
import Turma from "./models/turma_model.js";

import professorRota from './routes/professor_routes.js'

const server = express()
server.use(express.json());
server.use(cors());

try {
    await db.authenticate()
    console.log("Conexão com o MySQL estabelecida")
} catch (error) {
    console.log("Conexão com o MySQL não estabeliecida")
}

Curso.associate = (models) => {
    Curso.hasMany(models.Professor, { foreignKey: 'matr_professor', as: 'professores'})

    Curso,hasMany(models.Turma, { foreignKey: 'id_turma', as: 'turmas'})
 
}

Curso.belongsTo(Turma, {foreignKey:'id_turma', allowNull:true})
Curso.belongsTo(Professor, {foreignKey:'matr_professor', allowNull:true})

server.listen(5000, () => console.log("Servidor em execução http://localhost:5000"))