package superfatorial;

import java.math.BigInteger;

import exceptions.InputException;

public interface ISuperFatorial {

	/**
	 * Assinatura para o SuperFatorial
	 * @author udesc
	 *
	 */

	    
	    /**
	     * Recebe o fatorial do número e retorna o superfatorial dele
	     * @param numero para o qual calcularemos o superfatorial
	     * @return super fatorial
	     * @throws InputException indicando que o valor digitado é inválido
	     */
	    public BigInteger getSuperFatorial(BigInteger numero) throws InputException;
            //private BigInteger fat(BigInteger bg);
}
