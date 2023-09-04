Const mysql = require('mysql2'); 


Const conecta = mysql.createConnection ({ 
    Host: 'localhost', // endereço do banco 
    User: 'root' //usuário padrão 
    Database: 'test' //nome do banco 
}); 
Module.exports = {conecta} 