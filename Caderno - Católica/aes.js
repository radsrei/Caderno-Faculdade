const crypto = require('crypto');

//Gerar Chaves AES-256-CBC
const key = crypto.randomBytes(32);
const iv = crypto.randomBytes(16);

const algoritmo = 'aes-256-cbc';
const textoOriginal = 'Texto secreto com cripto simétrica...';

function criptografar(texto){
    try{
        const cipher = crypto.createCipheriv(algoritmo, key, iv);
        let criptografado = cipher.update(texto,'utf8','hex');
        criptografado += cipher.final('hex');
        return criptografado;
    }catch (erro){
        console.erro('Erro durante a criptografia: ', erro.message);
        return null;
    }
}

function descriptografar(textoCriptografado){
    try{
        const decipher = crypto.createDecipheriv(algoritmo,key,iv);
        let texto = decipher.update(textoCriptografado,'hex','utf8');
        texto += decipher.final('utf8');
        return texto;
    }catch (erro){
        console.erro('Erro durante a descriptografia: ', erro.message);
        return null;
    }
}

//Texto Plano
const textoCriptografado = criptografar(textoOriginal);

//texto Criptografado

const textoDescriptografado = descriptografar(textoCriptografado);

console.log('texto origial: ', textoOriginal);
console.log('texto criptografado: ',textoCriptografado);
console.log('texto descriptografado: ',textoDescriptografado);