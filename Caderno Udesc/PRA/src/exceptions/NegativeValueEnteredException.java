
package exceptions;

/**
 * Lançada quando o valor é negativo
 * @author udesc
 *
 */
public class NegativeValueEnteredException extends Exception {
	private static final String NEGATIVE_EXCEPTION = "Zero não possui fatorial";
	
	/**
	 * Construtor da classe com a mensagem padrão
	 */
	public NegativeValueEnteredException() {
		super(NEGATIVE_EXCEPTION);
	}

}


