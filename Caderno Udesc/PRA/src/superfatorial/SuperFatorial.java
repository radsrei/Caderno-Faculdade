package superfatorial;

import java.math.BigInteger;

import exceptions.InputException;
//import java.io.IOException;

//Logica super_fatorial
public class SuperFatorial implements ISuperFatorial {

        @Override
	public BigInteger getSuperFatorial(BigInteger bg) throws InputException {

		// Casos de erro
		if (bg.compareTo(BigInteger.ZERO) == 0)
			return BigInteger.ONE;
		else if (bg.compareTo(BigInteger.ZERO) < 0) {
			throw new InputException(null);
		}

		// calculando fatorial
		BigInteger resultado = BigInteger.ONE;

		while(bg.compareTo(BigInteger.ZERO) != 0) {
			resultado = resultado.multiply(fat(bg));
			bg = bg.subtract(BigInteger.ONE);
		}
                
		return resultado;
	}

            protected static BigInteger fat(BigInteger bg) {

		if (bg.compareTo(BigInteger.ONE)==0)
			return BigInteger.ONE;

		return bg.multiply(fat(bg.subtract(BigInteger.ONE)));

	}

}
