/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package superfatorial;

import exceptions.InputException;
import java.io.IOException;
import java.math.BigInteger;
import java.util.HashMap;

/**
 *
 * @author nilton
 */
public class SuperFatorialComCache{

    private HashMap<String, BigInteger> cache = new HashMap();
    
    public void addCache(String in, BigInteger bi) throws IOException {
        if (!cache.containsKey(in)) {
            cache.put(in, bi);
        }
    }
    
    public HashMap<String,BigInteger> getCache(){
        return cache;
    }
    
    public BigInteger getFatoria(BigInteger numero) throws InputException, IOException {

        BigInteger bg = new BigInteger(numero.toString());
        BigInteger resultado = BigInteger.ONE;
        
        while (bg.compareTo(BigInteger.ZERO) != 0) {
            if (cache.containsKey(bg.toString())) {
                System.out.println("Em cache: "+ bg.toString());
                resultado = cache.get(bg.toString());
                break;
            } else {
                bg = bg.subtract(BigInteger.ONE);
            }
        }

        if(bg.compareTo(numero)==0)
            return cache.get(bg.toString());

        while (numero.compareTo(bg) != 0) {
            
            bg = bg.add(BigInteger.ONE);
            resultado = resultado.multiply(SuperFatorial.fat(bg));
            addCache(bg.toString(), resultado);
        }

        return resultado;
    }
    
}
